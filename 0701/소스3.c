//�ҽ�3.c

#include <stdio.h>

//step3) ����ü�� ��� �� -> ����ü ����!!!!
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

	//���ó�¥ ���� ���
	input_today(&day1);

	//��±��
	print_day(day1);

	//��¥ ���� ���
	next_day(&day1);

	//��� ��� 
	print_day(day1);

	return 0;
}