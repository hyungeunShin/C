//�ҽ�5.c
//����ü ������ ���ڷ� ����!!!!!!
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

void input_stu(struct student *pstu)
{
	int num;
	printf("�⼮(20�� ����) : ");
	scanf_s("%d", &num);
	(*pstu).attend = num;

	printf("�ʱ�(20�� ����) : ");
	scanf_s("%d", &((*pstu).exam1));  //<--- 

	printf("�Ǳ�(40�� ����) : ");
	scanf_s("%d", &(*pstu).exam2);

	printf("����(20�� ����) : ");
	scanf_s("%d", &(*pstu).report);
}

void cal_stu(struct student *pstu)
{
	(*pstu).total = (*pstu).attend + (*pstu).exam1 + (*pstu).exam2 + (*pstu).report;

	if ((*pstu).total >= 60)
		(*pstu).result = 'P';
	else
		(*pstu).result = 'F';
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
	struct student stu2 = { "�̱浿", "C���" };

	//����� �Է��� ���ؼ� ������ ����
	input_stu(&stu1);	
	input_stu(&stu2); 

	//���� ���� ( ��, P, F )
	cal_stu(&stu1);
	cal_stu(&stu2);

	printf("\n\n");
	print_stu(&stu1); //����ü�� �ּ� ������ Ȱ��!(�����޺��� �޸� ȿ����)
	printf("\n\n");
	print_stu(&stu2);
		
	return 0;
}
