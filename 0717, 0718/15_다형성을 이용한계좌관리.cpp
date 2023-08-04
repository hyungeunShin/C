//15_�������� �̿��� ���°���

#include <iostream>
using namespace std;

class Account
{
private:
	int id;			//���¹�ȣ
	string name;	//�̸�	
	int balance;	//�ܾ�

public:
	Account(int _id, string _name)	: id(_id), name(_name), balance(0) {}
	Account(int _id, string _name, int _balance): id(_id), name(_name), balance(_balance)  {}
	~Account() {}

public:  //�ʿ��� ��� ����!!!
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
	FaithAccount(int id, string name)	: Account(id, name), rate(0.1f){}

	FaithAccount(int id, string name, int balance, float _rate)	: Account(id, name, (int)(balance + balance *_rate)), rate(_rate) {}
	~FaithAccount() {}

public:

public:
	//������
	void InputMoney(int money)
	{
		int bal = (int)(money + money*rate);
		Account::InputMoney(bal);
	}
	//������
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
	ContriAccount(int id, string name)	: Account(id, name), contribution(0){}

	ContriAccount(int id, string name, int balance)	: Account(id, name, (int)(balance - balance *0.1f)),
		contribution((int)(balance *0.1f)) {}

	~ContriAccount() {}

public:

public:
	//������
	void InputMoney(int money)
	{
		int bal = (int)(money - money*0.1f);
		Account::InputMoney(bal);

		contribution = contribution + (int)(money*0.1f);
	}
	//������
	void Print()
	{
		Account::Print();
		cout << "[��α��Ѿ�] " << contribution << "��" << "\t";
	}
};


int main()
{
	//������ ���� ��ü�� ����!!!
	Account* *acc = new Account*[6]; //Account*�� 6�� �����ϴ� �迭 ����.

	//���� ���� ����
	acc[0] = new Account(111, "ȫ�浿", 1000);
	acc[1] = new FaithAccount(222, "�̱浿", 1000, 0.1f);
	acc[2] = new ContriAccount(333, "�ֱ浿", 1000);
	acc[3] = new Account(444, "��浿", 500);
	acc[4] = new FaithAccount(555, "���浿", 1000, 0.2f);
	acc[5] = new ContriAccount(666, "��浿", 2000);

	//������ü���
	for (int i = 0; i < 6; i++)
	{
		Account *p = acc[i];
		p->Print();
		cout << endl;
	}
	

	return 0;
}
