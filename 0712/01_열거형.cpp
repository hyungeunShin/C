//01_������.cpp
// ����� ���� ������ Ÿ��
// struct ( ��Ʈ�ʵ� ����ü )
// union  ( ����ü ) - ��� �ɹ����� ���� �޸𸮸� ���
// enum   ( ������ ) - �̸� �ش� Ÿ�Կ� ����� ��(����)���� ������ ���´�.
//					 - ���� : ������
//C++����� ����
// 1. enum Ÿ�Կ� ���� ������ ������ ����...���� ����..
// 2. struct, union, enum Ÿ���� ������ �� �±װ� Ÿ�Ը��� �ȴ�.... ���� ����.....
#include <iostream>
using std::cout;
using std::endl;

//Ÿ�Ը� : enum gender
//������? : FEMAIL, MAIL
//ũ��   :  sizeof(int)
enum gender { FEMAIL, MAIL };  //FEMAIL = 0, MAIL = 1

void exam1()
{
	enum gender g1; 
	g1 = FEMAIL;			
	//g1 = 0;  //C������ ������ ����... C++������ ����!!!!???????
	//�� �ڵ尡 ���ȴٸ� �Ʒ� �ڵ嵵 ���������� ������ ����.
	//g1 = 100;
	cout << g1 << endl;		//0

	g1 = MAIL;
	cout << g1 << endl;		//1
}


//������ ������ ������ �� �ִ�.
enum mytype { TYPE1, TYPE2 = 3, TYPE3, TYPE4=7 };  // 0, 3, 4, 7

void exam2()
{
	enum mytype t1;
	mytype t2; 
}

int main()
{
	exam2();

	return 0;
}