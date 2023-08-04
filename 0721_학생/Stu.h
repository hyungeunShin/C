//stdu.h

#pragma once
#include <iostream>
using namespace std;

class Stu
{
private:
	const int num; //상수 멤버 변수
	string name;

public:
	Stu(int num, string name);
	~Stu();

public:
	//상수 맴버 함수
	int GetNum()const			{		return num;		}
	string GetName()const		{		return name;	}
	void setName(string value)  { name = value;			}

public:
	void Print() const;
	
	//전역함수를 친구화 한 코드.
	friend ostream &operator<<(ostream &os, Stu *stu)
	{
		os << "[번호] " << stu->num << "\t[이름] " << stu->name.c_str();
		return os;
	}
};

//출력연산자 재정의 반드시 전역함수형태...

