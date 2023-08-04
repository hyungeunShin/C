//05_��ӱ������� ��ü ���� �帧
/*
1. �ڽİ�ü�� �����ϸ� �θ�ü�� ���� �����ǰ� �ڽİ�ü�� �����ȴ�.
2. �θ�ü�� ������ �� ���ڰ� ���� ����Ʈ �����ڰ� ȣ��ȴ�.
??? �θ� ���� �����ڰ� ������ �� ���� ���ϴ� �����ڸ� ȣ���� �� ������?  OK....
    [�ڽ� �������� �ݷ��ʱ�ȭ]���� ��������� �θ� �����ڸ� ������ �ϸ� �ȴ�.
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
//	Parent p1;			//[����] 1   [�Ҹ�] 2
//	Child c1;			//[����] 1,3  [�Ҹ�]4,2
	Child c2(10);		//[����] 1,5  [�Ҹ�]4,2

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
	//	Parent p1;			//[����] P1   [�Ҹ�] P3
	Child c1;			//[����] [p2],c1  [�Ҹ�] c3,p3
	Child c2(10);		//[����] p2,c2    [�Ҹ�]c3,p3

	return 0;
}