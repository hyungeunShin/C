//07_�����޸� new / delete

#include <iostream>
using namespace std;

//C���
void exam1()
{
	//stack : p1�� ����
	//heap  : ���� 1�� ������ ������ ����
	int *p1 = (int*)malloc(sizeof(int));

	*p1 = 10;
	*p1 = 20;

	free(p1);

	//stack : p2�� ����
	//headp : ���� 10�� ������ ������ ���� --> 10¥�� �迭�� ����!
	int *p2 = (int*)malloc(sizeof(int)* 10);

	p2[0] = 10;
	p2[1] = 20;
	p2[9] = 30;

	free(p2);
}

//C++���
//[�����Ϸ��� �������� �߿��� ���� � ���� �� Ÿ�� ]
//int* p1; //�ּҸ� ���󰡸� ������ �ִ�.
void exam2()
{
	//stack : p1
	//heap  : int ������� 1�� ����, ������
	int *p1 = new int;

	cout << *p1 << endl; 
	*p1 = 1;
	cout << *p1 << endl; 

	delete p1;   //���޸� ���� �䱸 �ڵ� : 4byte�� ���� -> 4byte����.

	//stack : p2
	//headp : int ������� 1�� ����, 10���� �ʱ�ȭ!!!!!!
	int *p2 = new int(10);

	cout << *p2 << endl; 

	delete p2;

	//stack : p3
	//headp : int ������� 10�� ����, ������...
	int *p3 = new int[10];

	p3[0] = 10;
	p3[1] = 20;
	p3[9] = 30;

//	delete p3; // �߸��� ��� ��. ���޸��� 4byte�� ���� ó��...
	delete[] p3;  //p3�� �迭�� �ּ��̴�.....
}

int main()
{
	exam2();

	return 0;
}