//App.cpp

#include <iostream>
using namespace std;
#include "ehglobal.h"
#include "App.h"

App::App()
{
}

App::~App()
{
}


void App::Init()
{
	Logo();
}


void App::Run()
{
	while (true)
	{
		ehglobal::clrscr();		
		//��ü��±��
		ma.ListAll();
		keydata key = MenuPrint();
		switch (key)
		{
		case ESC: return;
		case F1: ma.AddMember();			break;
		case F2: ma.RemoveMember();			break;
		case F3: ma.SearchMemberByNum();	break;
		case F4: ma.SearchMemberByName();	break;
		case F5: ma.UpdateMember();			break;
		default: cout << "�߸��� �޴��� �����Ͽ����ϴ�." << endl;
		}
		ehglobal::pausescr();
	}
}


void App::Exit()
{
	Ending();
}


void App::Logo()
{
	ehglobal::clrscr();
	cout << "***********************************************************" << endl;
	cout << " ��ۺ�Ʈ �ܱ� C++��� ����" << endl;
	cout << " vector�����̳ʸ� �̿��� �ɹ� ���� ���α׷�" << endl;
	cout << " - �̸� ����ڰ� ���ϴ� ������ŭ�� ���� ������ ����" << endl;
	cout << " - ����� �ε����� �Է¹޾� �ش� ��ġ�� ����" << endl;
	cout << " 2021-07-21" << endl;
	cout << " ��â��" << endl; 
	cout << "***********************************************************" << endl;
	ehglobal::pausescr();
}

void App::Ending()
{
	ehglobal::clrscr();
	cout << "***********************************************************" << endl;
	cout << " ��ۺ�Ʈ �ܱ� C++��� ����" << endl;
	cout << " vector�����̳ʸ� �̿��� �ɹ� ���� ���α׷�" << endl;
	cout << " ���α׷��� �����մϴ�." << endl;
	cout << "***********************************************************" << endl;
	ehglobal::pausescr();
}

keydata App::MenuPrint()
{
	cout << "***********************************************************" << endl;
	cout << "[ESC] : ����" << endl;
	cout << "[ F1] : �ɹ� �߰� " << endl;
	cout << "[ F2] : �ɹ� ���� " << endl;
	cout << "[ F3] : ��ȣ�� �˻�" << endl;
	cout << "[ F4] : �̸����� �˻�" << endl;
	cout << "[ F5] : ��ȣ�� �˻� �� ���� ����(��ȭ��ȣ, ����)" << endl;
	cout << "***********************************************************" << endl;
	cout << ">> ";
	return ehglobal::getkey();
}
