//16_추상클래스와 순수가상함수
/*
Add [num1, num2, result] [Cal, Print]
Sub [num1, num2, result] [Cal, Print]
Mul [num1, num2, result] [Cal, Print]
Div [num1, num2, result] [Cal, Print]
-> 누구나 부모가 될수 있다.

-> ParentCal 이라는 부모를 만들고 Add, Sub, Mul, Div를 자식으로 만들자!
-> Add, Sub, Mul, Div를 만들 때 부모로부터 물려받은 Cal, Print를 재정의하였다.
만약, 재정의를 실수로 하지 않게 되면? 부모의 메서드가 호출된다....
자식들은 반드시 재정의를 해야 하는 구조이다. ---> 상황2)
왜? 부모의 Cal, Print는 기능이 없다.
(처음부터ParentCal 객체는 만들 목적이 없었다.) --> 상황1)
(Add, Sub, Mul, Div를 만들다 보니 공통부분을 갖는 부모가 필요해 졌다.)

[순수가상함수 / 추상클래스]
순수가상함수 : virtual, 순수(구현부가 없는 함수)
- virtual void foo() = 0;
-> 자식 클래스에 의해 반드시 재정의가 되어야 한다.
-> 자식 클래스가 순수가상함수를 재정의 안하면?? --> 자식도 추상 클래스가 된다.
추상클래스(미완성클래스) : 맴버로 순수가상함수를 갖고 있으면.
-> 객체 생성이 불가능!
*/
#include <iostream>
using namespace std;

//추상클래스(객체 생성이 불가능!)
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
	virtual void cal() = 0;			//순수가상함수
	virtual void Print() = 0;	    //순수가상함수
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
	Sub(int _num1, int _num2) : ParentCal(_num1, _num2) {  }  //<-- cal() 제외.......
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
	//	ParentCal p(10, 20);		//객체 생성 불가(왜? 추상클래스이기때문에)

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
