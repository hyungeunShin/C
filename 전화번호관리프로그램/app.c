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
	system("cls"); //화면 지우기   #include <stdlib.h>
	printf("***************************************************************\n");
	printf(" 비트 단기 52차\n");
	printf(" C언어 과정\n");
	printf(" 전화번호 관리 프로그램\n");
	printf(" 2021.07.06\n");
	printf(" 최창민\n"); 
	printf("***************************************************************\n");
	system("pause"); //멈춤
}

char menuprint()
{
	printf("***************************************************************\n");
	printf("[0] 프로그램 종료\n");
	printf("[1] Insert(회원 정보 저장)\n");
	printf("[2] Select(회원 정보 검색 - 이름으로 검색, 이름은 uniq)\n");
	printf("[3] Update(회원 정보 수정 - 이름으로 검색해서 전화번호 수정)\n");	
	printf("[4] Delete(회원 정보 삭제 - 이름으로 검색해서 삭제)\n");
	printf("***************************************************************\n");
	return _getch();
}

void ending()
{
	system("cls");
	printf("***************************************************************\n");	
	printf(" 프로그램을 종료합니다.\n");
	printf("***************************************************************\n");
	system("pause"); //멈춤
}