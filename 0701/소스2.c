//소스2.c

#include <stdio.h>

//step2) 함수를 배운 후 
void input_today(int *y, int*m, int *d)
{
	*y = 2021;
	*m = 7;
	*d = 1;
}

void print_day(int y, int m, int d)
{
	printf("%04d-%02d-%02d\n", y, m, d);
}

void next_day(int *y, int *m, int *d)
{
	*d = *d + 1;
}

int main()
{
	int year;
	int month;
	int day;

	//오늘날짜 저장 기능
	input_today(&year, &month, &day);

	//출력기능
	print_day(year, month, day);

	//날짜 연산 기능
	next_day(&year, &month, &day);

	//출력 기능 
	print_day(year, month, day);

	return 0;
}