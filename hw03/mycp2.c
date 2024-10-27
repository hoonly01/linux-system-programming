#include <stdio.h>
#include <stdlib.h>

#define	MAX_BUF	1024

int
main(int argc, char *argv[])
{
	FILE	*src, *dst;
	char	buf[MAX_BUF];
	int		count;

	if (argc != 3)  {
		fprintf(stderr, "Usage: %s source destination\n", argv[0]);
		exit(1);
	}

	if ((src = fopen(argv[1], "rb")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	if ((dst = fopen(argv[2], "wb")) == NULL)  {
		perror("fopen");
		exit(1);
	}

	while ((count = fread(buf, 1, MAX_BUF, src)) > 0)  {
		fwrite(buf, 1, count, dst);
	}

	fclose(src);
	fclose(dst);
}
// fread 함수를 통해 파일 복사 구현
// fread(buf, 1, MAX_BUF, src) -> 1바이트씩 최대 1024까지. 중간에 끝나도 읽은 개수만큼 return (e.g. 500 > 0)
// fread(buf, MAX_BUF, 1, src) -> 1024바이트를 1번, 중간에 끝나면 0 return (1024개 만큼 채우지 못했기 때문에)
