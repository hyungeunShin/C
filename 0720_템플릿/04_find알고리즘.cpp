//04_find 알고리즘
/*
알고리즘 
1) 구간 : 알고리즘을 수행할 영역(시작점~ 끝점)
    int arr[5] = {1,2,3,4,5};
	시작점 : arr
	끝  점 : arr+5 (past the end)
2) 알고리즘에 따라 필요한 정보 전달!
*/
#include <iostream>
using namespace std;
/*
int* myfind(int* start, int *end, int findvalue)
{
	for (; start != end; start++)
	{
		if (*start == findvalue)
			break;
	}
	return start;
}
*/

template<typename T1, typename T2>
T1 myfind(T1 start, T1 end, T2 findvalue)
{
	for (; start != end; start++)
	{
		if (*start == findvalue)
			break;
	}
	return start;
}

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int* ret = myfind(arr, arr + 5, 55);
	if (ret == arr + 5)
		cout << "없다" << endl;
	else
		cout << *ret << endl; 

	double arr1[5] = { 10.1, 20.2, 30.1, 41.2, 51.4 };
	double* ret1 = myfind(arr1, arr1 + 5, 51.4);
	if (ret1 == arr1 + 5)
		cout << "없다" << endl;
	else
		cout << *ret1 << endl;
	return 0;
}