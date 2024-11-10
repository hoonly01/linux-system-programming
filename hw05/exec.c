#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int
main()
{
	pid_t	pid;
	char	*argv[] = { "mycp", "exec.c", "exec2.c", NULL };
	char 	*path = "/home/lsp67/lab/hw03/mycp";

	// execl
	if ((pid = fork()) < 0)  {
		perror("fork");
		exit(1);
	}
	else if (pid == 0)  {
		// mycp exec.c exec2.c
		if (execl(path, "mycp", "exec.c", "exec2.c", NULL) == -1)  {
			perror("execl");
			exit(1);
		}
	}
	if (waitpid(pid, NULL, 0) < 0)  {
		perror("waitpid");
		exit(1);
	}

	// execv
	if ((pid = fork()) < 0)  {
		perror("fork");
		exit(1);
	}
	else if (pid == 0)  {
		// mycp exec.c exec2.c
		if (execv(path, argv) == -1)  {
			perror("execv");
			exit(1);
		}
	}
	if (waitpid(pid, NULL, 0) < 0)  {
		perror("waitpid");
		exit(1);
	}

	// execlp
	if ((pid = fork()) < 0)  {
		perror("fork");
		exit(1);
	}
	else if (pid == 0)  {
		// execute 'env' from PATH
		if (execlp("env", "env", NULL) == -1)  {
			perror("execlp");
			exit(1);
		}
	}
	if (waitpid(pid, NULL, 0) < 0)  {
		perror("waitpid");
		exit(1);
	}
}
