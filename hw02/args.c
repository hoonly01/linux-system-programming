#include <stdio.h>

int main(int argc, char *argv[])
{
	int		i;

	for (i = 0 ; i < argc ; i++)
		printf("argv[%d]=%s\n", i, argv[i]);

}
// argc는 입력받은 argv+1개. 0번은 본인

