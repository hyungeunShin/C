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
	cout << " vector컨테이너를 이용한 맴버 관리 프로그램" << endl;
	cout << " - 미리 사용자가 원하는 개수만큼의 저장 공간을 생성" << endl;
	cout << " - 저장시 인덱스를 입력받아 해당 위치에 저장" << endl;
	cout << " 2021-07-21" << endl;
	cout << " 최창민" << endl; 
	cout << "***********************************************************" << endl;
	ehglobal::pausescr();
}

void App::Ending()
{
	ehglobal::clrscr();
	cout << "***********************************************************" << endl;
	cout << " 우송비트 단기 C++언어 과정" << endl;
	cout << " vector컨테이너를 이용한 맴버 관리 프로그램" << endl;
	cout << " 프로그램을 종료합니다." << endl;
	cout << "***********************************************************" << endl;
	ehglobal::pausescr();
}

keydata App::MenuPrint()
{
	cout << "***********************************************************" << endl;
	cout << "[ESC] : 종료" << endl;
	cout << "[ F1] : 맴버 추가 " << endl;
	cout << "[ F2] : 맴버 삭제 " << endl;
	cout << "[ F3] : 번호로 검색" << endl;
	cout << "[ F4] : 이름으로 검색" << endl;
	cout << "[ F5] : 번호로 검색 후 정보 변경(전화번호, 나이)" << endl;
	cout << "***********************************************************" << endl;
	cout << ">> ";
	return ehglobal::getkey();
}
