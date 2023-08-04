//member.cpp

#include "std.h"

int  Member::s_number = 1000;   //static 맴버 필드가 생성된다.

Member::Member(string _name, string _phone, int _age, char _gender)
{
	this->name		= _name;
	this->phone		= _phone;
	this->age		= _age;
	this->gender	= _gender;
	this->number    = s_number;
	s_number		= s_number + 1;

}

Member::~Member()
{

}

void Member::print() const
{
	cout << "[" <<  number <<"] ";
	cout << name.c_str() << "\t";			//string타입에서 저장된 문자열 반환
	cout << phone.c_str() << "\t";
	cout << age << "\t";
	cout << (gender=='m'?"남":"여") << endl;
}

void Member::println() const
{
	cout << "회원번호 : " << number << endl;
	cout << "이    름 : " << name.c_str() << endl;
	cout << "전화번호 : " << phone.c_str() << endl;
	cout << "나    이 : " << age << endl;
	cout << "성    별 : " << (gender == 'm' ? "남" : "여") << endl;
}