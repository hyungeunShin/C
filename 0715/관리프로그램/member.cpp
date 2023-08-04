//member.cpp

#include "std.h"

int  Member::s_number = 1000;   //static �ɹ� �ʵ尡 �����ȴ�.

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
	cout << name.c_str() << "\t";			//stringŸ�Կ��� ����� ���ڿ� ��ȯ
	cout << phone.c_str() << "\t";
	cout << age << "\t";
	cout << (gender=='m'?"��":"��") << endl;
}

void Member::println() const
{
	cout << "ȸ����ȣ : " << number << endl;
	cout << "��    �� : " << name.c_str() << endl;
	cout << "��ȭ��ȣ : " << phone.c_str() << endl;
	cout << "��    �� : " << age << endl;
	cout << "��    �� : " << (gender == 'm' ? "��" : "��") << endl;
}