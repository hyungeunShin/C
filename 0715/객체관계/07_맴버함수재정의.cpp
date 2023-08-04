//07_�ɹ� �Լ� ������(Override)
/*
1) �����ε�   : �Լ��� �̸��� �����ϰ� �Ű����� ����Ʈ�� �ٸ� �Լ����� ����
2) �������̵� : ��Ӱ��迡�� �����ϴ� ����
                �θ�� ���� �������� �ɹ��Լ��� ������(����,�̸�,�Ű���������Ʈ �����ϰ�)
*/
#include <iostream>
using namespace std;

class Parent
{
public:
	void foo(int n) { cout << "Parent::foo(int)" << endl;  }
};

class Child : public Parent
{
public:
	//������(Override)
	void foo(int n) 
	{ 
		//�ڽ��� �޼��带 ȣ���ϴ� ����Լ� ����
		//foo(n);
		//�����ǵ� �θ��� �޼��带 ȣ��!!!!
		Parent::foo(n);

		cout << "Child::foo(int)" << endl; 
	}
};

int main()
{
	Child c1;
	c1.foo(10);		//�����ǰ� ���ٸ� �θ�κ��� �������� foo�� ȣ��
					//�������ߴٸ� �����ǵ� foo�� ȣ��
	return 0;
}