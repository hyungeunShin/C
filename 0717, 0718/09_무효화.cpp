//09_��ȿȭ
#include <iostream>
using namespace std;

//1) ���� �ڵ�
/*
class Parent
{
//�����ε�
public:
void foo()		{ cout << "Parent::foo()" << endl; }
void foo(int)	{ cout << "Parent::foo(int)" << endl;  }
};

class Child : public Parent
{
//�θ�κ��� �����ε��� 2���� �޼��带 �����޾Ҵ�.
};

int main()
{
Child c1;
c1.foo();
c1.foo(10);
}
*/

//2) �θ�� ���� �������� �����ε� ������ �޼��尡 �ְ�
//   �ڽ��� �������� �����ε� ������ �Լ��� �����ϰ� ����
//   -> ��ȿȭ
/*
class Parent
{
	//�����ε�
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
	//�θ�� ���� �������� �����ε� �Լ��� ��ȿȭ�� �߻�!
//	c1.foo();
//	c1.foo(10);
}
*/


//3) ��� : �����ε� ������ �ż��带 �ڽ��� �ٽ� �����ϰ� �Ǹ�
//          ��ȿȭ�� �߻��ϱ� ������ ��� �����ǰ� �ʿ��ϴ�.
class Parent
{
	//�����ε�
public:
	void foo()		{ cout << "Parent::foo()" << endl; }
	void foo(int)	{ cout << "Parent::foo(int)" << endl; }
};

class Child : public Parent
{
public:
	//�ʿ信 ���ؼ� string�� ���޹޴� �Լ��� �߰��ߴ�.
	//�������� �Լ����� ��ȿȭ �Ǿ���.
	void foo(string s) { cout << "Child::foo(string)" << endl; }
	//��ȿȭ�� �Լ����� ����ϰ� �ʹٸ� �Ʒ� �ڵ带 �߰��ϸ� �ȴ�.
	//�ٽ� ǥ��)��ȿȭ�� �Լ����� ����ϰ� �ʹٸ� �������̵� �ϸ� �ȴ�.
	//          �׸��� �� ���ο��� �θ��� �Լ��� ȣ���Ѵ�.
	void foo()			{ Parent::foo(); }
	void foo(int n)		{ Parent::foo(n); }
};

int main()
{
	Child c1;
	//�θ�� ���� �������� �����ε� �Լ��� ��ȿȭ�� �߻�!
	c1.foo();			//�ڽ��� ���� �θ� ���� �޼���
	c1.foo(10);			//�ڽ��� ���� �θ� ���� �޼���
	c1.foo("string");	//�ڽ��� ���� �޼���	
}