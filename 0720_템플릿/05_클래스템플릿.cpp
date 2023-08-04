//05_클래스템플릿
/*
클래스템플릿은 주로 데이터 저장소 클래스(container class)에 활용된다.
*/
#include <iostream>
using namespace std;
//wbarray.h
//클래스템플릿은 코드가 아니다. -> 코드를 만드는 틀!!!!!!
//템플릿코드는 무조건 h 파일에 만든다.!!!!!!!!!!!!!!!!!!!!!

template<typename T>				//<-----------------------------1)
class WbArray
{
private:
	T *base;   //T를 저장!, *base : 동적배열	<--------------------2)
	int max;
	int size;

public:
	WbArray(int _max = 10);		//기본값은 선언부에만 처리
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
	//동적배열
	base = new T[max];  //T를 max개 저장할 수 있는 배열을 생성<-------------------

	//모든 배열을 NULL초기화
	for (int i = 0; i < max; i++)
		base[i] = NULL;
}

template<typename T>
WbArray<T>::~WbArray()
{
	//생성된 객체 소멸
	for (int i = 0; i < size; i++)
		delete base[i];

	//생성된 동적 배열 소멸
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
	//정상적인 인덱스 판별
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

//--------------- 템플릿 클래스 사용 --------------------------------

//char를 관리!

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

//관리 데이터 : char
//char의 주소를 저장하고 있다.
void exam1()
{
	WbArray<char*> arr(26);			//<---------------------수정1)

	//insert
	for (int i = 'a'; i <= 'z'; i++)
	{
		char* value = new char(i); //힙메모리에 char저장공간을 생성하고 i로 초기화
		arr.push_back(value);
	}

	//printall
	for (int i = 0; i < arr.get_size(); i++)
	{
		char* data = arr[i];		//수정2)-------------------------------------
		cout << *data << " ";
	}
	cout << endl << endl;

	//select
	int idx = exam1_chartoidx(arr, 'c');
	if (idx == -1)
		cout << "없다" << endl;
	else
	{
		char* value = arr[idx];		//<-----------------------------------
		cout << "검색결과 : " << *value << endl;
	}

	//update
	idx = exam1_chartoidx(arr, 'c');
	if (idx == -1)
		cout << "없다" << endl;
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
		cout << "없다" << endl;
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