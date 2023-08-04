//07_배열연산자
#include <iostream>
using namespace std;

class MyArr
{
	int arr[5];		//1,2,3,4,5
public:
	MyArr()
	{
		for (int i = 0; i < 5; i++)
		{
			arr[i] = i + 1;
		}
	}

public:
	int getData(int idx)		{ return arr[idx]; }
	int& operator[](int idx)	{ return arr[idx]; }
};

int main()
{
	MyArr arr;
	cout << arr.getData(2) << endl;			//3
	cout << arr[2] << endl;			// arr.operator[](2);

	arr[2]		= 10;				// 
	int value	= arr[2];	
	cout << value << endl;			//10
	

	return 0;
}