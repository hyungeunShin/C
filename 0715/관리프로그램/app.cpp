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
	system("cls"); //ȭ�� �����   #include <stdlib.h>
	cout << "***************************************************************" << endl;
	printf(" ��Ʈ �ܱ� 54��\n");
	printf(" C++��� ����\n");
	printf(" OOP ����� ȸ�� ���� ���α׷�\n");
	printf(" 2021.07.15\n");
	printf(" ��â��\n");
	cout << "***************************************************************" << endl;
	system("pause"); //����
}

char App::menuprint()
{
	printf("***************************************************************\n");
	printf("[0] ���α׷� ����\n");
	printf("[1] Insert(ȸ�� ���� ����)\n");
	printf("[2] Select(ȸ�� ���� �˻� - �̸����� �˻�, �̸��� uniq)\n");
	printf("[3] Update(ȸ�� ���� ���� - �̸����� �˻��ؼ� ��ȭ��ȣ�� ���̸� ����)\n");
	printf("[4] Delete(ȸ�� ���� ���� - �̸����� �˻��ؼ� �ش� ������ 0���� �ʱ�ȭ)\n");
	printf("***************************************************************\n");
	return _getch();   //#include <conio.h>
}

void App::ending()
{
	system("cls");
	printf("***************************************************************\n");
	printf(" ���α׷��� �����մϴ�.\n");
	printf("***************************************************************\n");
	system("pause"); //����
}