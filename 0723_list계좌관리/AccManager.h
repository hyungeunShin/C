//AccManager.h
#pragma once

#include <vector>
#include <list>
using namespace std;
#include "Account.h"
#include "AccList.h"

class AccManager
{
	list<Account*> base;		//Account*�� �����ϴ� �迭�� ����(ca:0, size:0)
	vector<AccList*> baselist;	//AccList*�� �����ϴ� �迭�� ����

public:
	AccManager();
	~AccManager();

	//Account
private:
	void Exist(int number);
	void InputMoney(int accid, int money);
	void OutputMoney(int accid, int money);

	//AccoutList
private:
	void AddAccList(int accid, int input, int output, int balance);
	void PrintAccList(int accid);

public:
	void AddAccount();			//���� ���� 
	void ListAll();				//��ü ���¸���Ʈ ���
	void SearchAccountById();	//���¹�ȣ�� �˻�
	void InputMoney();			//�Ա�
	void OutputMoney();			//���
	void RemoveAccount();		//���� ����
	void TransferMoney();		//���� ��ü
};

