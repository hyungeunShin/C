//stdu.h

#pragma once
#include <iostream>
using namespace std;

class Stu
{
private:
	const int num; //��� ��� ����
	string name;

public:
	Stu(int num, string name);
	~Stu();

public:
	//��� �ɹ� �Լ�
	int GetNum()const			{		return num;		}
	string GetName()const		{		return name;	}
	void setName(string value)  { name = value;			}

public:
	void Print() const;
	
	//�����Լ��� ģ��ȭ �� �ڵ�.
	friend ostream &operator<<(ostream &os, Stu *stu)
	{
		os << "[��ȣ] " << stu->num << "\t[�̸�] " << stu->name.c_str();
		return os;
	}
};

//Stu�� �ɹ��ʵ� �� num���� ���ϴ� Ŭ����
class CompareByNum
{
	int num;
public:
	CompareByNum(int num) : num(num) {}
public:
	bool operator()(Stu*pstu)
	{
		return (pstu->GetNum() == num);
	}
};

//Stud�� �ɹ��ʵ� �� name���� ���ϴ� Ŭ����
class CompareByName
{
	string name;
public:
	CompareByName(string name) : name(name) {}
public:
	bool operator()(Stu*pstu)
	{
		return (pstu->GetName() == name);
	}
};