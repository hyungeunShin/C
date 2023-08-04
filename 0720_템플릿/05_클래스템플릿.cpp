//05_Ŭ�������ø�
/*
Ŭ�������ø��� �ַ� ������ ����� Ŭ����(container class)�� Ȱ��ȴ�.
*/
#include <iostream>
using namespace std;
//wbarray.h
//Ŭ�������ø��� �ڵ尡 �ƴϴ�. -> �ڵ带 ����� Ʋ!!!!!!
//���ø��ڵ�� ������ h ���Ͽ� �����.!!!!!!!!!!!!!!!!!!!!!

template<typename T>				//<-----------------------------1)
class WbArray
{
private:
	T *base;   //T�� ����!, *base : �����迭	<--------------------2)
	int max;
	int size;

public:
	WbArray(int _max = 10);		//�⺻���� ����ο��� ó��
	~WbArray();

public:
	int get_size() const			{ return size; }

public:
	T get_data(int idx) const	{ return base[idx]; }		//<---------- 3)
	T operator[](int idx)		{ return base[idx]; }		//<---------- 4)

public:
	bool push_back(T value);								//<----------- 5
	bool erase(int idx);
};

template<typename T>
WbArray<T>::WbArray(int _max /*= 10*/) : max(_max), size(0)
{
	//�����迭
	base = new T[max];  //T�� max�� ������ �� �ִ� �迭�� ����<-------------------

	//��� �迭�� NULL�ʱ�ȭ
	for (int i = 0; i < max; i++)
		base[i] = NULL;
}

template<typename T>
WbArray<T>::~WbArray()
{
	//������ ��ü �Ҹ�
	for (int i = 0; i < size; i++)
		delete base[i];

	//������ ���� �迭 �Ҹ�
	delete[] base;
}

template<typename T>
bool WbArray<T>::push_back(T value)
{
	if (max <= size) //Overflow
		return false;

	base[size] = value;
	size++;
	return true;
}

template<typename T>
bool WbArray<T>::erase(int idx)
{
	//�������� �ε��� �Ǻ�
	if (idx < 0 || idx > size - 1)
		return false;

	void* del = base[idx];			//<-------------------
	for (int i = idx; i < size - 1; i++)
	{
		base[i] = base[i + 1];
	}
	size--;

	delete del;
	return true;
}

//--------------- ���ø� Ŭ���� ��� --------------------------------

//char�� ����!

int exam1_chartoidx(WbArray<char*>& arr, char value)	
{
	for (int i = 0; i < arr.get_size(); i++)
	{
		char* data = (char*)arr[i];
		if (*data == value)
			return i;
	}
	return -1;
}

//���� ������ : char
//char�� �ּҸ� �����ϰ� �ִ�.
void exam1()
{
	WbArray<char*> arr(26);			//<---------------------����1)

	//insert
	for (int i = 'a'; i <= 'z'; i++)
	{
		char* value = new char(i); //���޸𸮿� char��������� �����ϰ� i�� �ʱ�ȭ
		arr.push_back(value);
	}

	//printall
	for (int i = 0; i < arr.get_size(); i++)
	{
		char* data = arr[i];		//����2)-------------------------------------
		cout << *data << " ";
	}
	cout << endl << endl;

	//select
	int idx = exam1_chartoidx(arr, 'c');
	if (idx == -1)
		cout << "����" << endl;
	else
	{
		char* value = arr[idx];		//<-----------------------------------
		cout << "�˻���� : " << *value << endl;
	}

	//update
	idx = exam1_chartoidx(arr, 'c');
	if (idx == -1)
		cout << "����" << endl;
	else
	{
		char* value = arr[idx];		//<------------------------
		*value = 'C';
	}
	//printall
	for (int i = 0; i < arr.get_size(); i++)
	{
		char* data = arr[i];		//void* data = arr.get_data(i);
		cout << *data << " ";
	}
	cout << endl << endl;

	//delete
	idx = exam1_chartoidx(arr, 'f');
	if (idx == -1)
		cout << "����" << endl;
	else
	{
		arr.erase(idx);
	}
	//printall
	for (int i = 0; i < arr.get_size(); i++)
	{
		char* data = arr[i];		//void* data = arr.get_data(i);
		cout << *data << " ";
	}
	cout << endl << endl;
}

int main()
{
	exam1();

	return 0;
}