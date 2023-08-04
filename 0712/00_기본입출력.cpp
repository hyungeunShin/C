//00_기본 입출력.cpp

//C언어 기본 코드를 C++ 컴파일러도 동일하게 컴파일 한다.
/*
#include <stdio.h>		//c언어의 IO함수들의 선언부.

int main()
{
	printf("Hello, World!\n");

	return 0;
}
*/

//C++코드로 변경처리
#include <iostream>		//c++언어의 기본 h파일,    .h를 사용안 함(기존 라이브러리 h의 include차이)
						// 특정 연도(1998년?)를 기준으로 라이브러리 표준처리가 있었다.
using std::cout;
using std::endl;

int main()
{
	std::cout;
	cout << "Hello, World!\n\n" << endl; 
	//실행1) std::cout << "Hello, World!";
	//실행2) std::cout << std::endl;      : std::endl;  "\n" + fflush(stdout)

	return 0;
}
