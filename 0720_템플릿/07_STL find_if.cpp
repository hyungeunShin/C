//07_Find_if

/*
find �˰��� �Լ��� �⺻�� Ÿ�Կ����� �˻��� �����ϴ�.
������ ��ü�� ����� ���������� ����� �Ұ����ϴ�.
�̸� �ذ��� �ִ� ���� find_if �Լ���.
*/

#include <iostream>
#include <vector>
#include <algorithm>		//STL�� �˰��� �Լ� ���
using namespace std;

class Stu
{
private:
	const int num; //��� ��� ����
	string name;

public:
	Stu(int num, string name) : num(num), name(name) {}

public:
	//��� �ɹ� �Լ�
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

//�Լ� ��ü : ��ü�� �Լ�ó�� ����� �� �ִ� ����
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
	base.push_back(new Stu(111, "ȫ�浿"));
	base.push_back(new Stu(222, "��浿"));

//	myfind(base.begin(), base.end(), 111);

	CompareByNum sbn(333);
	vector<Stu*>::iterator itr = find_if(base.begin(), base.end(), sbn);
	if (itr == base.end())
		cout << "����" << endl;
	else
	{
		Stu* pstu = *itr;
		cout << pstu->GetNum() << ", " << pstu->GetName().c_str() << endl;
	}

	return 0;
}