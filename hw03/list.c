#include <stdio.h>
#include <stdlib.h>

#define	MAX_BUF	256

int
main(int argc, char *argv[])
{
	FILE	*fp;
	char	buf[MAX_BUF];
	int		line;

	if (argc != 2)  {
		printf("Usage: %s filename\n", argv[0]);
		exit(1);
	}

	if ((fp = fopen(argv[1], "rt")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	line = 1;
	while (fgets(buf, MAX_BUF, fp) != NULL)  {
		printf("%4d: %s", line++, buf);
	}

	fclose(fp);
}
// 파일을 argument로 받아서, 해당 파일의 각 줄에 번호를 붙여  출력해주는 프로그램
// fgets는 c library
