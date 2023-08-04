//app.c

#include "std.h"

void app_init()
{
	logo();
}

void app_run()
{
	char input;
	while (1)
	{
		system("cls");

		con_printall();

		menuprint();
	
		input = _getch();   //#include <conio.h>
	
		switch (input)
		{
		case '0': return;
		case '1': con_insert(); break;
		case '2': con_update(); break;
		case '3': con_select(); break;
		case '4': con_delete(); break;
		}		

		system("pause");
	}
}

void app_exit()
{
	ending();
}

void logo()
{
	system("cls"); //ȭ�� �����   #include <stdlib.h>
	printf("*************************************************\n");
	printf(" ��Ʈ �ܱ� 52��\n");
	printf(" C��� ����\n");
	printf(" ���� ���� ���α׷�\n");
	printf(" 2021.06.28\n");
	printf(" ȫ�浿\n"); 
	printf("*************************************************\n");
	system("pause"); //����
}

void menuprint()
{
	printf("*************************************************\n");
	printf("[0] ���α׷� ����\n");
	printf("[1] Insert(����)\n");
	printf("[2] Update(����)\n");
	printf("[3] Select(�˻�)\n");
	printf("[4] Delete(����)\n");
	printf("*************************************************\n");
}

void ending()
{
	system("cls");
	printf("*************************************************\n");	
	printf(" ���α׷��� �����մϴ�.\n");
	printf("*************************************************\n");
	system("pause"); //����
}