//ehglobal.h

#pragma once
#include <iostream>
using namespace std;

enum keydata
{
	NO_DEFINED, F1, F2, F3, F4, F5, F6, F7, ESC  //0 ~ 
};

//static �޼��常 �����ϴ� Ŭ���� 
// - ��ü ���� ����� �� �ִ� �޼���
class ehglobal
{
public:
	static void clrscr();			//ȭ���� ����� �޼���
	static void pausescr();			//ȭ���� ���ߴ� �޼���
	static int getnum();			//���� �Է¹޴� �޼���
	static string getstr();			//���ڿ��� �Է¹޴� �޼���
	static keydata getkey();		//��� Ű(Funtion)�� �Է¹޴� �޼���

private:			//�ܺο��� ��ü�� ������ �� ������ �Ͽ���.
	ehglobal();
	~ehglobal();
};

