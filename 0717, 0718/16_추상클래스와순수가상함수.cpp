//16_�߻�Ŭ������ ���������Լ�
/*
Add [num1, num2, result] [Cal, Print]
Sub [num1, num2, result] [Cal, Print]
Mul [num1, num2, result] [Cal, Print]
Div [num1, num2, result] [Cal, Print]
-> ������ �θ� �ɼ� �ִ�.

-> ParentCal �̶�� �θ� ����� Add, Sub, Mul, Div�� �ڽ����� ������!
-> Add, Sub, Mul, Div�� ���� �� �θ�κ��� �������� Cal, Print�� �������Ͽ���.
����, �����Ǹ� �Ǽ��� ���� �ʰ� �Ǹ�? �θ��� �޼��尡 ȣ��ȴ�....
�ڽĵ��� �ݵ�� �����Ǹ� �ؾ� �ϴ� �����̴�. ---> ��Ȳ2)
��? �θ��� Cal, Print�� ����� ����.
(ó������ParentCal ��ü�� ���� ������ ������.) --> ��Ȳ1)
(Add, Sub, Mul, Div�� ����� ���� ����κ��� ���� �θ� �ʿ��� ����.)

[���������Լ� / �߻�Ŭ����]
���������Լ� : virtual, ����(�����ΰ� ���� �Լ�)
- virtual void foo() = 0;
-> �ڽ� Ŭ������ ���� �ݵ�� �����ǰ� �Ǿ�� �Ѵ�.
-> �ڽ� Ŭ������ ���������Լ��� ������ ���ϸ�?? --> �ڽĵ� �߻� Ŭ������ �ȴ�.
�߻�Ŭ����(�̿ϼ�Ŭ����) : �ɹ��� ���������Լ��� ���� ������.
-> ��ü ������ �Ұ���!
*/
#include <iostream>
using namespace std;

//�߻�Ŭ����(��ü ������ �Ұ���!)
class ParentCal
{
protected:
	int num1;
	int num2;
	float result;

public:
	ParentCal(int _num1, int _num2) : num1(_num1), num2(_num2) 	{ }
	~ParentCal() {}

public:
	virtual void cal() = 0;			//���������Լ�
	virtual void Print() = 0;	    //���������Լ�
};

class Add : public ParentCal
{
public:
	Add(int _num1, int _num2) : ParentCal(_num1, _num2) { }
	~Add() {}

public:
	void cal()	{ result = (float)num1 + num2; }
	void Print(){ cout << num1 << " + " << num2 << " = " << result << endl; }
};

class Sub : public ParentCal
{
public:
	Sub(int _num1, int _num2) : ParentCal(_num1, _num2) {  }  //<-- cal() ����.......
	~Sub() {}

public:
	void cal()	{ result = (float)num1 - num2; }
	void Print(){ cout << num1 << " - " << num2 << " = " << result << endl; }
};

class Mul : public ParentCal
{
public:
	Mul(int _num1, int _num2) : ParentCal(_num1, _num2) {  }
	~Mul() {}

public:
	void cal()	{ result = (float)num1 * num2; }
	void Print(){ cout << num1 << " * " << num2 << " = " << result << endl; }
};

class Div : public ParentCal
{
public:
	Div(int _num1, int _num2) : ParentCal(_num1, _num2) {  }
	~Div() {}
public:
	void cal()	{ result = (float)num1 / num2; }
	void Print(){ cout << num1 << " / " << num2 << " = " << result << endl; }
};

int main()
{
	//	ParentCal p(10, 20);		//��ü ���� �Ұ�(��? �߻�Ŭ�����̱⶧����)

	//	Add add(10, 20);		add.Print();
	//	Sub sub(10, 20);		sub.Print();
	//	Mul mul(10, 20);		mul.Print();
	//	Div div(10, 20);		div.Print();

	//	ParentCal *p1 = new Add(10, 20);
	//	p1->cal();
	//	p1->Print();

	ParentCal* *plist = new ParentCal*[4];
	plist[0] = new Add(10, 20);
	plist[1] = new Sub(10, 20);
	plist[2] = new Mul(10, 20);
	plist[3] = new Div(10, 20);

	for (int i = 0; i < 4; i++)
	{
		plist[i]->cal();
		plist[i]->Print();
	}


	return 0;
}
