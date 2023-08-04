//app.cpp

#include "std.h"

void App::init()
{
	logo();
}

void App::run()
{
	while (true)
	{
		system("cls");
		con.printall();
		switch (menuprint())
		{
		case '0': return;
		case '1': con.insert(); break;
		case '2': con.select(); break;
		case '3': con.update(); break;
		case '4': con.delete1(); break;
		}
		system("pause");
	}
}

void App::exit()
{
	ending();
}

void App::logo()
{
	system("cls"); //화면 지우기   #include <stdlib.h>
	cout << "***************************************************************" << endl;
	printf(" 비트 단기 54차\n");
	printf(" C++언어 과정\n");
	printf(" OOP 기반의 회원 관리 프로그램\n");
	printf(" 2021.07.15\n");
	printf(" 최창민\n");
	cout << "***************************************************************" << endl;
	system("pause"); //멈춤
}

char App::menuprint()
{
	printf("***************************************************************\n");
	printf("[0] 프로그램 종료\n");
	printf("[1] Insert(회원 정보 저장)\n");
	printf("[2] Select(회원 정보 검색 - 이름으로 검색, 이름은 uniq)\n");
	printf("[3] Update(회원 정보 수정 - 이름으로 검색해서 전화번호와 나이를 수정)\n");
	printf("[4] Delete(회원 정보 삭제 - 이름으로 검색해서 해당 정보를 0으로 초기화)\n");
	printf("***************************************************************\n");
	return _getch();   //#include <conio.h>
}

void App::ending()
{
	system("cls");
	printf("***************************************************************\n");
	printf(" 프로그램을 종료합니다.\n");
	printf("***************************************************************\n");
	system("pause"); //멈춤
}