////stumanager.cpp

#include <iostream>
using namespace std;
#include "ehglobal.h"
#include "StuManager.h"

StuManager::StuManager() : max_stu(SetMaxStu())
{
	base.resize(max_stu, 0);
}

StuManager::~StuManager()
{
	for (int i = 0; i<max_stu; i++)		//base.size()
	{
		if (base[i] != NULL) //���� �л��� ������ ������ Ȯ��
		{
			delete base[i];		//���޸𸮿� ������ ��ü�� �Ҹ�
			base[i] = NULL;		//�迭�� �ּҸ� NULL�� ����
		}
	}
}

int StuManager::SetMaxStu()
{
	cout << "�ִ� ������ �л� ���� �Է��ϼ��� : ";
	return ehglobal::getnum();
}

int StuManager::InputNumber()
{
	cout << "�߰��� �л� ��ȣ�� �Է��ϼ���(0 ~ " << max_stu-1 << ") : ";
	int num = ehglobal::getnum();
	if ((num < 0) || (num >= max_stu))
		throw "������ ������ϴ�."; 

	if (base[num]) //���� �л��� �����Ǿ����� Ȯ��
		throw "�̹� ������ �л��� �ֽ��ϴ�.";

	return num;
}

int StuManager::InputNumber(string type)
{
	cout << "[" << type.c_str() << "]" << "�л� ��ȣ�� �Է��ϼ���(0 ~" << max_stu - 1 << ") : ";
	int num = ehglobal::getnum();
	if ((num < 0) || (num >= max_stu))
		throw "������ ������ϴ�.";

	if (base[num] == NULL) //���� �л��� �����Ǿ����� Ȯ��
		throw "������ �л��� �����ϴ�.";

	return num;
}

//1. �ӽú������� 2.�ʱ�ȭ  3.�ӽú������̿��� ���尴ü�� ����  4. ����
void StuManager::AddStu()
{
	try
	{
		int number = InputNumber();

		cout << "�̸��� �Է��ϼ��� : ";
		string name = ehglobal::getstr();	

		Stu* pstu = new Stu(number, name);

		base[number] = pstu;

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
	for (int i = 0; i<max_stu; i++)
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
		int num = InputNumber("����");

		delete base[num];
		base[num] = NULL; //�ʱⰪ 0���� �ٽ� ����

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
		int num = InputNumber("�˻�");

		Stu* pstu = base[num];
		pstu->Print();
	}
	catch (const char* msg)
	{
		cout << "�˻� ���� : " << msg << endl;
	}	
}

//���� �˻�
Stu* StuManager::NameToStu(string name)
{
	for (int i = 0; i<max_stu; i++)
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

void StuManager::SearchStuByName()
{
	try
	{
		cout << "�˻��� �л� �̸��� �Է��ϼ��� : ";
		string name = ehglobal::getstr();

		Stu *pstu = NameToStu(name);
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
		int num		  =	InputNumber("����");   //��ü�� ����Ǿ� �ִ� �ε����� ã�� ����!

		cout << "������ �л� �̸��� �Է��ϼ��� : ";
		string name = ehglobal::getstr();

		Stu* pstu = base[num];
		pstu->setName(name);

		cout << "�����Ǿ����ϴ�." << endl;
	}
	catch (const char* msg)
	{
		cout << "���� ���� : " << msg << endl;
	}
}
