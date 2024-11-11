#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int
main()
{
	pid_t	pid;
	int		status;

	if ((pid = fork()) < 0)  {
		perror("fork");
		exit(1);
	}
	else if (pid == 0)  {
		printf("I'm a child\n");
		sleep(2);
	}
	else  {
		wait(&status);
		printf("A child killed with %d status\n", status);
	}
}
// child process가 종료되면서 return 하는 값을 status에, 그걸 출력
