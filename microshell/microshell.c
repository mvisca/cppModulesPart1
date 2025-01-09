#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void fterr(char *s, char *a);
void ftexec(char *a[], int i, int tfd, char *e[]);

int main( int ac, char *av[], char *ev[])
{
	int i, fd[2], tfd;
	(void)ac;

	tfd = dup(STDIN_FILENO);
	i = 0;

	while (av[i] && av[i + 1])
	{
		av = av[i + 1];
		i = 0;

		while (av[i] != NULL && strcmp(av[i], ";") && strcmp(av[i], "|"))
		{
			i++;
		}
		if (strcmp(av[0], "cd") == 0)
		{
			if (i != 2)
			{
				fterr("ERR CD", NULL);
			}
			else
			{
				if (chdir(av[1]) != 0)
				{
			        fterr("error: cd...", av[1]);
                }
			}
		}
        else if (i != 2 && av[i] == NULL && strcmp(av[i], ";")
        {
            
        }
	}

}
