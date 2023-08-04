//control.c
#include "std.h"

int g_flag[10], g_c[10], g_cpp[10], g_struct[10];	

void con_printall()
{
	printf("�ε���\tC���\tC++���\t�ڷᱸ��\t�հ�\t���\n");
	printf("--------------------------------------------------------\n");
	for (int i = 0; i < 10; i++)
	{		
		printf("[%02d]\t%d\t%d\t%d\t\t%d\t%.1f\n", 
			i, g_c[i], g_cpp[i], g_struct[i],				 //�ε���, ���� ����
			g_c[i] + g_cpp[i] + g_struct[i],				 //��
			(g_c[i] + g_cpp[i] + g_struct[i]) / 3.0f);		 //��� (���� / �Ǽ�)
	}
}

void con_insert()
{
	int idx, c, cpp, st;

	printf("�ε���(0~9) : ");			scanf_s("%d", &idx);
	printf("C���     ���� : ");		scanf_s("%d", &c);
	printf("C++���   ���� : ");		scanf_s("%d", &cpp);
	printf("�ڷᱸ��  ���� : ");		scanf_s("%d", &st);
	//-------------------------------------------------
	
	if (idx < 0 || idx >9)
	{
		printf("�߸��� �ε��� �Դϴ�.\n");
	}
	else if (g_flag[idx] != 0)
	{
		printf("���� �����մϴ�.\n");
	}
	else
	{
		g_flag[idx] = 1;	//<---------------------------------
		g_c[idx] = c;
		g_cpp[idx] = cpp;
		g_struct[idx] = st;
		printf("����Ǿ����ϴ�.\n");
	}
}

void con_update()
{
	int idx, c, cpp, st;

	printf("�ε���(0~9) : ");				scanf_s("%d", &idx);
	printf("C���     ���� ���� : ");		scanf_s("%d", &c);
	printf("C++���   ���� ���� : ");		scanf_s("%d", &cpp);
	printf("�ڷᱸ��  ���� ���� : ");		scanf_s("%d", &st);
	//-------------------------------------------------

	if (idx < 0 || idx >9)
	{
		printf("�߸��� �ε��� �Դϴ�.\n");
	}
	else if (g_flag[idx] == 0)
	{
		printf("���� �������� �ʽ��ϴ�.\n");
	}
	else
	{
		g_c[idx]		= c;
		g_cpp[idx]		= cpp;
		g_struct[idx]	= st;
		printf("�����Ǿ����ϴ�.\n");
	}
}

void con_select()
{
	int idx;

	printf("�ε���(0~9) : ");
	scanf_s("%d", &idx);

	if (idx < 0 || idx >9)
	{
		printf("�߸��� �ε��� �Դϴ�.\n");
	}
	else if (g_flag[idx] == 0)
	{
		printf("���� �������� �ʽ��ϴ�.\n");
	}
	else
	{
		printf("C���     ���� : %d��\n", g_c[idx]);
		printf("C++���   ���� : %d��\n", g_cpp[idx]);
		printf("�ڷᱸ��  ���� : %d��\n", g_struct[idx]);
		printf("��             : %d��\n", g_c[idx] + g_cpp[idx] + g_struct[idx]);
		printf("���           : %.1f��\n", (g_c[idx] + g_cpp[idx] + g_struct[idx])/3.0f);
	}
}

void con_delete()
{
	int idx;

	printf("������ �ε���(0~9) : ");
	scanf_s("%d", &idx);

	if (idx < 0 || idx >9)
	{
		printf("�߸��� �ε��� �Դϴ�.\n");
	}
	else if (g_flag[idx] == 0)
	{
		printf("���� �������� �ʽ��ϴ�.\n");
	}
	else
	{
		g_flag[idx]		= 0;
		g_c[idx]		= 0;
		g_cpp[idx]		= 0;
		g_struct[idx]	= 0;
		printf("�����Ǿ����ϴ�.\n");
	}
}