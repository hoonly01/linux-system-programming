#include <stdio.h>
#include <stdlib.h>

#define	MAX_BUF	256

int
main(int argc, char *argv[])
{
	FILE	*src, *dst;
	char	buf[MAX_BUF];

	if (argc != 3)  {
		fprintf(stderr, "Usage: %s source destination\n", argv[0]);
		exit(1);
	}

	if ((src = fopen(argv[1], "rt")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	if ((dst = fopen(argv[2], "wt")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	while (fgets(buf, MAX_BUF, src) != NULL)  {
		fputs(buf, dst);
	}

	fclose(src);
	fclose(dst);
}
// 한 글자씩이 아니라 버퍼의 수(지금은 256)만큼 읽고, 쓰고
