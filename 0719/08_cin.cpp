//08_cin�� ������ ����ȯ
#include <iostream>
using namespace std;

int getInt(const char* msg)
{
	int number;

	while (true)
	{
		cout << msg << " : ";
		cin >> number;
		if (cin)	//��������<---------------------------
			break;
		else
		{				
			cin.clear(); ////cin��ü�� �ʱ�ȭ
			cin.ignore(); //���� ����ֱ�
		}
	}
	return number;
}

int main()
{
	int number = getInt("���� �Է�");
	cout << number << endl;
	return 0;
}