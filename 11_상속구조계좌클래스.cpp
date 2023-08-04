//11_��ӱ�������Ŭ����
#include <iostream>
using namespace std;

//[�ɹ��ʵ�], [������&�Ҹ���], [get&set], [���method...]
class Account
{
private:
	int id;			//���¹�ȣ
	string name;	//�̸�	
	int balance;	//�ܾ�

public:
	Account(int _id, string _name) 
		: id(_id), name(_name), balance(0) {}
	Account(int _id, string _name, int _balance) 
		: id(_id), name(_name), balance(_balance)  {}
	~Account() {}

public:  //�ʿ��� ��� ����!!!
	int get_id() const		{ return id;		}
	string get_name() const { return name;		}
	int get_balance() const { return balance;   }
	void set_id(int value)		{ id = value;		}	
	void set_name(string value) { name = value;		}
	void set_balance(int value) { balance = value;  }

public:
	void InputMoney(int money)
	{
		balance = balance + money;
	}
	void OutputMoney(int money)
	{
		balance = balance - money;
	}
	void Print()
	{
		cout << "[���¹�ȣ] " << id << "\t";
		cout << "[�̸�] " << name.c_str() << "\t";
		cout << "[�ܾ�] " << balance << "��" << "\t"; 
	}
};

//�������� ���� �Աݽ� ���ڰ� ���ԵǾ� �Ա�ó����.
class FaithAccount : public Account
{
private:
	float rate;		//������(0.1, 0.3)

public:
	FaithAccount(int id, string name)
	: Account(id, name), rate(0.1f){}

	FaithAccount(int id, string name, int balance, float _rate)
	: Account(id, name, (int)(balance + balance *_rate)) , rate(_rate) {}
	~FaithAccount() {}

public:

public:
	void InputMoney(int money)
	{
		int bal = (int)(money + money*rate);
		Account::InputMoney(bal);
	}

	void Print()
	{
		Account::Print();
		cout << "[������] " << rate << "%" << "\t";
	}

};

//�Աݽ� �ڵ����� 10%�� ��α��� ����
//��) 1000�� �Աݽ� -> ���� �Աݾ� : 900�� , 100�� ��α��Ѿ� �ջ�
class ContriAccount : public Account
{
private:
	int contribution;   //��α� �Ѿ� 

public:
	ContriAccount(int id, string name)
		: Account(id, name), contribution(0){}

	ContriAccount(int id, string name, int balance)
		: Account(id, name, (int)(balance - balance *0.1f)), 
		contribution((int)(balance *0.1f)) {}

	~ContriAccount() {}

public:

public:
	void InputMoney(int money)
	{
		int bal = (int)(money - money*0.1f);
		Account::InputMoney(bal);

		contribution = contribution + (int)(money*0.1f);
	}

	void Print()
	{
		Account::Print();
		cout << "[��α��Ѿ�] " << contribution << "��" << "\t";
	}
};


int main()
{
	Account acc(111, "ȫ�浿", 1000);  
	acc.Print();	cout << endl;

	acc.InputMoney(500);
	acc.Print();	cout << endl;

	acc.OutputMoney(700);
	acc.Print();	cout << endl;

	cout << endl << endl;
	FaithAccount acc1(222, "�̱浿", 1000, 0.1f);
	acc1.Print();	cout << endl;

	acc1.InputMoney(500);
	acc1.Print();	cout << endl;

	acc1.OutputMoney(700);
	acc1.Print();	cout << endl;


	cout << endl << endl;	
	ContriAccount acc2(222, "�̱浿", 1000);
	acc2.Print();	cout << endl;

	acc2.InputMoney(500);
	acc2.Print();	cout << endl;

	acc2.OutputMoney(700);
	acc2.Print();	cout << endl;

	return 0;
}
