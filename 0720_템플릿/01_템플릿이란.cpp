//01_템플릿이란?
/*
2개의 인자를 받아서 max를 반환하는 함수(int, char, float..)
방법1) 오버로드
       필요한 함수들을 내가 직접 정의하는 것
방법2) 함수템플릿(template, 무언가를 만드는 틀) 
       필요한 함수들을 만들어 내는 방법을 컴파일러에게 알려 줌.
	   - 컴파일러는 코드를 분석해서 필요한 함수들을 정의한다. 
*/

#include <iostream>
using namespace std;

//1. 오버로드
int max(int n1, int n2)		//[성질] 타입만 다르고 알고리즘이 동일하다.
{
	if (n1 > n2)
		return n1;
	else
		return n2;
}

char max(char n1, char n2)
{
	if (n1 > n2)
		return n1;
	else
		return n2;
}

float max(float n1, float n2)
{
	if (n1 > n2)
		return n1;
	else
		return n2;
}

//2. 함수 템플릿
template<typename T>			//template : 템플릿이다.->틀이다.
T min(T n1, T n2)				//typename T : T 식별자를 생성(정해지지 않은 타입)
{								//             T는 어떤 타입으로도 변환이 될 수 있다.
	if (n1 > n2)
		return n2;
	else
		return n1;
}

int main()
{
	cout << max(10, 20) << endl;
	cout << max('a', 'A') << endl;
	cout << max(10.1f, 10.1f) << endl; 

	//아래의 템플릿함수를 호출하는 코드를 활용하여
	//3개의 오버로드된 함수를 컴파일러가 만든다.
	cout << min(10, 20) << endl; 
	cout << min('a', 'A') << endl;
	cout << min(10.1f, 10.1f) << endl;
	return 0;
}