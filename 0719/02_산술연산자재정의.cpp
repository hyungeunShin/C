//02_산술연산자 재정의

#include <iostream>
using namespace std;

class Complex		//복소수
{
private:
	int real; 
	int image; 

public:
	Complex(int r, int i) : real(r), image(i) {}

public:
	void Print() const { cout << real << "+" << image << "i" << endl; }

	Complex Add( const Complex & c) 
	{
		int r = real + c.real;
		int i = image + c.image;
		Complex temp(r, i);
		return temp;
	}
	Complex operator+(const Complex & c)
	{
		int r = real + c.real;
		int i = image + c.image;
		Complex temp(r, i);
		return temp;
	}
	Complex operator-(const Complex & c)
	{
		int r = real - c.real;
		int i = image - c.image;
		Complex temp(r, i);
		return temp;
	}
};

int main()
{
	//int n1 = 10; int n2 = 20;   int result = n1 + n2;
	Complex com1(1, 2);		com1.Print();
	Complex com2(2, 3);     com2.Print();

	Complex com3 = com1.Add(com2);			//com1과 com2의 합을 반환
	com3.Print();

	Complex com4 = com1 + com2;		// com1.operator+(com2);
	com4.Print();

	Complex com5 = com1 - com2;		//com1.operator-(com2);
	com5.Print();
	return 0;
}