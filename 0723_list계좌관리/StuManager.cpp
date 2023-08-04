////stumanager.cpp

#include <iostream>
#include <algorithm>
using namespace std;
#include "ehglobal.h"
#include "StuManager.h"

StuManager::StuManager() 
{
}

StuManager::~StuManager()
{

	for (int i = 0; i< (int)base.size(); i++)		//base.size()
	{
		delete base[i];		//���޸𸮿� ������ ��ü�� �Ҹ�
		base[i] = NULL;		//�迭�� �ּҸ� NULL�� ����	
	}
}


void StuManager::Exist(int number)
{
	vector<Stu*>::iterator seek = base.begin();
	vector<Stu*>::iterator end = base.end();

	for (; seek != end; seek++)
	{
		Stu* pstu = *seek;
		if (pstu->GetNum() == number)
			throw "������ ��ȣ�� �����մϴ�.";
	}
}

//������ �˻� ���(���� �˻�)
Stu* StuManager::NameToStu(string name)
{
	for (int i = 0; i< (int)base.size(); i++)
	{
		Stu* pstu = base[i];

		if (pstu != NULL) //���� �л��� �����Ǿ����� Ȯ��
		{
			if (pstu->GetName() == name)
				return pstu;
		}
	}
	throw "�������� ���� �л��Դϴ�.";
}


//1. �ӽú������� 2.�ʱ�ȭ  3.�ӽú������̿��� ���尴ü�� ����  4. ����
void StuManager::AddStu()
{
	try
	{
		cout << "�л� ��ȣ�� �Է��ϼ���: ";
		int number = ehglobal::getnum();
		Exist(number);		//�����Ѵٸ� ���ܸ� �߻�!

		cout << "�̸��� �Է��ϼ��� : ";
		string name = ehglobal::getstr();	

		Stu* pstu = new Stu(number, name);

		base.push_back(pstu);			//<-- 0��°���� ���������� ����!

		cout << "���� ����" << endl;
	}
	catch (const char* msg)
	{
		cout << ">> �Է� ���� : " << msg << endl;
	}
}

//1.��ȸ �� ��ü ���
void StuManager::ListAll()
{
	for (int i = 0; i< (int)base.size(); i++)
	{
		Stu *pstu = base[i];
		if (pstu != NULL) //���� �л��� �����Ǿ����� Ȯ��
			cout << pstu << endl;
	}
}

//1. ������ ��ȣ �Է�(������ �ε����� ����)  [2. ���޸� ����   3. �ڽ��� �޸𸮸� NULL�ʱ�ȭ]
void StuManager::RemoveStu()
{
	try
	{
		cout << "�л� ��ȣ�� �Է��ϼ���: ";
		int number = ehglobal::getnum();

		CompareByNum sbn(number);
		vector<Stu*>::iterator itr = 
			find_if(base.begin(), base.end(), sbn);   //#include <algorithm>

		//���� ������ STU��ü�� ���� �Ҹ�ó��
		Stu* pdel = *itr;
		delete pdel;

		base.erase(itr);	//���������̳ʿ��� �ּҰ� �����.!

		cout << "���� �Ǿ����ϴ�." << endl; 
	}
	catch (const char* msg)
	{
		cout << "���� ���� : " << msg << endl; 
	}
}


void StuManager::SearchStuByNum()
{
	try
	{
		cout << "�˻��� �л� ��ȣ�� �Է��ϼ���: ";
		int number = ehglobal::getnum();

		CompareByNum sbn(number);
		vector<Stu*>::iterator itr =
			find_if(base.begin(), base.end(), sbn);   //#include <algorithm>
		if (itr == base.end())
			throw "�ش� ��ȣ�� �������� �ʽ��ϴ�.";

		Stu* pstu = *itr;
		pstu->Print();		
	}
	catch (const char* msg)
	{
		cout << "�˻� ���� : " << msg << endl;
	}	
}


void StuManager::SearchStuByName()
{
	try
	{
		cout << "�˻��� �л��� �̸��� �Է��ϼ���: ";
		string name = ehglobal::getstr();

		CompareByName sbn(name);
		vector<Stu*>::iterator itr =
			find_if(base.begin(), base.end(), sbn);   //#include <algorithm>
		if (itr == base.end())
			throw "�ش� ��ȣ�� �������� �ʽ��ϴ�.";

		Stu* pstu = *itr;
		pstu->Print();
	}
	catch (const char* msg)
	{
		cout << "�˻� ���� : " << msg << endl;
	}
}


void StuManager::UpdateName()
{
	try
	{
		cout << "�˻��� �л� ��ȣ�� �Է��ϼ���: ";
		int number = ehglobal::getnum();

		CompareByNum sbn(number);
		vector<Stu*>::iterator itr =
			find_if(base.begin(), base.end(), sbn);   //#include <algorithm>
		if (itr == base.end())
			throw "�ش� ��ȣ�� �������� �ʽ��ϴ�.";

		cout << "������ �л� �̸��� �Է��ϼ��� : ";
		string name = ehglobal::getstr();

		Stu* pstu = *itr;
		pstu->setName(name);

		cout << "�����Ǿ����ϴ�." << endl;
	}
	catch (const char* msg)
	{
		cout << "���� ���� : " << msg << endl;
	}
}
