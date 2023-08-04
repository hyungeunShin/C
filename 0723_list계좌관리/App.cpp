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
		//전체출력기능
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
		default: cout << "잘못된 메뉴를 선택하였습니다." << endl;
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
	cout << " 우송비트 단기 C++언어 과정" << endl;
	cout << " vector컨테이너를 이용한 계좌 관리 프로그램" << endl;
	cout << " - 순차적 저장" << endl;
	cout << " 2021-07-22" << endl;
	cout << " 최창민" << endl; 
	cout << "***********************************************************" << endl;
	ehglobal::pausescr();
}

void App::Ending()
{
	ehglobal::clrscr();
	cout << "***********************************************************" << endl;
	cout << " 우송비트 단기 C++언어 과정" << endl;
	cout << " vector컨테이너를 이용한 계좌 관리 프로그램" << endl;
	cout << " 프로그램을 종료합니다." << endl;
	cout << "***********************************************************" << endl;
	ehglobal::pausescr();
}

keydata App::MenuPrint()
{
	cout << "***********************************************************" << endl;
	cout << "[ESC] : 종료" << endl;
	cout << "[ F1] : 계좌 생성(insert) " << endl;
	cout << "[ F2] : 계좌번호로 검색(select) " << endl;
	cout << "[ F3] : 계좌번호로 검색해서 입금(update)" << endl;
	cout << "[ F4] : 계좌번호로 검색해서 출금(update)" << endl;
	cout << "[ F5] : 계좌번호로 검색해서 삭제(delete)" << endl;
	cout << "[ F6] : 계좌번호로 검색해서 이체(update)" << endl;
	cout << "***********************************************************" << endl;
	cout << ">> ";
	return ehglobal::getkey();
}
