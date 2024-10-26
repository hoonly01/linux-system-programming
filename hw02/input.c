#include <stdio.h>

int main()
{
	char c, s[80];
	int i; long l;
	float f; double d;
	
	scanf("%c %s %d %ld %f %lf", &c, s, &i, &l, &f, &d); 
	printf("Output: %c %s %d %ld %.4f %.2lf\n", c, s, i, l, f, d); 

	c = getchar();
	putchar(c);

	gets(s);
	puts(s);
}
// %c: single character
// %s: sequence of character
// %d: decimal
// %ld: long decimal
// %f: floating-point number, .4f는 소숫점 4자리고정
// %lf: double형 입출력
