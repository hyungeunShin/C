//08_생성자예제(지금까지 배운 내용...)
/*
계좌를 아래와 같이 정의하겠다.
이름 : Account
맴버변수 : int accnumber , char name[20],  int balance
맴버함수 : void inputmoney(int money),  void print()
*조건
 객체 생성은 2가지 방법이 가능하도록 구현
 1) 계좌번호와 이름으로 객체 생성할 수 있어야 한다. 단 이때 잔액은 0으로 초기화
 2) 계좌번호, 이름, 입금액으로 객체를 생성할 수 있어야 한다.
*/

#include <iostream>
using namespace std;
#include <conio.h>

class Account
{
	//맴버 변수
private:
	int accnumber;
	char name[20];
	int balance;

	//생성자
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

	//맴버 함수 
public:
	void inputmoney(int money)
	{
		balance = balance + money;
	}

	void print()
	{
		cout << accnumber << "\t";
		cout << name << "\t";
		cout << balance << "원" << endl; 
	}
};


int main()
{
	Account  acc1(1111, "홍길동", 1000);  //2번째 생성자가 호출!

	while (true)
	{
		system("cls");
		acc1.print();
		cout << "*******************************************************" << endl;
		cout << "[0] 프로그램 종료" << endl;
		cout << "[1] 입금" << endl;
		cout << "*******************************************************" << endl;
		switch (_getch())	//#include <conio.h>
		{
		case '0':  return 0;
		case '1':
		{
					int money;
					cout << "입금액 : ";	cin >> money;
					acc1.inputmoney(money);
					break;
		}		
			//system("pause");
		}
	}

	return 0;
}

