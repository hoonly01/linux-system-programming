#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define	MAX_CMD		256

void
DoCmd(char *cmd)
{
	printf("Doing %s", cmd);
	sleep(1);
	printf("Done\n");
}

int
main()
{
	char	cmd[MAX_CMD];
	int		pid;

	while (1)  {
		printf("CMD> ");
		fgets(cmd, MAX_CMD, stdin);	
		if (cmd[0] == 'q')
			break;

		if ((pid = fork()) < 0)  {
			perror("fork");
			exit(1);
		}
		else if (pid == 0)  {
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
// wait가 없으니 병렬 실행하고자 하는 의도대로 동작
// wait이 compile되면 fork하고 exit까지 parent가 기다림 -> 다음 입력 받는 동작 수행 안함
// CMD> 가 왜 안나오지 ........
