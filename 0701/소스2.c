//�ҽ�2.c

#include <stdio.h>

//step2) �Լ��� ��� �� 
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

	//���ó�¥ ���� ���
	input_today(&year, &month, &day);

	//��±��
	print_day(year, month, day);

	//��¥ ���� ���
	next_day(&year, &month, &day);

	//��� ��� 
	print_day(year, month, day);

	return 0;
}