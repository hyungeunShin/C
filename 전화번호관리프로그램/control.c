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
		member member = g_arr.base[i];
		printf("%d : ", i);
		member_print(&member);
	}
}

void con_insert()
{
	printf("[ȸ�� ���� ����]\n\n");
	//���� ����
	char name[20], phone[20];

	//�ʱ�ȭ	
	wb_getstring("�̸�", name, sizeof(name));
	wb_getstring("��ȭ��ȣ", phone, sizeof(phone));

	//���� ������ ����
	member mem = member_createmember(name, phone);

	//����
	if (arr_insert(&g_arr, mem) == 1)
		printf("����Ǿ����ϴ�\n");
	else
		printf("������ ������ �����մϴ�.\n");
}

int nametoidx(const char* name)
{
	for (int i = 0; i < g_arr.size; i++)
	{
		member mem = g_arr.base[i];
		if (strcmp(mem.name, name) == 0)
		{			
			return i;
		}
	}
	return -1;
}

void con_select()
{
	printf("[ȸ�� ���� �˻�]\n\n");

	char name[20];
	wb_getstring("�˻��� �̸�", name, sizeof(name));

	int idx = nametoidx(name);
	if (idx == -1)
	{
		printf("�ش� �̸��� �������� �ʽ��ϴ�.\n");
		return;
	}

	//member_println(&g_arr.base[idx]);
	member_println(g_arr.base + idx);
}

void con_update()
{
	printf("[ȸ�� ���� ����]\n\n");

	char name[20];
	wb_getstring("�˻��� �̸�(������ ���)", name, sizeof(name));

	int idx = nametoidx(name);
	if (idx == -1)
	{
		printf("�ش� �̸��� �������� �ʽ��ϴ�.\n");
		return;
	}

	//�����۾�
//	wb_getstring("������ ��ȭ��ȣ", g_arr.base[idx].phone, sizeof(g_arr.base[idx].phone));

	char phone[20];
	wb_getstring("������ ��ȭ��ȣ", phone, sizeof(phone));

	strcpy_s(g_arr.base[idx].phone, sizeof(g_arr.base[idx].phone), phone);

	printf("�����Ǿ����ϴ�\n");
}

void con_delete()
{
	printf("[ȸ�� ���� ����]\n\n");

	char name[20];
	wb_getstring("������ �̸�", name, sizeof(name));

	int idx = nametoidx(name);
	if (idx == -1)
	{
		printf("�ش� �̸��� �������� �ʽ��ϴ�.\n");
		return;
	}

	//����
	//1���� : �����ּ�
	//2���� : ��� ����Ʈ�� 0���� ����
	//3���� : �����ּҺ��� 0���� ������ ������
	memset(&g_arr.base[idx], 0, sizeof(member));
	g_arr.base[idx].flag = 0;	//<--------------------------------------------
	strcpy_s(g_arr.base[idx].name, sizeof(g_arr.base[idx].name), "");
	g_arr.base[idx].phone[0] = '\0';

	printf("�����Ǿ����ϴ�\n");
}