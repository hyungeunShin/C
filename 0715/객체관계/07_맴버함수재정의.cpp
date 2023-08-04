//07_맴버 함수 재정의(Override)
/*
1) 오버로딩   : 함수의 이름은 동일하고 매개변수 리스트가 다른 함수들의 관계
2) 오버라이드 : 상속관계에서 존재하는 문법
                부모로 부터 물려받은 맴버함수를 재정의(리턴,이름,매개변수리스트 동일하게)
*/
#include <iostream>
using namespace std;

class Parent
{
public:
	void foo(int n) { cout << "Parent::foo(int)" << endl;  }
};

class Child : public Parent
{
public:
	//재정의(Override)
	void foo(int n) 
	{ 
		//자신의 메서드를 호출하는 재귀함수 구조
		//foo(n);
		//재정의된 부모의 메서드를 호출!!!!
		Parent::foo(n);

		cout << "Child::foo(int)" << endl; 
	}
};

int main()
{
	Child c1;
	c1.foo(10);		//재정의가 없다면 부모로부터 물려받은 foo를 호출
					//재정의했다면 재정의된 foo를 호출
	return 0;
}