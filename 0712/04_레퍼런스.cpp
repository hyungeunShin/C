//04_레퍼런스
/*
기존 변수에 붙는 별명
*/
#include <iostream>
using std::cout;		
using std::endl;
using std::cin;

//기존 변수에 붙는 별명(반드시 선언과 동시에 초기화)
void exam1()
{
	int number;					//지역 변수 
	int& r_number = number;		//레퍼런스(선언시 누구의 별명 처리)

	number = 10;
	cout << number << endl; //10
	cout << r_number << endl; //10

	r_number = 20;
	cout << number << endl;		//20
	cout << r_number << endl;	//20

	cout << &number << endl;	//주소출력(동일)
	cout << &r_number << endl;	//주소출력(동일)
}


/*
사용예1) 함수의 인자 전달
C언어
1) 값 전달(call by value)		: 값을 복사 
2) 주소 전달(call by address)	: 값의 주소를 전달해서 원본 변경!
C++ 하나가 더 추가됨
3) 참조자 전달(call by reference) : 2번 기능과 동일한 성질을 갖는다.
*/
void exam2_fun(int n1, int* pn2, int & n3)
{
	n1 = 20;
	*pn2 = 30;
	n3 = 40;
}

void exam2()
{
	int number = 10;
	exam2_fun(number, &number, number); //V, A, R

	cout << number << endl;  // 30 -> 40 
}


/*
사용예2) 참조자 반환
*/
int g_arr[5] = { 1, 2, 3, 4, 5 };  //전역변수

int getdata1_exam3(int idx)		{		return g_arr[idx];		}
int& getdata2_exam3(int idx)	{		return g_arr[idx];		}

void exam3()
{
	//함수의 호출은 대입연산의 R value에 있었다.
	int value;
	value = getdata1_exam3(1);		// value = 2;
	cout << value << endl;			// 2

	//getdata1_exam3(2) = value;		// 3 = 2;	// 상수 = 상수;
	//------------------------------------------------------------------------

	//만약 호출된 함수의 반환타입이 참조자라면 대입연산의 L value에도 사용이 가능하다.
	value = getdata2_exam3(1);		// value = g_arr[1]; --> value = 2;
	cout << value << endl;			// 2

	getdata2_exam3(2) = value;		// g_arr[2] = 2;	// 변수의공간 = 상수;
	cout << g_arr[2] << endl;		// 2
}


int main()
{
	exam3();
	return 0;
}