//10_�Ļ��� ���� ������ ó��

#include <iostream>
using namespace std;

class Parent
{
private:
	void private_foo() {}
protected:
	void protected_foo() {}
public:
	void public_foo()  {}
};

class Child : public Parent
{
	//�θ��� privet -> private
	//�θ��� protected -> protected
	//�θ��� public ->public ���� ��ӵȴ�.
};

//�θ�� ���� �������� �� �������� protected����
class Child1 : protected Parent		 
{
	//�θ��� privet		-> private
	//�θ��� protected  -> protected
	//�θ��� public		-> protected ���� ��ӵȴ�.
};

//�θ�� ���� �������� �� �������� private����
class Child2 : private Parent
{
	//�θ��� privet		-> private
	//�θ��� protected  -> private
	//�θ��� public		-> private ���� ��ӵȴ�.
};

int main()
{
	//public ����ϰ� �Ǹ� ��ӵ� 3���� �޼��� �� public_foo()�� �ܺο��� ��밡��
	Child c1;
	c1.public_foo();	

	//��� ȣ�� �Ұ���.
	Child1 c2;

	//��� ȣ�� �Ұ���
	Child2 c3;

}