//01_���ø��̶�?
/*
2���� ���ڸ� �޾Ƽ� max�� ��ȯ�ϴ� �Լ�(int, char, float..)
���1) �����ε�
       �ʿ��� �Լ����� ���� ���� �����ϴ� ��
���2) �Լ����ø�(template, ���𰡸� ����� Ʋ) 
       �ʿ��� �Լ����� ����� ���� ����� �����Ϸ����� �˷� ��.
	   - �����Ϸ��� �ڵ带 �м��ؼ� �ʿ��� �Լ����� �����Ѵ�. 
*/

#include <iostream>
using namespace std;

//1. �����ε�
int max(int n1, int n2)		//[����] Ÿ�Ը� �ٸ��� �˰����� �����ϴ�.
{
	if (n1 > n2)
		return n1;
	else
		return n2;
}

char max(char n1, char n2)
{
	if (n1 > n2)
		return n1;
	else
		return n2;
}

float max(float n1, float n2)
{
	if (n1 > n2)
		return n1;
	else
		return n2;
}

//2. �Լ� ���ø�
template<typename T>			//template : ���ø��̴�.->Ʋ�̴�.
T min(T n1, T n2)				//typename T : T �ĺ��ڸ� ����(�������� ���� Ÿ��)
{								//             T�� � Ÿ�����ε� ��ȯ�� �� �� �ִ�.
	if (n1 > n2)
		return n2;
	else
		return n1;
}

int main()
{
	cout << max(10, 20) << endl;
	cout << max('a', 'A') << endl;
	cout << max(10.1f, 10.1f) << endl; 

	//�Ʒ��� ���ø��Լ��� ȣ���ϴ� �ڵ带 Ȱ���Ͽ�
	//3���� �����ε�� �Լ��� �����Ϸ��� �����.
	cout << min(10, 20) << endl; 
	cout << min('a', 'A') << endl;
	cout << min(10.1f, 10.1f) << endl;
	return 0;
}