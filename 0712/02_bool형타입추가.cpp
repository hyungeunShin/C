//02_bool�� Ÿ�� �߰�
/*
bool : true, false�� �����ϴ� Ÿ��
- �Ʒ��� C���� 100% ������ �ĺ��� ��� ���� - 
����
����
�Ǽ�
*/
#include <iostream>		
using std::cout;
using std::endl;

int main()
{
	bool  b1;		// 0(����) or 1(���� ��ǥ�ϴ� ����)�� �����ϴ� Ÿ��
	b1 = true;
	cout << b1 << endl;

	b1 = false;
	cout << b1 << endl;

	//�Ʒ� ����� �����ϴ� ����� �ƴϴ�...
	b1 = 1;				//OK
	cout << b1 << endl;

	b1 = 2;				//����(�߸��� �� ����)
	cout << b1 << endl;	// 1

	return 0;
}
