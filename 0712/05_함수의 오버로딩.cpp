//05_�Լ��� �����ε�
#include <iostream>
using std::cout;
using std::endl;

//���� ����� ��ȯ�ϴ� �Լ�(������, �Ǽ���)
//C����� 
int exam1_add(int n1, int n2)			{ return n1 + n2;  }
float exam1_add1(float n1, float n2)	{ return n1 + n2;  }

void exam1()
{
	cout << exam1_add(10, 20) << endl;			// cout << 30 << endl; 
	cout << exam1_add1(10.1f, 20.2f) << endl;  // cout << 30.3 << endl; 
}

//c++�����?
//������ �̸��� ���� �Լ��� ������ ����!(������ ����̶�� �����ϰ� ���Ǿ�� �Ѵ�.)
//�̸� ����� ������ �Լ��� �����ε��̴�.
//�Լ��� �����ε� : �Լ��� �� + �Ű����� ����Ʈ -> �Լ��� �ĺ���:�ż����
int		exam2_add(int n1, int n2)			{ return n1 + n2; }	//1
float	exam2_add(float n1, float n2)		{ return n1 + n2; }	//2

void exam2()
{
	cout << exam2_add(10, 20)		<< endl;  //1) cout << 30 << endl; 
	cout << exam2_add(10.1f, 20.2f) << endl;  //2) cout << 30.3 << endl; 
}

int main()
{
	exam2();

	return 0;
}