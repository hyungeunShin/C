//06_������
/*
�� ���� : ��ü �ʱ�ȭ(������ ���ÿ� �ɹ������� ���� �ʱ�ȭ)

Ư¡ : Ư���� ������ �ɹ� �Լ�
       ��ü�� ������ �� �ڵ����� ȣ��ȴ�.(���� ���� ȣ���� �� ���� �Լ�)

���� : ������ ����.
       �Լ��� �̸��� ��ӵǾ� �ִ�. : Ŭ������� ���� 
	   �Ű����� ����Ʈ�� �Ϲ� �Լ�ó�� ����� �� �ִ�. 

-> �����ڴ� ��ӵ� ����� ���� �ִ�. 
   ��ü ������ [�ݵ��] �ڵ����� ȣ��Ǿ� ��ü�� �ʱ�ȭ�ϴ� ������ �����Ѵ�.
*/
#include <iostream>
using namespace std;

class sample
{
	//�ɹ� ����(�ʵ�)
private:
	int number;
	char ch;
	char str[20];

	//������
public:
	sample(int n, char c, const char* s)
	{
		cout << "sample(int, char, const char*)" << endl; 
		number = n;
		ch = c;
		strcpy_s(str, sizeof(str), s);
	}
};

int main()
{
	//��ü ���� -> [�ݵ��] ������ ȣ�� �߻�!!!!!!
	sample s1(10, 'A', "test");

	return 0;
}