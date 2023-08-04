//소스1.c

/*
날짜를 관리하는 프로그램
- 오늘날짜 저장 출력
- 오늘의 다음날자로 변경 출력 
*/
#include <stdio.h>

//step1) 함수 전 
int main()
{
	int year;
	int month;
	int day;

	year = 2021;
	month = 7;
	day = 1;

	printf("%04d-%02d-%02d\n", year, month, day);

	day = day + 1; 

	printf("%04d-%02d-%02d\n", year, month, day);


	return 0;
}