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

//��¿����� ������ �ݵ�� �����Լ�����...

