//15_다형성을 이용한 계좌관리

#include <iostream>
using namespace std;

class Account
{
private:
	int id;			//계좌번호
	string name;	//이름	
	int balance;	//잔액

public:
	Account(int _id, string _name)	: id(_id), name(_name), balance(0) {}
	Account(int _id, string _name, int _balance): id(_id), name(_name), balance(_balance)  {}
	~Account() {}

public:  //필요할 경우 제공!!!
	int get_id() const		{ return id; }
	string get_name() const { return name; }
	int get_balance() const { return balance; }
	void set_id(int value)		{ id = value; }
	void set_name(string value) { name = value; }
	void set_balance(int value) { balance = value; }

public:
	virtual void InputMoney(int money)
	{
		balance = balance + money;
	}
	void OutputMoney(int money)
	{
		balance = balance - money;
	}
	virtual void Print()
	{
		cout << "[계좌번호] " << id << "\t";
		cout << "[이름] " << name.c_str() << "\t";
		cout << "[잔액] " << balance << "원" << "\t";
	}
};

//이자율에 따라서 입금시 이자가 포함되어 입금처리됨.
class FaithAccount : public Account
{
private:
	float rate;		//이자율(0.1, 0.3)

public:
	FaithAccount(int id, string name)	: Account(id, name), rate(0.1f){}

	FaithAccount(int id, string name, int balance, float _rate)	: Account(id, name, (int)(balance + balance *_rate)), rate(_rate) {}
	~FaithAccount() {}

public:

public:
	//재정의
	void InputMoney(int money)
	{
		int bal = (int)(money + money*rate);
		Account::InputMoney(bal);
	}
	//재정의
	void Print()
	{
		Account::Print();
		cout << "[이자율] " << rate << "%" << "\t";
	}

};

//입금시 자동으로 10%의 기부금이 적립
//예) 1000원 입금시 -> 실제 입금액 : 900원 , 100원 기부금총액 합산
class ContriAccount : public Account
{
private:
	int contribution;   //기부금 총액 

public:
	ContriAccount(int id, string name)	: Account(id, name), contribution(0){}

	ContriAccount(int id, string name, int balance)	: Account(id, name, (int)(balance - balance *0.1f)),
		contribution((int)(balance *0.1f)) {}

	~ContriAccount() {}

public:

public:
	//재정의
	void InputMoney(int money)
	{
		int bal = (int)(money - money*0.1f);
		Account::InputMoney(bal);

		contribution = contribution + (int)(money*0.1f);
	}
	//재정의
	void Print()
	{
		Account::Print();
		cout << "[기부금총액] " << contribution << "원" << "\t";
	}
};


int main()
{
	//다형성 구조 개체를 관리!!!
	Account* *acc = new Account*[6]; //Account*를 6개 저장하는 배열 생성.

	//계좌 생성 저장
	acc[0] = new Account(111, "홍길동", 1000);
	acc[1] = new FaithAccount(222, "이길동", 1000, 0.1f);
	acc[2] = new ContriAccount(333, "최길동", 1000);
	acc[3] = new Account(444, "허길동", 500);
	acc[4] = new FaithAccount(555, "공길동", 1000, 0.2f);
	acc[5] = new ContriAccount(666, "김길동", 2000);

	//계좌전체출력
	for (int i = 0; i < 6; i++)
	{
		Account *p = acc[i];
		p->Print();
		cout << endl;
	}
	

	return 0;
}
