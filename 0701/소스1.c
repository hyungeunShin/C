//�ҽ�1.c

/*
��¥�� �����ϴ� ���α׷�
- ���ó�¥ ���� ���
- ������ �������ڷ� ���� ��� 
*/
#include <stdio.h>

//step1) �Լ� �� 
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