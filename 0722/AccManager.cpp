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
		delete base[i];		//힙메모리에 생성된 객체를 소멸
		base[i] = NULL;		//배열의 주소를 NULL로 변경	
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
			throw "동일한 번호가 존재합니다.";
	}
}

void AccManager::AddAccount()
{
	try
	{
		cout << endl;
		cout << "계좌번호 번호를 입력하세요: ";
		int number = ehglobal::getnum();
		Exist(number);		//계좌번호가 존재한다면 예외를 발생!

		cout << "이름을 입력하세요 : ";
		string name = ehglobal::getstr();

		cout << "입금액을 입력하세요: ";
		int money = ehglobal::getnum();

		Account* pacc = new Account(number, name, money);

		base.push_back(pacc);			//<-- 0번째부터 순차적으로 저장!

		AddAccList(number, money, 0, money);		//<---거래 내역 저장1)

		cout << "저장 성공" << endl;
	}
	catch (const char* msg)
	{
		cout << ">> 입력 에러 : " << msg << endl;
	}
}

void AccManager::ListAll()
{
	for (int i = 0; i< (int)base.size(); i++)
	{
		Account *pacc = base[i];
		if (pacc != NULL) //실제 학생이 보관되었는지 확인
			pacc->Print();
	}
}

void AccManager::SearchAccountById()
{
	try
	{
		cout << "검색할 계좌번호를 입력하세요: ";
		int accid = ehglobal::getnum();

		CompareById sbn(accid);		//stu.h참조 --> Account 구현[CompareById]
		vector<Account*>::iterator itr =
			find_if(base.begin(), base.end(), sbn);   //#include <algorithm>
		if (itr == base.end())
			throw "해당 계좌번호는 존재하지 않습니다.";

		Account* pacc = *itr;
		pacc->Println();

		PrintAccList(accid);  //<--------------- 거래 내역 출력!!!!!!!!!!!!!!!!
	}
	catch (const char* msg)
	{
		cout << "검색 에러 : " << msg << endl;
	}
}

void AccManager::InputMoney(int accid, int money)
{
	CompareById sbn(accid);		//stu.h참조 --> Account 구현[CompareById]
	vector<Account*>::iterator itr =
		find_if(base.begin(), base.end(), sbn);   //#include <algorithm>
	if (itr == base.end())
		throw "해당 계좌번호는 존재하지 않습니다.";

	Account* pacc = *itr;
	pacc->InputMoney(money);

	AddAccList(accid, money, 0, pacc->get_balance());		//<---거래 내역 저장2)
}

void AccManager::InputMoney()
{
	try
	{
		cout << "입금할 계좌번호를 입력하세요: ";
		int accid = ehglobal::getnum();

		cout << "입금액을 입력하세요: ";
		int money = ehglobal::getnum();

		InputMoney(accid, money);	//오류나면 throw		

		cout << "입금되었습니다." << endl;
	}
	catch (const char* msg)
	{
		cout << "입금 에러 : " << msg << endl;
	}
}

void AccManager::OutputMoney(int accid, int money)
{
	CompareById sbn(accid);		//stu.h참조 --> Account 구현[CompareById]
	vector<Account*>::iterator itr =
		find_if(base.begin(), base.end(), sbn);   //#include <algorithm>
	if (itr == base.end())
		throw "해당 계좌번호는 존재하지 않습니다.";

	Account* pacc = *itr;
	pacc->OutputMoney(money);

	AddAccList(accid, 0, money, pacc->get_balance());		//<---거래 내역 저장3)
}

void AccManager::OutputMoney()
{
	try
	{
		cout << "출금할 계좌번호를 입력하세요: ";
		int accid = ehglobal::getnum();

		cout << "출금액을 입력하세요: ";
		int money = ehglobal::getnum();

		OutputMoney(accid, money);	//오류 : throw

		cout << "출금되었습니다." << endl;
	}
	catch (const char* msg)
	{
		cout << "출금 에러 : " << msg << endl;
	}
}

void AccManager::RemoveAccount()
{
	try
	{
		cout << "계좌번호를 입력하세요: ";
		int accid = ehglobal::getnum();

		CompareById sbn(accid);
		vector<Account*>::iterator itr =
			find_if(base.begin(), base.end(), sbn);   //#include <algorithm>

		//힙에 생성된 STU객체는 직접 소멸처리
		Account* pacc = *itr;
		delete pacc;

		base.erase(itr);	//백터컨테이너에서 주소가 사라짐.!

		cout << "삭제 되었습니다." << endl;
	}
	catch (const char* msg)
	{
		cout << "삭제 에러 : " << msg << endl;
	}
}

void AccManager::TransferMoney()
{
	try
	{
		cout << "출금할 계좌번호를 입력하세요: ";
		int outputid = ehglobal::getnum();

		cout << "이체금액 입력하세요: ";
		int money = ehglobal::getnum();

		cout << "이체할 대상의 계좌번호를 입력하세요: ";
		int inputid = ehglobal::getnum();

		OutputMoney(outputid, money);
		InputMoney(inputid, money);

		cout << "이체되었습니다." << endl;
	}
	catch (const char* msg)
	{
		cout << "출금 에러 : " << msg << endl;
	}
}

void AccManager::AddAccList(int accid, int input, int output, int balance)
{
	AccList *plist = new AccList(accid, input, output, balance);

	baselist.push_back(plist);

	cout << "거래 내역이 저장되었습니다." << endl;
}

void AccManager::PrintAccList(int accid)
{
	cout << "\n[거래 내역]" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "계좌번호\t일자\t시간\t입금\t출금\t잔액" << endl;
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
