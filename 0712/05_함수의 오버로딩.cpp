//05_함수의 오버로딩
#include <iostream>
using std::cout;
using std::endl;

//합의 결과를 반환하는 함수(정수합, 실수합)
//C언어라면 
int exam1_add(int n1, int n2)			{ return n1 + n2;  }
float exam1_add1(float n1, float n2)	{ return n1 + n2;  }

void exam1()
{
	cout << exam1_add(10, 20) << endl;			// cout << 30 << endl; 
	cout << exam1_add1(10.1f, 20.2f) << endl;  // cout << 30.3 << endl; 
}

//c++언어라면?
//동일한 이름을 갖는 함수로 구성이 가능!(동일한 기능이라면 동일하게 사용되어야 한다.)
//이를 만드는 문법이 함수의 오버로딩이다.
//함수의 오버로딩 : 함수의 명 + 매개변수 리스트 -> 함수의 식별자:매서드명
int		exam2_add(int n1, int n2)			{ return n1 + n2; }	//1
float	exam2_add(float n1, float n2)		{ return n1 + n2; }	//2

void exam2()
{
	cout << exam2_add(10, 20)		<< endl;  //1) cout << 30 << endl; 
	cout << exam2_add(10.1f, 20.2f) << endl;  //2) cout << 30.3 << endl; 
}

int main()
{
	exam2();

	return 0;
}