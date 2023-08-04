//08_�����ڿ���(���ݱ��� ��� ����...)
/*
���¸� �Ʒ��� ���� �����ϰڴ�.
�̸� : Account
�ɹ����� : int accnumber , char name[20],  int balance
�ɹ��Լ� : void inputmoney(int money),  void print()
*����
 ��ü ������ 2���� ����� �����ϵ��� ����
 1) ���¹�ȣ�� �̸����� ��ü ������ �� �־�� �Ѵ�. �� �̶� �ܾ��� 0���� �ʱ�ȭ
 2) ���¹�ȣ, �̸�, �Աݾ����� ��ü�� ������ �� �־�� �Ѵ�.
*/

#include <iostream>
using namespace std;
#include <conio.h>

class Account
{
	//�ɹ� ����
private:
	int accnumber;
	char name[20];
	int balance;

	//������
public:
	Account(int _accnumber, const char*_name)
	{
		accnumber = _accnumber;
		strcpy_s(name, sizeof(name), _name);
		balance = 0;
	}

	Account(int _accnumber, const char*_name, int _balance)
	{
		accnumber = _accnumber;
		strcpy_s(name, sizeof(name), _name);
		balance = _balance;
	}

	//�ɹ� �Լ� 
public:
	void inputmoney(int money)
	{
		balance = balance + money;
	}

	void print()
	{
		cout << accnumber << "\t";
		cout << name << "\t";
		cout << balance << "��" << endl; 
	}
};


int main()
{
	Account  acc1(1111, "ȫ�浿", 1000);  //2��° �����ڰ� ȣ��!

	while (true)
	{
		system("cls");
		acc1.print();
		cout << "*******************************************************" << endl;
		cout << "[0] ���α׷� ����" << endl;
		cout << "[1] �Ա�" << endl;
		cout << "*******************************************************" << endl;
		switch (_getch())	//#include <conio.h>
		{
		case '0':  return 0;
		case '1':
		{
					int money;
					cout << "�Աݾ� : ";	cin >> money;
					acc1.inputmoney(money);
					break;
		}		
			//system("pause");
		}
	}

	return 0;
}

