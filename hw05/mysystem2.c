#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
mysystem(char *cmd) {
}

int
main()
{
	char	cmd[MAX_CMD];
	int		pid;

	while (1)  {
		fgets(cmd, MAX_CMD, stdin);	
		if (cmd[0] == 'q')
			break;

		if ((pid = fork()) < 0)  {		// error
			perror("fork");
			exit(1);
		}
		else if (pid == 0)  {			// child
			DoCmd(cmd);
			exit(0);
		}
#if 0
		else  {
			wait(NULL);
		}
#endif
	}




}
