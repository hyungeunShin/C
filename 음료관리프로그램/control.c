//control.c
#include "std.h"

wbarr  g_arr; 

void con_init()
{
	arr_init(&g_arr, 10);
	file_read(&g_arr);
}

void con_exit()
{
	file_write(&g_arr);
	arr_exit(&g_arr);
}

void con_printall()
{
	for (int i = 0; i < g_arr.size; i++)
	{
		drink dr = g_arr.base[i];
		printf("%d : ", i);
		drink_print(&dr);
	}
}

void con_insert()
{
	printf("[��ǰ ���� ����]\n\n");
	//���� ����
	char name[20];
	int  price;

	//�ʱ�ȭ	
	wb_getstring("�̸�", name, sizeof(name));
	price = wb_getint("����");
	
	//���� ������ ����
	drink dr = drink_createdrink(name, price);

	//����
	if (arr_insert(&g_arr, dr) == 1)
		printf("����Ǿ����ϴ�\n");
	else
		printf("������ ������ �����մϴ�.\n");
}

int nametoidx(const char* name)
{
	for (int i = 0; i < g_arr.size; i++)
	{
		drink mem = g_arr.base[i];
		if (strcmp(mem.name, name) == 0)
		{			
			return i;
		}
	}
	return -1;
}

void con_select()
{
	printf("[��ǰ ���� �˻�]\n\n");

	char name[20];
	wb_getstring("�˻��� �̸�", name, sizeof(name));

	int idx = nametoidx(name);
	if (idx == -1)
	{
		printf("�ش� �̸��� �������� �ʽ��ϴ�.\n");
		return;
	}

	//drink_println(&g_arr.base[idx]);
	drink_println(g_arr.base + idx);
}

void con_update()
{
	printf("[��ǰ ���� ����]\n\n");

	char name[20];
	wb_getstring("�˻��� �̸�(������ ���)", name, sizeof(name));

	int idx = nametoidx(name);
	if (idx == -1)
	{
		printf("�ش� �̸��� �������� �ʽ��ϴ�.\n");
		return;
	}

	//�����۾�
	//g_arr.base[idx].price = wb_getint("������ ����");

	int price;
	price = wb_getint("������ ����");	
	g_arr.base[idx].price = price;

	printf("�����Ǿ����ϴ�\n");
}

void con_delete()
{
	printf("[��ǰ ���� ����]\n\n");

	char name[20];
	wb_getstring("������ �̸�", name, sizeof(name));

	int idx = nametoidx(name);
	if (idx == -1)
	{
		printf("�ش� �̸��� �������� �ʽ��ϴ�.\n");
		return;
	}

	arr_delete(&g_arr, idx);

	printf("�����Ǿ����ϴ�\n");
}