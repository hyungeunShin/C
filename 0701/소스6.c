//�ҽ�6.c

//����ü �ɹ��� ���ڷ� ����!!!!!!
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

void input_stu(int* a, int *e1, int *e2, int* r)
{
	int num;
	printf("�⼮(20�� ����) : ");
	scanf_s("%d", &num);
	*a = num;

	printf("�ʱ�(20�� ����) : ");
	scanf_s("%d", e1);  //<--- 

	printf("�Ǳ�(40�� ����) : ");
	scanf_s("%d", e2);

	printf("����(20�� ����) : ");
	scanf_s("%d", r);
}

void cal_stu(int a, int e1, int e2, int r, int*total, char *result)
{
	*total = a + e1 + e2 + r;

	if ( *total >= 60)
		*result = 'P';
	else
		*result = 'F';
}

void print_stu(const struct student *pstu)
{
	printf("�л� ���� ���\n");
	printf("�̸� : %s\n", (*pstu).name);
	printf("����� : %s\n", (*pstu).subject);
	printf("�⼮���� : %d��\n", (*pstu).attend);
	printf("�ʱ����� : %d��\n", (*pstu).exam1);
	printf("�Ǳ����� : %d��\n", (*pstu).exam2);
	printf("�������� : %d��\n", (*pstu).report);
	printf("�հ� : %d��\n", (*pstu).total);
	printf("��� : %c\n", (*pstu).result);
}

int main()
{
	struct student stu1 = { "ȫ�浿", "C���" };

	//����� �Է��� ���ؼ� ������ ����
	input_stu(&stu1.attend, &stu1.exam1, &stu1.exam2, &stu1.report);

	//���� ���� ( ��, P, F )
	cal_stu(stu1.attend, stu1.exam1,stu1.exam2, stu1.report, &stu1.total, &stu1.result);

	print_stu(&stu1); //����ü�� �ּ� ������ Ȱ��!(�����޺��� �޸� ȿ����)

	return 0;
}
