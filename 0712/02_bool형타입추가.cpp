//02_bool형 타입 추가
/*
bool : true, false를 저장하는 타입
- 아래는 C언어와 100% 동일한 식별자 기능 제공 - 
정수
문자
실수
*/
#include <iostream>		
using std::cout;
using std::endl;

int main()
{
	bool  b1;		// 0(거짓) or 1(참을 대표하는 숫자)을 저장하는 타입
	b1 = true;
	cout << b1 << endl;

	b1 = false;
	cout << b1 << endl;

	//아래 방식은 권장하는 방식이 아니다...
	b1 = 1;				//OK
	cout << b1 << endl;

	b1 = 2;				//워닝(잘못된 값 대입)
	cout << b1 << endl;	// 1

	return 0;
}
