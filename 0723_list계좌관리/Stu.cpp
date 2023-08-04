//stu.cpp

#include "Stu.h"

Stu::Stu(int num, string name) : num(num), name(name)
{
//	this->name = name;
}

Stu::~Stu()
{
}

void Stu::Print() const
{
	cout << "[번호] " << num << endl;
	cout << "[이름] " << name.c_str() << endl; 
}
