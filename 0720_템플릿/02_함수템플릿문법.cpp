//02_함수 템플릿 문법

#include <iostream>
using namespace std;

template<typename T>
T myadd(T n1, T n2, T n3)
{
	return n1 + n2 + n3;
}

template<typename T1, typename T2>
T1 mysub(T1 n1, T2 n2, T2 n3)
{
	return n1 - n2 - n3;
}

int main()
{
	//함수 템플릿을 호출!!!
	//1. 암시적 호출방식
	cout << myadd(10, 20, 30) << endl;			// T -> int
	cout << myadd(10.1, 20.2, 30.3) << endl;	// T -> double

	cout << mysub(10.1, 20, 10) << endl;		// T1 -> doube, T2 -> int

	//2. 명시적 호출방식
	cout << myadd<int>(10, 20, 30) << endl;					// T -> int
	cout << myadd<double>(10.1, 20.2, 30.3) << endl;		// T -> double

	cout << mysub<double, int>(10.1, 20, 10) << endl;		// T1 -> doube, T2 -> int
}