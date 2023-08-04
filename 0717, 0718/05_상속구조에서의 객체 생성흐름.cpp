//05_상속구조에서 객체 생성 흐름
/*
1. 자식객체를 생성하면 부모객체가 먼저 생성되고 자식객체가 생성된다.
2. 부모객체가 생성될 때 인자가 없는 디폴트 생성자가 호출된다.
??? 부모가 여러 생성자가 존재할 때 내가 원하는 생성자를 호출할 수 있을까?  OK....
    [자식 생성자의 콜론초기화]에서 명시적으로 부모 생성자를 지정을 하면 된다.
*/
#include <iostream>
using namespace std;

/*
class Parent
{
public:
	Parent() { cout << "Parent()" << endl; }			//1
	Parent(int n) { cout << "Parent(int)" << endl;  }   //3

	~Parent() { cout << "~Parent()" << endl; }			//2
};

class Child : public Parent
{	
public:
	Child() { cout << "Child()" << endl; }			 //3
	Child(int n) { cout << "Child(int)" << endl; }   //5

	~Child() { cout << "~Child()" << endl; }		 //4
};


int main()
{
//	Parent p1;			//[생성] 1   [소멸] 2
//	Child c1;			//[생성] 1,3  [소멸]4,2
	Child c2(10);		//[생성] 1,5  [소멸]4,2

	return 0;
}
*/

class Parent
{
public:
	Parent() { cout << "Parent()" << endl; }			//P1
	Parent(int n) { cout << "Parent(int)" << endl; }    //P2

	~Parent() { cout << "~Parent()" << endl; }			//P3
};

class Child : public Parent
{
public:
	Child() : Parent(10)
	{ cout << "Child()" << endl; }			 //C1
	
	Child(int n) : Parent(n) 
	{ cout << "Child(int)" << endl; }   //C2

	~Child() { cout << "~Child()" << endl; }		 //C3
};


int main()
{
	//	Parent p1;			//[생성] P1   [소멸] P3
	Child c1;			//[생성] [p2],c1  [소멸] c3,p3
	Child c2(10);		//[생성] p2,c2    [소멸]c3,p3

	return 0;
}