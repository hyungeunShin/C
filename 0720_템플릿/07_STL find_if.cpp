//07_Find_if

/*
find 알고리즘 함수는 기본형 타입에서의 검색은 가능하다.
하지만 객체가 저장된 구조에서는 사용이 불가능하다.
이를 해결해 주는 것이 find_if 함수다.
*/

#include <iostream>
#include <vector>
#include <algorithm>		//STL의 알고리즘 함수 사용
using namespace std;

class Stu
{
private:
	const int num; //상수 멤버 변수
	string name;

public:
	Stu(int num, string name) : num(num), name(name) {}

public:
	//상수 맴버 함수
	int GetNum()const			{ return num; }
	string GetName()const		{ return name; }
};



void myfind(vector<Stu*>::iterator begin, vector<Stu*>::iterator end, int value)
{
	//for (; begin != end; begin++)
	//{
	//	Stu *pstu =  *begin;
	//	if (pstu == value)	//??????????
	//}
}

//함수 객체 : 객체를 함수처럼 사용할 수 있는 문법
class CompareByNum
{
	int num;
public:
	CompareByNum(int num) : num(num) {}
public:
	bool operator()(Stu* stu)
	{
		return (stu->GetNum() == num);
	}
};

vector<Stu*>::iterator myfind_if(vector<Stu*>::iterator begin, vector<Stu*>::iterator end,
	CompareByNum cb)
{
	for (; begin != end; begin++)
	{
		Stu *pstu = *begin;
		if (cb(pstu))		//cb.operator()(pstu);
			return begin;
	}
	return end;
}

int main()
{
	vector<Stu*> base; 
	base.push_back(new Stu(111, "홍길동"));
	base.push_back(new Stu(222, "김길동"));

//	myfind(base.begin(), base.end(), 111);

	CompareByNum sbn(333);
	vector<Stu*>::iterator itr = find_if(base.begin(), base.end(), sbn);
	if (itr == base.end())
		cout << "없다" << endl;
	else
	{
		Stu* pstu = *itr;
		cout << pstu->GetNum() << ", " << pstu->GetName().c_str() << endl;
	}

	return 0;
}