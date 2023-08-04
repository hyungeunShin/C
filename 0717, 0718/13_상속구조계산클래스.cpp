//13_��ӱ������Ŭ����
#include <iostream>
using namespace std;

class Add
{
protected:
	int num1;
	int num2;
	float result;

public:
	Add(int _num1, int _num2) : num1(_num1), num2(_num2), result(0.0f) 	{	}
	~Add() {}

public:  //�ʿ��� ��� ����!!!
	int get_num1() const			{ return num1; }
	int get_num2() const			{ return num2; }
	float get_result() const		{ return result; }
	void set_num1(int value)		{ num1 = value; }
	void set_num2(int value)		{ num2 = value; }
	void set_result(float value)	{ result = value; }

public:
	void cal()
	{
		result = (float)num1 + num2;
	}
	void Print()
	{
		cout << num1 << " + " << num2 << " = " << result << endl;
	}
};

class Sub : public Add
{
public:
	Sub(int _num1, int _num2) : Add(_num1, _num2) {}
	~Sub() {}

public:  //�ʿ��� ��� ����!!!

public:
	void cal()
	{
		result = (float)num1 - num2;
	}
	void Print()
	{
		cout << num1 << " - " << num2 << " = " << result << endl;
	}
};

class Mul : public Add
{
public:
	Mul(int _num1, int _num2) : Add(_num1, _num2) {}
	~Mul() {}

public:  //�ʿ��� ��� ����!!!

public:
	void cal()
	{
		result = (float)num1 * num2;
	}
	void Print()
	{
		cout << num1 << " * " << num2 << " = " << result << endl;
	}
};

class Div : public Add
{
public:
	Div(int _num1, int _num2) : Add(_num1, _num2) {}
	~Div() {}

public:  //�ʿ��� ��� ����!!!

public:
	void cal()
	{
		result = (float)num1 / num2;
	}
	void Print()
	{
		cout << num1 << " / " << num2 << " = " << result << endl;
	}
};


int main()
{
	Add add(10, 20);		add.cal();		add.Print();
	Sub sub(10, 20);		sub.cal();		sub.Print();
	Mul mul(10, 20);		mul.cal();		mul.Print();
	Div div(10, 20);		div.cal();		div.Print();

	return 0;
}
