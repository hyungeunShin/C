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
	cout << "�ִ� ������ ȸ�� ���� �Է��ϼ��� : ";
	return ehglobal::getnum();
}


int StuManager::InputNumber()
{
	cout << "�߰��� ȸ�� ��ȣ�� �Է��ϼ���(0 ~ " << max_stu-1 << ") : ";
	int num = ehglobal::getnum();
	if ((num < 0) || (num >= max_stu))
		throw "������ ������ϴ�."; 

	if (base[num]) //���� �л��� �����Ǿ����� Ȯ��
		throw "�̹� ������ ȸ���� �ֽ��ϴ�.";

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

//�Է� ���� ����
void StuManager::AddMember()
{
	try
	{
		int number = InputNumber();

		cout << "�̸��� �Է��ϼ��� : ";
		string name = ehglobal::getstr();

		cout << "��ȭ��ȣ�� �Է��ϼ��� : ";
		string phone = ehglobal::getstr();

		cout << "���̸� �Է��ϼ��� : ";
		int age = ehglobal::getnum();

		cout << "������ �Է��ϼ��� : ";
		char gender = ehglobal::getchar();

		Member* pstu = new Member(number, name, phone, age, gender);

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
		Member *pmem = base[i];
		if (pmem != NULL) //���� �л��� �����Ǿ����� Ȯ��
			cout << pmem << endl;
	}
}

//1. ������ ��ȣ �Է�(������ �ε����� ����)  [2. ���޸� ����   3. �ڽ��� �޸𸮸� NULL�ʱ�ȭ]
void StuManager::RemoveMember()
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

void StuManager::SearchMemberByNum()
{
	try
	{
		int num = InputNumber("�˻�");

		Member* pmem = base[num];
		pmem->println();
	}
	catch (const char* msg)
	{
		cout << "�˻� ���� : " << msg << endl;
	}	
}

//���� �˻�
Member* StuManager::NameToMember(string name)
{
	for (int i = 0; i<max_stu; i++)
	{
		Member* pmem = base[i];

		if (pmem != NULL) //���� �л��� �����Ǿ����� Ȯ��
		{
			if (pmem->getname() == name)
				return pmem;
		}
	}
	throw "�������� ���� �л��Դϴ�.";
}

void StuManager::SearchMemberByName()
{
	try
	{
		cout << "�˻��� �л� �̸��� �Է��ϼ��� : ";
		string name = ehglobal::getstr();

		Member *pmem = NameToMember(name);
		pmem->println();
	}
	catch (const char* msg)
	{
		cout << "�˻� ���� : " << msg << endl; 
	}
}

void StuManager::UpdateMember()
{
	try
	{
		int num		  =	InputNumber("����");   //��ü�� ����Ǿ� �ִ� �ε����� ã�� ����!

		cout << "������ �л��� ��ȭ��ȣ�� �Է��ϼ��� : ";
		string phone = ehglobal::getstr();

		cout << "������ �л��� ���̸� �Է��ϼ��� : ";
		int age = ehglobal::getnum();

		Member* pmem = base[num];
		pmem->setphone(phone);
		pmem->setage(age); 

		cout << "�����Ǿ����ϴ�." << endl;
	}
	catch (const char* msg)
	{
		cout << "���� ���� : " << msg << endl;
	}
}
