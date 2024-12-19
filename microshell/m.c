#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

void ferr(char *s, char *a)
{
	while (*s)
		write (2, s++, 1);
	if (a)
		while (*a)
			write (2, a++, 1);
	write (2, "\n", 1);
}

void fexe(char *a[], int i, int tfd, char *e[])
{
	a[i] = NULL;
	dup2(tfd, STDIN_FILENO);
	close (tfd);
	execve(a[0], a, e);
	ferr("error: cannot execute ", a[0]);
	exit (0);
}

int main(int c, char *a[], char *e[])
{
	int i;
	int tfd;
	int fd[2];
	
	i = 0;
	tfd = dup(STDIN_FILENO);
	
	while (a[i] && a[i + 1])
	{
		a = &a[i + 1];
		i = 0;

		while (a[i] && strcmp(a[i], ";") && strcmp(a[i], "|"))
			i++;

		if (strcmp(a[0], "cd") == 0)
		{
			if (i != 2)
				ferr("error: cd: bad arguments", NULL);
			else if (chdir(a[1]) != 0)
				ferr("error: cd: cannot change directory to ", a[1]);
		}

		else if (i != 0 && (a[i] == NULL || strcmp(a[i], ";") == 0))
		{
			if (fork() == 0)
			{
				fexe(a, i, tfd, e);
			}
			else
			{
				close(tfd);
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
				tfd = dup(STDIN_FILENO);
			}
		}

		else if (i != 0 && strcmp(a[i], "|") == 0)
		{
			pipe(fd);
			if (fork () == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				fexe(a, i, tfd, e);
			}
			else
			{
				close (fd[1]);
				close (tfd);
				tfd = fd[0];
			}
		}
	}
	close (tfd);
	return (0);
}
