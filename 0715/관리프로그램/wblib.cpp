//wblib.cpp

#include "std.h"


int Wblib::getint(string msg)
{
	int num;
	cout << msg.c_str() << " : ";
	cin >> num;
	return num;
}

char Wblib::getchar(string msg)
{
	char ch;
	cout << msg.c_str() << " : ";
	cin >> ch;
	return ch;
}

string Wblib::getstring(string msg)
{
	char str[50];
	cout << msg.c_str() << " : ";	// cout >> : ���������� printf() �� ȣ��!
	cin >> str;						// cin >> : ���������� scanf_s()  �� ȣ��!
	cin.getline(str, sizeof(str));	//, gets_s()
	return str;
}