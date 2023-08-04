//09_무효화
#include <iostream>
using namespace std;

//1) 원본 코드
/*
class Parent
{
//오버로딩
public:
void foo()		{ cout << "Parent::foo()" << endl; }
void foo(int)	{ cout << "Parent::foo(int)" << endl;  }
};

class Child : public Parent
{
//부모로부터 오버로딩된 2개의 메서드를 물려받았다.
};

int main()
{
Child c1;
c1.foo();
c1.foo(10);
}
*/

//2) 부모로 부터 물려받은 오버로딩 구조의 메서드가 있고
//   자식이 물려받은 오버로딩 구조의 함수를 유사하게 정의
//   -> 무효화
/*
class Parent
{
	//오버로딩
public:
	void foo()		{ cout << "Parent::foo()" << endl; }
	void foo(int)	{ cout << "Parent::foo(int)" << endl; }
};

class Child : public Parent
{
public:
	void foo(string s) { cout << "Child::foo(string)" << endl; }
};

int main()
{
	Child c1;
	//부모로 부터 물려받은 오버로딩 함수의 무효화가 발생!
//	c1.foo();
//	c1.foo(10);
}
*/


//3) 결론 : 오버로딩 구조의 매서드를 자식이 다시 정의하게 되면
//          무효화가 발생하기 때문에 모두 재정의가 필요하다.
class Parent
{
	//오버로딩
public:
	void foo()		{ cout << "Parent::foo()" << endl; }
	void foo(int)	{ cout << "Parent::foo(int)" << endl; }
};

class Child : public Parent
{
public:
	//필요에 의해서 string을 전달받는 함수를 추가했다.
	//물려받은 함수들이 무효화 되었다.
	void foo(string s) { cout << "Child::foo(string)" << endl; }
	//무효화된 함수들을 사용하고 싶다면 아래 코드를 추가하면 된다.
	//다시 표현)무효화된 함수들을 사용하고 싶다면 오버라이딩 하면 된다.
	//          그리고 그 내부에서 부모의 함수를 호출한다.
	void foo()			{ Parent::foo(); }
	void foo(int n)		{ Parent::foo(n); }
};

int main()
{
	Child c1;
	//부모로 부터 물려받은 오버로딩 함수의 무효화가 발생!
	c1.foo();			//자식을 통해 부모가 만든 메서드
	c1.foo(10);			//자식을 통해 부모가 만든 메서드
	c1.foo("string");	//자식이 만든 메서드	
}