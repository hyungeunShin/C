//06_�⺻�� �Ű�����.
//C++���� �ִ� ����

#include <iostream>
using std::cout;
using std::endl;

//�Լ� ȣ��� �Ű������� �����Ǵ� ���� ���� ���� ��� �⺻������ �ʱ�ȭ �ȴ�.
void exam1_fun1(int n1, int n2 = 10, char ch = 'X')
{
	cout << n1 << ", " << n2 << ", " << ch << endl;  //6��(<<)�� printf�� ȣ��!
}

void exam1()
{
	exam1_fun1(1, 2, 'A');	//1, 2, 'A'

	exam1_fun1(1, 2);		//1, 2, 'X' 

	exam1_fun1(1);			//1, 10, 'X'
}

//�Լ� ȣ��� �Ű����� ������ �ݵ�� ù��° ���ں��� ���������� ���޵ȴ�.
//�׷��� ������ �⺻���� ������ �Ű��������� ä������.
void exam2_fun1(int n1=10, int n2, char ch)  //�׷��� error�̴�.
{
	cout << n1 << ", " << n2 << ", " << ch << endl;  //6��(<<)�� printf�� ȣ��!
}

void exam2()
{
	exam2_fun1(1, 2, 'A');
}

int main()
{
	exam2();
	return 0;
}