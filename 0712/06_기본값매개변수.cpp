//06_기본값 매개변수.
//C++언어에만 있는 문법

#include <iostream>
using std::cout;
using std::endl;

//함수 호출시 매개변수에 대응되는 값을 전달 안할 경우 기본값으로 초기화 된다.
void exam1_fun1(int n1, int n2 = 10, char ch = 'X')
{
	cout << n1 << ", " << n2 << ", " << ch << endl;  //6번(<<)의 printf가 호출!
}

void exam1()
{
	exam1_fun1(1, 2, 'A');	//1, 2, 'A'

	exam1_fun1(1, 2);		//1, 2, 'X' 

	exam1_fun1(1);			//1, 10, 'X'
}

//함수 호출시 매개변수 전달은 반드시 첫번째 인자부터 순차적으로 전달된다.
//그렇기 때문에 기본값은 마지막 매개변수부터 채워진다.
void exam2_fun1(int n1=10, int n2, char ch)  //그래서 error이다.
{
	cout << n1 << ", " << n2 << ", " << ch << endl;  //6번(<<)의 printf가 호출!
}

void exam2()
{
	exam2_fun1(1, 2, 'A');
}

int main()
{
	exam2();
	return 0;
}