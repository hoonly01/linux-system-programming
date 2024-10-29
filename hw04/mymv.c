#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
	if (argc != 3)  {
		fprintf(stderr, "Usage: %s old new\n", argv[0]);
		exit(1);
	}

	if (rename(argv[1], argv[2]) < 0)  {
		perror("rename");
		exit(1);
	}
}
// argv[1]의 파일을 이동 혹은 이름 변경
// 디렉토리 같으면 이름 변경(삭제, 수정 X)
// 디렉토리 다르면 이, 해당 파일 이미 존재하면 덮어쓰기
