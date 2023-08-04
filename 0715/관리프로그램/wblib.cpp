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
	cout << msg.c_str() << " : ";	// cout >> : 내부적으로 printf() 를 호출!
	cin >> str;						// cin >> : 내부적으로 scanf_s()  를 호출!
	cin.getline(str, sizeof(str));	//, gets_s()
	return str;
}