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
	cout << "[��ȣ] " << num << endl;
	cout << "[�̸�] " << name.c_str() << endl; 
}
