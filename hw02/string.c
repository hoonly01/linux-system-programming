#include <stdio.h>

int
strlen_p(char *str)
{
	int	len = 0;

	while (*str++ )  {
		len++;
	}
	return len;
}
// null character 일때 ASCII 값 0. 즉 마지막에 도달하면 널 문자를 받아 while 종료 후 return

int
strlen_a(char str[])
{
	int i;

	for (i = 0 ; str[i] != '\0' ; i++)
		;
	return i;
}
// index를 이용, 널 문자를 만나기 전까지 계속 반복

void
strcpy_p(char *dst, char *src)
{
	while (*src)  {
		*dst++ = *src++;
	}
	*dst = *src;
}
// src의 null character(마지막) 전까지 while 돌면서 복사
// 그대로 끝내면 dst에 null character가 복사되기 전이므로 마지막 한 번더 copy 해주고 종료

void
strcpy_a(char dst[], char src[])
{
	int i;

	for (i = 0 ; src[i] != '\0' ; i++)
		dst[i] = src[i];
	dst[i] = src[i];
}
// strcpy_a와 같음. index 사용

void
strcat_p(char *dst, char *src)
{
	while (*dst++)
		;
	*dst--;
	while (*src)  {
		*dst++ = *src++;
	}
	*dst = *src;
}
// while (*dst++)가 종료되면  dst 포인터는  널 캐릭터의 한칸 뒤를 가리키고 있다.
// 널 캐릭터 위치로 다시 돌려놓고, 그 자리부터 src를 붙임

void
strcat_a(char dst[], char src[])
{
	int i, j;

	for (i = 0 ; dst[i] != '\0' ; i++)
		;
	for (j = 0 ; src[j] != '\0' ; j++)
		dst[i+j] = src[j];
	dst[i+j] = src[j];
}
// dst의 마지막에 널 캐릭터를 넣기 위함

int
strcmp_p(char *dst, char *src)
{
	while(*dst && (*dst == *src))
	{
		dst++;
		src++;
	}
	return (*dst - *src);

}
// 널 캐릭터가 아니면서 dst와 src의 문자가 같으면 계속 검사
// 널 캐릭터가 아님을 검사해야 함. 두 문자열이 완전히 같은 경우,
// while문을 빠져나가지 못하는 무한 loop에 빠질 수 있다.
// 둘 중 하나라도 조건이 깨지면 값을 비교해서 return
// strcmp 함수는 스트링을 비교하는 함수, 리턴 값은 아스키코를 기준으로 한 차이 값

int
strcmp_a(char dst[], char src[])
{
	int i;
	i = 0;
	while(dst[i] && (dst[i] == src[i]))
	{
		i++;
	}
	return (dst[i] - src[i]);
}
// 포인터 접근에서  arr index 접근으로 변경
// 동작 방식은 strcmp_p와 동일

int main()
{
	int		len1, len2;
	int		result1, result2;
	char	str1[20], str2[20];

	len1 = strlen_p("Hello");
	len2 = strlen_a("Hello");
	printf("strlen: p=%d, a=%d\n", len1, len2);

	strcpy_p(str1, "Hello");
	strcpy_a(str2, "Hello");
	printf("strcpy: p=%s, a=%s\n", str1, str2);

	strcat_p(str1, ", World!");
	strcat_a(str2, ", World!");
	printf("strcat: p=%s, a=%s\n", str1, str2);

	result1 = strcmp_p("ABCD", "ABCd");
	result2 = strcmp_a("ABCD", "ABC");
	printf("strcmp_p: %d\n", result1);
	printf("strcmp_a: %d\n", result2);
}
// 숙제2
// strcmp_p 함수로 "ABCD"와 "ABCd"를 비교, 즉 비교하는  문자가 다른 경우	: expected output: -32 // ('D'=68, 'd'=100)
// strcmp_a 함수로 "ABCD"와 "ABC"를 비교, 즉 길이가 달라 비교가 끝나는 경우	: expected output: 68  // ('D'의 아스키 값)
