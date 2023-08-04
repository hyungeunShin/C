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

//Stu의 맴버필드 중 num으로 비교하는 클래스
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

//Stud의 맴버필드 중 name으로 비교하는 클래스
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