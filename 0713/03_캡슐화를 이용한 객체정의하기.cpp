//03_캡슐화를 이용한 객체 정의하기.
/*
- Account 객체 정의(맴버변수, 맴버함수==기능 정의)
--------------------------------------
Account
--------------------------------------
int accnumber;	 // 계좌 번호
char name[20];   // 고객 이름
int  balance;	 // 계좌 잔액
--------------------------------------
void inputmoney(int money);			//계좌잔액 = 계좌잔액 + 입금액;
void outputmoney(int money);		//계좌잔액 = 계좌잔액 - 출금액;
void print();						//이전 코드 참조 출력처리....
----------------------------------------
* 객체 생성과 동시에 원하는 정보로 초기화..
*/

#include <iostream>
using namespace std;
#include <conio.h>

struct Account
{
	int accnumber;	 // 계좌 번호
	char name[20];   // 고객 이름
	int  balance;	 // 계좌 잔액

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
		cout << "  [ 계좌번호 ] " << accnumber << endl;
		cout << "  [ 이    름 ] " << name << endl;
		cout << "  [ 잔    액 ] " << balance << "원" << endl;
		cout << "--------------------------------------------------" << endl;
	}
};

int main()
{
	Account  acc = { 1111, "홍길동", 1000 };

	while (true)
	{
		system("cls");
		acc.print();
		cout << "*******************************************************" << endl;
		cout << "[0] 프로그램 종료" << endl;
		cout << "[1] 입금 [2] 출금" << endl;
		cout << "*******************************************************" << endl;
		switch (_getch())	//#include <conio.h>
		{
		case '0':  return 0;
		case '1':
		{
					int money;
					cout << "입금액 : ";	cin >> money;
					acc.inputmoney(money);
					break;
		}
		case '2':
		{
					int money;
					cout << "출금액 : ";	cin >> money;
					acc.outputmoney(money);
					break;
		}
			//system("pause");
		}
	}

	return 0;

}
