//AccManager.cpp

#include <iostream>
#include <algorithm>
using namespace std;
#include "ehglobal.h"
#include "Account.h"
#include "AccManager.h"

AccManager::AccManager()
{
}

AccManager::~AccManager()
{
	for (int i = 0; i< (int)base.size(); i++)		//base.size()
	{
		delete base[i];		//���޸𸮿� ������ ��ü�� �Ҹ�
		base[i] = NULL;		//�迭�� �ּҸ� NULL�� ����	
	}
}

void AccManager::Exist(int number)
{
	vector<Account*>::iterator seek = base.begin();
	vector<Account*>::iterator end  = base.end();

	for (; seek != end; seek++)
	{
		Account* pacc = *seek;
		if (pacc->get_id() == number)
			throw "������ ��ȣ�� �����մϴ�.";
	}
}

void AccManager::AddAccount()
{
	try
	{
		cout << endl;
		cout << "���¹�ȣ ��ȣ�� �Է��ϼ���: ";
		int number = ehglobal::getnum();
		Exist(number);		//���¹�ȣ�� �����Ѵٸ� ���ܸ� �߻�!

		cout << "�̸��� �Է��ϼ��� : ";
		string name = ehglobal::getstr();

		cout << "�Աݾ��� �Է��ϼ���: ";
		int money = ehglobal::getnum();

		Account* pacc = new Account(number, name, money);

		base.push_back(pacc);			//<-- 0��°���� ���������� ����!

		AddAccList(number, money, 0, money);		//<---�ŷ� ���� ����1)

		cout << "���� ����" << endl;
	}
	catch (const char* msg)
	{
		cout << ">> �Է� ���� : " << msg << endl;
	}
}

void AccManager::ListAll()
{
	for (int i = 0; i< (int)base.size(); i++)
	{
		Account *pacc = base[i];
		if (pacc != NULL) //���� �л��� �����Ǿ����� Ȯ��
			pacc->Print();
	}
}

void AccManager::SearchAccountById()
{
	try
	{
		cout << "�˻��� ���¹�ȣ�� �Է��ϼ���: ";
		int accid = ehglobal::getnum();

		CompareById sbn(accid);		//stu.h���� --> Account ����[CompareById]
		vector<Account*>::iterator itr =
			find_if(base.begin(), base.end(), sbn);   //#include <algorithm>
		if (itr == base.end())
			throw "�ش� ���¹�ȣ�� �������� �ʽ��ϴ�.";

		Account* pacc = *itr;
		pacc->Println();

		PrintAccList(accid);  //<--------------- �ŷ� ���� ���!!!!!!!!!!!!!!!!
	}
	catch (const char* msg)
	{
		cout << "�˻� ���� : " << msg << endl;
	}
}

void AccManager::InputMoney(int accid, int money)
{
	CompareById sbn(accid);		//stu.h���� --> Account ����[CompareById]
	vector<Account*>::iterator itr =
		find_if(base.begin(), base.end(), sbn);   //#include <algorithm>
	if (itr == base.end())
		throw "�ش� ���¹�ȣ�� �������� �ʽ��ϴ�.";

	Account* pacc = *itr;
	pacc->InputMoney(money);

	AddAccList(accid, money, 0, pacc->get_balance());		//<---�ŷ� ���� ����2)
}

void AccManager::InputMoney()
{
	try
	{
		cout << "�Ա��� ���¹�ȣ�� �Է��ϼ���: ";
		int accid = ehglobal::getnum();

		cout << "�Աݾ��� �Է��ϼ���: ";
		int money = ehglobal::getnum();

		InputMoney(accid, money);	//�������� throw		

		cout << "�ԱݵǾ����ϴ�." << endl;
	}
	catch (const char* msg)
	{
		cout << "�Ա� ���� : " << msg << endl;
	}
}

void AccManager::OutputMoney(int accid, int money)
{
	CompareById sbn(accid);		//stu.h���� --> Account ����[CompareById]
	vector<Account*>::iterator itr =
		find_if(base.begin(), base.end(), sbn);   //#include <algorithm>
	if (itr == base.end())
		throw "�ش� ���¹�ȣ�� �������� �ʽ��ϴ�.";

	Account* pacc = *itr;
	pacc->OutputMoney(money);

	AddAccList(accid, 0, money, pacc->get_balance());		//<---�ŷ� ���� ����3)
}

void AccManager::OutputMoney()
{
	try
	{
		cout << "����� ���¹�ȣ�� �Է��ϼ���: ";
		int accid = ehglobal::getnum();

		cout << "��ݾ��� �Է��ϼ���: ";
		int money = ehglobal::getnum();

		OutputMoney(accid, money);	//���� : throw

		cout << "��ݵǾ����ϴ�." << endl;
	}
	catch (const char* msg)
	{
		cout << "��� ���� : " << msg << endl;
	}
}

void AccManager::RemoveAccount()
{
	try
	{
		cout << "���¹�ȣ�� �Է��ϼ���: ";
		int accid = ehglobal::getnum();

		CompareById sbn(accid);
		vector<Account*>::iterator itr =
			find_if(base.begin(), base.end(), sbn);   //#include <algorithm>

		//���� ������ STU��ü�� ���� �Ҹ�ó��
		Account* pacc = *itr;
		delete pacc;

		base.erase(itr);	//���������̳ʿ��� �ּҰ� �����.!

		cout << "���� �Ǿ����ϴ�." << endl;
	}
	catch (const char* msg)
	{
		cout << "���� ���� : " << msg << endl;
	}
}

void AccManager::TransferMoney()
{
	try
	{
		cout << "����� ���¹�ȣ�� �Է��ϼ���: ";
		int outputid = ehglobal::getnum();

		cout << "��ü�ݾ� �Է��ϼ���: ";
		int money = ehglobal::getnum();

		cout << "��ü�� ����� ���¹�ȣ�� �Է��ϼ���: ";
		int inputid = ehglobal::getnum();

		OutputMoney(outputid, money);
		InputMoney(inputid, money);

		cout << "��ü�Ǿ����ϴ�." << endl;
	}
	catch (const char* msg)
	{
		cout << "��� ���� : " << msg << endl;
	}
}

void AccManager::AddAccList(int accid, int input, int output, int balance)
{
	AccList *plist = new AccList(accid, input, output, balance);

	baselist.push_back(plist);

	cout << "�ŷ� ������ ����Ǿ����ϴ�." << endl;
}

void AccManager::PrintAccList(int accid)
{
	cout << "\n[�ŷ� ����]" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "���¹�ȣ\t����\t�ð�\t�Ա�\t���\t�ܾ�" << endl;
	cout << "-------------------------------------------------------------" << endl;
	for (int i = 0; i < (int)baselist.size(); i++)
	{
		AccList *aclist = baselist[i];
		if (aclist->get_accid() == accid)
		{
			aclist->Print();
		}
	}
}
