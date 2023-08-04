//acclist.h

#pragma once
#include <iostream>
using namespace std;

class AccList
{
	int accid;			//계좌번호
	string accdate;		//거래일자
	string acctime;		//거래시간
	int inputmoney;		//입금
	int outputmoney;	//출금
	int balance;		//잔액
	tm newtime;		//거래발생일시

public:
	AccList(int accid, int inputmoney, int outputmoney, int balance);
	~AccList();

public:
	int get_accid() const { return accid;  }

public:
	void Print() const;
};

