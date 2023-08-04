//01_열거형.cpp
// 사용자 정의 데이터 타입
// struct ( 비트필드 구조체 )
// union  ( 공용체 ) - 모든 맴버들이 같은 메모리를 사용
// enum   ( 열거형 ) - 미리 해당 타입에 저장될 값(정수)들을 결정해 놓는다.
//					 - 목적 : 가독성
//C++언어의 문법
// 1. enum 타입에 대해 형식의 안전성 보장...문법 개선..
// 2. struct, union, enum 타입을 정의할 때 태그가 타입명이 된다.... 편리성 개선.....
#include <iostream>
using std::cout;
using std::endl;

//타입명 : enum gender
//무었을? : FEMAIL, MAIL
//크기   :  sizeof(int)
enum gender { FEMAIL, MAIL };  //FEMAIL = 0, MAIL = 1

void exam1()
{
	enum gender g1; 
	g1 = FEMAIL;			
	//g1 = 0;  //C언어에서는 가능한 문법... C++언어에서는 금지!!!!???????
	//위 코드가 허용된다면 아래 코드도 문법적으로 가능해 진다.
	//g1 = 100;
	cout << g1 << endl;		//0

	g1 = MAIL;
	cout << g1 << endl;		//1
}


//임의의 정수로 설정할 수 있다.
enum mytype { TYPE1, TYPE2 = 3, TYPE3, TYPE4=7 };  // 0, 3, 4, 7

void exam2()
{
	enum mytype t1;
	mytype t2; 
}

int main()
{
	exam2();

	return 0;
}