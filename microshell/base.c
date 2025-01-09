#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

void ferr(char *s[], char *a[])
{
	while (*s)
		write (2, s++, 1);
	if (a)
		while (*a)
			write (2, a++, 1);
	write (2, a, 1);
}

void fexe(char *a[], int i, in tfd, char *e[])
{
	a[i] = NULL;
	dup2(tfd, STDIN_FILENO);
	close (tfd);
	execve(a[0], a, e);
	ferr("error: cannot execute ", a[0]);
	exit (0);
}


