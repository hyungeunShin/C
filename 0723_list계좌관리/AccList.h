//acclist.h

#pragma once
#include <iostream>
using namespace std;

class AccList
{
	int accid;			//���¹�ȣ
	string accdate;		//�ŷ�����
	string acctime;		//�ŷ��ð�
	int inputmoney;		//�Ա�
	int outputmoney;	//���
	int balance;		//�ܾ�
	tm newtime;		//�ŷ��߻��Ͻ�

public:
	AccList(int accid, int inputmoney, int outputmoney, int balance);
	~AccList();

public:
	int get_accid() const { return accid;  }

public:
	void Print() const;
};

