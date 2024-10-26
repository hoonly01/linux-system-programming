#include <stdio.h>
#include <string.h>  // 문자열 복사를 위한 헤더

int main()
{
    char str1[20], str2[20];
    int value;

    // 문자열 복사
    strcpy(str1, "ABC");
    strcpy(str2, "abc");

    // 포인터 차이를 출력할 때 %td (포인터 차이 포맷) 사용
    printf("%td\n", !(str1 - str2) );  // 두 포인터의 차이

    return 0;
}
