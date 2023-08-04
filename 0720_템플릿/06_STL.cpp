//06_STL(Standard Template Library)
/*
STL을 구성하는 중요한 3가지 요소
1) Container( 데이터 저장소 ) -> 템플릿 클래스 형태로 지원
2) Algorithm( 함수 )          -> 템플릿 함수 형태로 지원
3) iterator (이터레이터 )     -> 내포클래스 형태로 지원, 데이터 저장소를 순회하는 도구
...
*/
#include <iostream>
#include <algorithm>		//STL의 알고리즘 함수 사용
#include <functional>
#include <iterator>
#include <vector>
using namespace std;

//알고리즘
void exam1()
{
	//컨테이너(데이터를 저장하고 있으면)
	int arr[10] = { 4, 2, 6, 121, 5, 23, 65, 323, 31, 23 };

	//STL 알고리즘 함수
	int*ret =  find<int*, int>(arr, arr + 10, 23);  //일반적으로는 암시적사용
	if (ret == arr + 10)
		cout << "없다" << endl;
	else
		cout << *ret << endl; 

	//STL 알고리즘 함수
	sort(arr, arr + 10);

	//전체 출력
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl; 

	//STL 알고리즘 함수
	copy(arr, arr + 10, ostream_iterator<int>(cout, "-")); //#include <iterator>
}

//컨테이너[자료구조(배열, 연결리스트)]
//배열 : vector

void exam2()
{
	vector<int> v1;		//int를 저장하는 배열!!!! --> WbArray
	cout << "max : " << v1.capacity() << endl;		//0
	cout << "size : " << v1.size() << endl;			//0

	//데이터를 넣을때마다 max값과 size를 계속 증가시켜준다.
	for (int i = 0; i < 10000; i++)
		v1.push_back(i);

	cout << "max : " << v1.capacity() << endl;		//12138
	cout << "size : " << v1.size() << endl;			//10000

	//----------------구간 획득???????-------------------------------
	vector<int>::iterator begin = v1.begin();   // v1의 첫번째 데이터의 주소
	vector<int>::iterator end = v1.end();		// v1의 마지막 데이터 다음 주소
	vector<int>::iterator itr = find(begin, end, 9999);  //일반적으로는 암시적사용
	if (itr == v1.end())
		cout << "없다" << endl;
	else
		cout << *itr << endl;		// 9999
}

int main()
{
	exam2();
	return 0;
}