//�ҽ�4.c
/*
�л��� C��� ���� ���� ���� ���α׷�
�л�[�̸�, �����, �⼮����, �ʱ�����, �Ǳ�����, ��������, �ջ�����, 'P' or 'F']
*/
#include <stdio.h>

struct student
{
	char name[20];
	char subject[20];
	int attend;
	int exam1;
	int exam2;
	int report;
	int total;
	char result;
};

int main()
{
	struct student stu1 = { "ȫ�浿", "C���"  };

	//����� �Է��� ���ؼ� ������ ����
	int num;
	printf("�⼮(20�� ����) : ");
	scanf_s("%d", &num); 
	stu1.attend = num; 

	printf("�ʱ�(20�� ����) : ");
	scanf_s("%d", &stu1.exam1);  //<--- 

	printf("�Ǳ�(40�� ����) : ");
	scanf_s("%d", &stu1.exam2);

	printf("����(20�� ����) : ");
	scanf_s("%d", &stu1.report);

	//���� ���� ( ��, P, F )
	stu1.total = stu1.attend + stu1.exam1 + stu1.exam2 + stu1.report;

	if ( stu1.total >= 60)
		stu1.result = 'P';
	else
		stu1.result = 'F';

	printf("�л� ���� ���\n");
	printf("�̸� : %s\n", stu1.name);
	printf("����� : %s\n", stu1.subject);
	printf("�⼮���� : %d��\n", stu1.attend);
	printf("�ʱ����� : %d��\n", stu1.exam1);
	printf("�Ǳ����� : %d��\n", stu1.exam2);
	printf("�������� : %d��\n", stu1.report);
	printf("�հ� : %d��\n", stu1.total);
	printf("��� : %c\n", stu1.result);

	return 0;
}
