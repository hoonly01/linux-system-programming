#include <stdio.h>

main(int argc, char *argv[])
{
	FILE	*src;
	int 	ch;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s source\n", argv[0]);
		exit(1);
	}
	// source 파일 1개만 필요, argv 2개. 아니라면 exit
	
	if ((src = fopen(argv[1], "rt")) == NULL) {
		perror("fopen");
		exit(1);
	}
	
	while((ch = fgetc(src)) != -1) {
		if((ch >= 'a') && (ch <= 'z')) {
			fputc(ch-32, stdout);
		}
		else {
			fputc(ch, stdout);
		}
	}
	// 한글자씩 읽으면서, 알파벳 소문자 (ASCII 97~122)이면 대문자로 출력
	// 숫자 범위에서 'a', 'z'로 가독성을 위해 수정
	// 아니라면 그대로 출력

	fclose(src);
}
// 사용 예시
// ./upper upper.c
// upper.c (본 파일)의 내용을 대문자로 콘솔에 출력함
