//03_함수 템플릿문법
// 템플릿특수화(템플릿전문화)

// - [템플릿]동일한 알고리즘을 가지고 있다면 틀을 제공하여 컴파일러가 함수를 만들도록 한다.
// - 만약, 알고리즘이 다르다면????

#include <iostream>
using namespace std;

template<typename T>
bool myequals(T value1, T value2)
{
	return (value1 == value2);
}

//템플릿전문화
template<>
bool myequals(char* s1, char* s2)
{
	cout << "TEST" << endl;
	return (strcmp(s1, s2) == 0);
}

int main()
{
	cout << myequals(10, 20) << endl;			// 0
	cout << myequals<char>('A', 'A') << endl;	// 1

	float f1 = 10.1f;
	float f2 = 10.1f;
	cout << myequals(f1, f2) << endl;			// 1

	
	char str1[] = "aaa";
	char str2[] = "aaa";
	cout << myequals(str1,str2) << endl;		// 0
	return 0;
}
