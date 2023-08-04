//app.c

#include "std.h"

void app_init()
{
	logo();
	con_init();
}

void app_run()
{
	while (1)
	{
		system("cls");
		con_printall();
		switch (menuprint())
		{
		case '0': return;
		case '1': con_insert(); break;
		case '2': con_select(); break;
		case '3': con_update(); break;
		case '4': con_delete(); break;
		}		
		system("pause");
	}
}

void app_exit()
{
	ending();
	con_exit();
}

void logo()
{
	system("cls"); //ȭ�� �����   #include <stdlib.h>
	printf("***************************************************************\n");
	printf(" ��Ʈ �ܱ� 52��\n");
	printf(" C��� ����\n");
	printf(" ��ȭ��ȣ ���� ���α׷�\n");
	printf(" 2021.07.06\n");
	printf(" ��â��\n"); 
	printf("***************************************************************\n");
	system("pause"); //����
}

char menuprint()
{
	printf("***************************************************************\n");
	printf("[0] ���α׷� ����\n");
	printf("[1] Insert(ȸ�� ���� ����)\n");
	printf("[2] Select(ȸ�� ���� �˻� - �̸����� �˻�, �̸��� uniq)\n");
	printf("[3] Update(ȸ�� ���� ���� - �̸����� �˻��ؼ� ��ȭ��ȣ ����)\n");	
	printf("[4] Delete(ȸ�� ���� ���� - �̸����� �˻��ؼ� ����)\n");
	printf("***************************************************************\n");
	return _getch();
}

void ending()
{
	system("cls");
	printf("***************************************************************\n");	
	printf(" ���α׷��� �����մϴ�.\n");
	printf("***************************************************************\n");
	system("pause"); //����
}