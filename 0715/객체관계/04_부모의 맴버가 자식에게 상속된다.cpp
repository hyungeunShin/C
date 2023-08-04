//04_부모의 맴버가 자식에게 상속된다.
/*
[부모의 맴버변수와 맴버함수가 자식에게 상속된다.]
[생성자, 소멸자는 상속 대상이 아니다.]
*/
#include <iostream>
using namespace std;

class Parent
{
	string name;		//28byte
	int age;			//4byte
public:
	void foo() { cout << "Parent::foo()" << endl; }
};

class Child : public Parent
{
	string univer;		//28byte
public:
	void woo() { cout << "Parent::woo()" << endl; }
};

int main()
{
	//Parent 객체의 크기
	cout << sizeof(Parent) << endl;		//32byte
	cout << sizeof(Child) << endl;		//60byte

	Child child;
	child.foo();
	child.woo();

	return 0;
}