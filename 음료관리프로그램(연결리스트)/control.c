//control.c
#include "std.h"

linkedlist g_list;

void con_init()
{
	list_init(&g_list);
	file_read(&g_list);
}

void con_exit()
{
	file_write(&g_list);
}

void con_printall()
{
	list_next_printall(&g_list);
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
	if (list_frontinsert(&g_list, dr) == 1)
		printf("����Ǿ����ϴ�\n");
	else
		printf("������ ������ �����մϴ�.\n");
}

void con_select()
{
	printf("[��ǰ ���� �˻�]\n\n");

	char name[20];
	wb_getstring("�˻��� �̸�", name, sizeof(name));

	node *cur = list_select1(&g_list, name);
	if (cur == NULL)
	{
		printf("�ش� �̸��� �������� �ʽ��ϴ�.\n");
		return;
	}

	drink_println(&cur->data);
}

void con_update()
{
	printf("[��ǰ ���� ����]\n\n");

	char name[20];
	wb_getstring("�˻��� �̸�(������ ���)", name, sizeof(name));

	node *cur = list_select1(&g_list, name);
	if (cur == NULL)
	{
		printf("�ش� �̸��� �������� �ʽ��ϴ�.\n");
		return;
	}

	int price;
	price = wb_getint("������ ����");	
	cur->data.price = price;

	printf("�����Ǿ����ϴ�\n");
}

void con_delete()
{
	printf("[��ǰ ���� ����]\n\n");

	char name[20];
	wb_getstring("������ �̸�", name, sizeof(name));

	node *cur = list_select1(&g_list, name);
	if (cur == NULL)
	{
		printf("�ش� �̸��� �������� �ʽ��ϴ�.\n");
		return;
	}
	
	list_nodedelete(&g_list, cur);

	printf("�����Ǿ����ϴ�\n");
}