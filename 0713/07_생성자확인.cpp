//07_������Ȯ��
/*
��ü�� ������ ��(�ݵ��)
1. �޸� ����(�ɹ� ����)
2. ������ ȣ��
*/

#include <iostream>
using namespace std;

class Sample
{
};

void exam1()
{
	Sample s1;	 //��ü ����
	//�ɹ� ������ ���� ������ �޸𸮴� �ּ� �޸��� 1byte ����(�����Ϸ���)
	//�����ڰ� ���� ������ ���ڰ� ���� �⺻�����ڸ� ����(�����Ϸ���)
	//[�����Ϸ��� ������ �ִ� �⺻ ������]
	// Sample() { } 
	cout << sizeof(s1) << endl;   // 1byte..
}


//�پ��� �������� ȣ�� ����
//�����ڴ� �����ε��� �����ϴ�.
class Sample1
{
	//2���� ������ -> ��ü�� �����ϴ� ����� 2������.
public:
	//Sample1() {}
	Sample1(int n1)				{ cout << "Sample(int)" << endl;		}
	Sample1(int n1, char ch)	{ cout << "Sample(int, char)" << endl;  }
};

void exam2()
{
//	Sample1 s0;			// ����...�����ڸ� ����� �����Ϸ��� ���̻� �⺻�����ڸ�
						//������ ���� �ʴ´�.
	Sample1 s1(10);
	Sample1 s2(10, 'A');
}

class Sample2
{
private:		//��������� ���� ���̰Բ�.
	int		number;
	char	c;

public:
	Sample2(int n1)				{ number = n1;    c = n1; }
	Sample2(int n1, char ch)	{ number = n1;    c = ch; }

public:
	void Print()
	{
		cout << number << ", " << c << endl; 
	}
};

void exam3()
{
	Sample2 s1(65);				// 1) 5byte �޸𸮰� ���� 2) �����ڸ� ȣ��->�ʱ�ȭ
	Sample2 s2(65, 'B');

	s1.Print();
	s2.Print();
}

int main()
{
	exam3();	

	return 0;
}


