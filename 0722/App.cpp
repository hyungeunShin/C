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
		ama.ListAll();
		keydata key = MenuPrint();
		switch (key)
		{
		case ESC: return;
		case F1: ama.AddAccount();				break;
		case F2: ama.SearchAccountById();		break;
		case F3: ama.InputMoney();				break;
		case F4: ama.OutputMoney();				break;
		case F5: ama.RemoveAccount();			break;
		case F6: ama.TransferMoney();			break;
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
	cout << " vector�����̳ʸ� �̿��� ���� ���� ���α׷�" << endl;
	cout << " - ������ ����" << endl;
	cout << " 2021-07-22" << endl;
	cout << " ��â��" << endl; 
	cout << "***********************************************************" << endl;
	ehglobal::pausescr();
}

void App::Ending()
{
	ehglobal::clrscr();
	cout << "***********************************************************" << endl;
	cout << " ��ۺ�Ʈ �ܱ� C++��� ����" << endl;
	cout << " vector�����̳ʸ� �̿��� ���� ���� ���α׷�" << endl;
	cout << " ���α׷��� �����մϴ�." << endl;
	cout << "***********************************************************" << endl;
	ehglobal::pausescr();
}

keydata App::MenuPrint()
{
	cout << "***********************************************************" << endl;
	cout << "[ESC] : ����" << endl;
	cout << "[ F1] : ���� ����(insert) " << endl;
	cout << "[ F2] : ���¹�ȣ�� �˻�(select) " << endl;
	cout << "[ F3] : ���¹�ȣ�� �˻��ؼ� �Ա�(update)" << endl;
	cout << "[ F4] : ���¹�ȣ�� �˻��ؼ� ���(update)" << endl;
	cout << "[ F5] : ���¹�ȣ�� �˻��ؼ� ����(delete)" << endl;
	cout << "[ F6] : ���¹�ȣ�� �˻��ؼ� ��ü(update)" << endl;
	cout << "***********************************************************" << endl;
	cout << ">> ";
	return ehglobal::getkey();
}
