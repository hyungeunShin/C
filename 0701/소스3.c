//소스3.c

#include <stdio.h>

//step3) 구조체를 배운 후 -> 구조체 정의!!!!
struct mydate   // --> int 
{
	int year;
	int month;
	int day;
};

void input_today(struct mydate *y)
{
	(*y).year = 2021;
	(*y).month = 7;
	(*y).day = 1;
}

void print_day(struct mydate d)
{
	printf("%04d-%02d-%02d\n", d.year, d.month, d.day);
}

void next_day(struct mydate *d)
{
	(*d).day = (*d).day + 1;
}

int main()
{
	struct mydate day1;

	//오늘날짜 저장 기능
	input_today(&day1);

	//출력기능
	print_day(day1);

	//날짜 연산 기능
	next_day(&day1);

	//출력 기능 
	print_day(day1);

	return 0;
}