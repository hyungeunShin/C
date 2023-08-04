//06_STL(Standard Template Library)
/*
STL�� �����ϴ� �߿��� 3���� ���
1) Container( ������ ����� ) -> ���ø� Ŭ���� ���·� ����
2) Algorithm( �Լ� )          -> ���ø� �Լ� ���·� ����
3) iterator (���ͷ����� )     -> ����Ŭ���� ���·� ����, ������ ����Ҹ� ��ȸ�ϴ� ����
...
*/
#include <iostream>
#include <algorithm>		//STL�� �˰��� �Լ� ���
#include <functional>
#include <iterator>
#include <vector>
using namespace std;

//�˰���
void exam1()
{
	//�����̳�(�����͸� �����ϰ� ������)
	int arr[10] = { 4, 2, 6, 121, 5, 23, 65, 323, 31, 23 };

	//STL �˰��� �Լ�
	int*ret =  find<int*, int>(arr, arr + 10, 23);  //�Ϲ������δ� �Ͻ������
	if (ret == arr + 10)
		cout << "����" << endl;
	else
		cout << *ret << endl; 

	//STL �˰��� �Լ�
	sort(arr, arr + 10);

	//��ü ���
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl; 

	//STL �˰��� �Լ�
	copy(arr, arr + 10, ostream_iterator<int>(cout, "-")); //#include <iterator>
}

//�����̳�[�ڷᱸ��(�迭, ���Ḯ��Ʈ)]
//�迭 : vector

void exam2()
{
	vector<int> v1;		//int�� �����ϴ� �迭!!!! --> WbArray
	cout << "max : " << v1.capacity() << endl;		//0
	cout << "size : " << v1.size() << endl;			//0

	//�����͸� ���������� max���� size�� ��� ���������ش�.
	for (int i = 0; i < 10000; i++)
		v1.push_back(i);

	cout << "max : " << v1.capacity() << endl;		//12138
	cout << "size : " << v1.size() << endl;			//10000

	//----------------���� ȹ��???????-------------------------------
	vector<int>::iterator begin = v1.begin();   // v1�� ù��° �������� �ּ�
	vector<int>::iterator end = v1.end();		// v1�� ������ ������ ���� �ּ�
	vector<int>::iterator itr = find(begin, end, 9999);  //�Ϲ������δ� �Ͻ������
	if (itr == v1.end())
		cout << "����" << endl;
	else
		cout << *itr << endl;		// 9999
}

int main()
{
	exam2();
	return 0;
}