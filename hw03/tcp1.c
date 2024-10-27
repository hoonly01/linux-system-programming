#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
	FILE	*src, *dst;
	int		ch;

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

	while((ch = fgetc(src) != -1))  {
		fputc(ch, dst);
	}

	fclose(src);
	fclose(dst);
}
// fgetc는 한 글자씩 읽음
// 한 글자씩 copy, EOF을 만나면 종료
// EOF는 fgetc의 return value, -1
// 문자열의 마지막은 '\0'임. 파일은 마지막에 널 캐릭터 X
