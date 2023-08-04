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
	system("cls"); //화면 지우기   #include <stdlib.h>
	printf("*************************************************\n");
	printf(" 비트 단기 52차\n");
	printf(" C언어 과정\n");
	printf(" 점수 관리 프로그램\n");
	printf(" 2021.06.28\n");
	printf(" 홍길동\n"); 
	printf("*************************************************\n");
	system("pause"); //멈춤
}

void menuprint()
{
	printf("*************************************************\n");
	printf("[0] 프로그램 종료\n");
	printf("[1] Insert(저장)\n");
	printf("[2] Update(수정)\n");
	printf("[3] Select(검색)\n");
	printf("[4] Delete(삭제)\n");
	printf("*************************************************\n");
}

void ending()
{
	system("cls");
	printf("*************************************************\n");	
	printf(" 프로그램을 종료합니다.\n");
	printf("*************************************************\n");
	system("pause"); //멈춤
}