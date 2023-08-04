//05_구조체의 확장

/*
[struct]
C의 구조체    : 맴버가 변수만 가능
C++의 구조체  : 맴버가 변수 + 함수 가능 ==> 캡슐화 구조(객체 정의) 
                기본 접근 지정자가 public
[class]
C++의 클래스  : 객체를 정의하는 문법(맴버가 변수 + 함수)
                기본 접근 지정자가 private 
*/
#include <iostream>
using namespace std;

struct sample_s
{
	int num;
};

class sample_c
{
private:
	int num;
};

int main()
{
	sample_s  s1 = { 10 };	
//	sample_c  c1 = { 10 };   // 데이터는 은닉이 되어야 하기 때문에 더이상 
							// 이런 방식의 초기화는 사용할 수 없다.
	return 0;
}