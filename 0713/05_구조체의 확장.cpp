//05_����ü�� Ȯ��

/*
[struct]
C�� ����ü    : �ɹ��� ������ ����
C++�� ����ü  : �ɹ��� ���� + �Լ� ���� ==> ĸ��ȭ ����(��ü ����) 
                �⺻ ���� �����ڰ� public
[class]
C++�� Ŭ����  : ��ü�� �����ϴ� ����(�ɹ��� ���� + �Լ�)
                �⺻ ���� �����ڰ� private 
*/
#include <iostream>
using namespace std;

struct sample_s
{
	int num;
};

class sample_c
{
private:
	int num;
};

int main()
{
	sample_s  s1 = { 10 };	
//	sample_c  c1 = { 10 };   // �����ʹ� ������ �Ǿ�� �ϱ� ������ ���̻� 
							// �̷� ����� �ʱ�ȭ�� ����� �� ����.
	return 0;
}