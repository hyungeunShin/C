//00_�⺻ �����.cpp

//C��� �⺻ �ڵ带 C++ �����Ϸ��� �����ϰ� ������ �Ѵ�.
/*
#include <stdio.h>		//c����� IO�Լ����� �����.

int main()
{
	printf("Hello, World!\n");

	return 0;
}
*/

//C++�ڵ�� ����ó��
#include <iostream>		//c++����� �⺻ h����,    .h�� ���� ��(���� ���̺귯�� h�� include����)
						// Ư�� ����(1998��?)�� �������� ���̺귯�� ǥ��ó���� �־���.
using std::cout;
using std::endl;

int main()
{
	std::cout;
	cout << "Hello, World!\n\n" << endl; 
	//����1) std::cout << "Hello, World!";
	//����2) std::cout << std::endl;      : std::endl;  "\n" + fflush(stdout)

	return 0;
}
