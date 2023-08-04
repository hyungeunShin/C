//Account.h
#pragma once
class Account
{
private:
	int id;			//���¹�ȣ
	string name;	//�̸�	
	int balance;	//�ܾ�

public:
	Account(int _id, string _name);
	Account(int _id, string _name, int _balance);
	~Account();

public:
	int get_id() const		{ return id;  }
	string get_name() const { return name;  }

public:
	void InputMoney(int money);	void OutputMoney(int money);	void Print();
};

