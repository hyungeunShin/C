//ehglobal.h

#pragma once
#include <iostream>
using namespace std;

enum keydata
{
	NO_DEFINED, F1, F2, F3, F4, F5, F6, F7, ESC  //0 ~ 
};

//static 메서드만 제공하는 클래스 
// - 객체 없이 사용할 수 있는 메서드
class ehglobal
{
public:
	static void clrscr();			//화면을 지우는 메서드
	static void pausescr();			//화면을 멈추는 메서드
	static int getnum();			//수를 입력받는 메서드
	static string getstr();			//문자열을 입력받는 메서드
	static keydata getkey();		//기능 키(Funtion)를 입력받는 메서드

private:			//외부에서 객체를 생성할 수 없도록 하였다.
	ehglobal();
	~ehglobal();
};

