//04_�θ��� �ɹ��� �ڽĿ��� ��ӵȴ�.
/*
[�θ��� �ɹ������� �ɹ��Լ��� �ڽĿ��� ��ӵȴ�.]
[������, �Ҹ��ڴ� ��� ����� �ƴϴ�.]
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
	//Parent ��ü�� ũ��
	cout << sizeof(Parent) << endl;		//32byte
	cout << sizeof(Child) << endl;		//60byte

	Child child;
	child.foo();
	child.woo();

	return 0;
}