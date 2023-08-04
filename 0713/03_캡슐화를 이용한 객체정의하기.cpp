//03_ĸ��ȭ�� �̿��� ��ü �����ϱ�.
/*
- Account ��ü ����(�ɹ�����, �ɹ��Լ�==��� ����)
--------------------------------------
Account
--------------------------------------
int accnumber;	 // ���� ��ȣ
char name[20];   // �� �̸�
int  balance;	 // ���� �ܾ�
--------------------------------------
void inputmoney(int money);			//�����ܾ� = �����ܾ� + �Աݾ�;
void outputmoney(int money);		//�����ܾ� = �����ܾ� - ��ݾ�;
void print();						//���� �ڵ� ���� ���ó��....
----------------------------------------
* ��ü ������ ���ÿ� ���ϴ� ������ �ʱ�ȭ..
*/

#include <iostream>
using namespace std;
#include <conio.h>

struct Account
{
	int accnumber;	 // ���� ��ȣ
	char name[20];   // �� �̸�
	int  balance;	 // ���� �ܾ�

	void inputmoney(int money)
	{
		if (money <= 0)
			return;

		balance = balance + money;
	}

	void outputmoney(int money)
	{
		if (money <= 0)
			return;

		if (money > balance)
			return;

		balance = balance - money;
	}
	
	void print()
	{
		cout << "--------------------------------------------------" << endl;
		cout << "  [ ���¹�ȣ ] " << accnumber << endl;
		cout << "  [ ��    �� ] " << name << endl;
		cout << "  [ ��    �� ] " << balance << "��" << endl;
		cout << "--------------------------------------------------" << endl;
	}
};

int main()
{
	Account  acc = { 1111, "ȫ�浿", 1000 };

	while (true)
	{
		system("cls");
		acc.print();
		cout << "*******************************************************" << endl;
		cout << "[0] ���α׷� ����" << endl;
		cout << "[1] �Ա� [2] ���" << endl;
		cout << "*******************************************************" << endl;
		switch (_getch())	//#include <conio.h>
		{
		case '0':  return 0;
		case '1':
		{
					int money;
					cout << "�Աݾ� : ";	cin >> money;
					acc.inputmoney(money);
					break;
		}
		case '2':
		{
					int money;
					cout << "��ݾ� : ";	cin >> money;
					acc.outputmoney(money);
					break;
		}
			//system("pause");
		}
	}

	return 0;

}
