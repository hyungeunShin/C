//AccManager.h
#pragma once

#include <vector>
#include <list>
using namespace std;
#include "Account.h"
#include "AccList.h"

class AccManager
{
	list<Account*> base;		//Account*를 저장하는 배열이 생성(ca:0, size:0)
	vector<AccList*> baselist;	//AccList*를 저장하는 배열이 생성

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
	void AddAccount();			//계좌 개설 
	void ListAll();				//전체 계좌리스트 출력
	void SearchAccountById();	//계좌번호로 검색
	void InputMoney();			//입금
	void OutputMoney();			//출금
	void RemoveAccount();		//계좌 삭제
	void TransferMoney();		//계좌 이체
};

