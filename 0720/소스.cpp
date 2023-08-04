//소스.cpp

#include <iostream>
using namespace std;
#include "Account.h"
#include "WbArray.h"

//char를 관리!
int exam1_chartoidx(WbArray& arr, char value)
{
	for (int i = 0; i < arr.get_size(); i++)
	{
		char* data = (char*)arr[i];
		if ( *data == value)
			return i;
	}
	return -1;
}

//관리 데이터 : char
//char의 주소를 저장하고 있다.
void exam1()
{
	WbArray arr(26);

	//insert
	for (int i = 'a'; i <= 'z'; i++)
	{
		char* value = new char(i); //힙메모리에 char저장공간을 생성하고 i로 초기화
		arr.push_back(value);
	}

	//printall
	for (int i = 0; i < arr.get_size(); i++)
	{
		char* data = (char*)arr[i];		//void* data = arr.get_data(i);
		cout << *data << " ";
	}
	cout << endl << endl;

	//select
	int idx = exam1_chartoidx(arr, 'c');
	if (idx == -1)
		cout << "없다" << endl;
	else
	{
		char* value = (char*)arr[idx];
		cout << "검색결과 : " <<  *value << endl; 
	}

	//update
	idx = exam1_chartoidx(arr, 'c');
	if (idx == -1)
		cout << "없다" << endl;
	else
	{
		char* value = (char*)arr[idx];
		*value = 'C';
	}
	//printall
	for (int i = 0; i < arr.get_size(); i++)
	{
		char* data = (char*)arr[i];		//void* data = arr.get_data(i);
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
		char* data = (char*)arr[i];		//void* data = arr.get_data(i);
		cout << *data << " ";
	}
	cout << endl << endl;
}




int exam2_idtoidx(WbArray& arr, int id)
{
	for (int i = 0; i < arr.get_size(); i++)
	{
		Account* data = (Account*)arr[i];
		if (data->get_id() == id)
			return i;
	}
	return -1;
}

int exam2_nametoidx(WbArray& arr, string name)
{
	for (int i = 0; i < arr.get_size(); i++)
	{
		Account* data = (Account*)arr[i];
		if (data->get_name() == name)
			return i;
	}
	return -1;
}


//관리 데이터 : Account
//Account의 주소를 저장
void exam2()
{
	WbArray arr(10);

	//insert #include "Account.h"
	Account *p1 = new Account(111, "홍길동");		arr.push_back(p1);
	Account *p2 = new Account(222, "이길동", 1000);	arr.push_back(p2);
	Account *p3 = new Account(333, "김길동");		arr.push_back(p3);
	Account *p4 = new Account(444, "최길동", 2000);	arr.push_back(p4);


	//printall
	for (int i = 0; i < arr.get_size(); i++)
	{
		Account* data = (Account*)arr[i];		//void* data = arr.get_data(i);
		data->Print();
		cout << endl;
	}
	cout << endl << endl;

	//select1
	int idx = exam2_idtoidx(arr, 555);	//계좌번호로 검색
	if (idx == -1)
		cout << "없다" << endl;
	else
	{
		Account* value = (Account*)arr[idx];
		cout << "검색결과 : ";
		value->Print(); 		
	}
	cout << endl;

	//select2
	idx = exam2_nametoidx(arr, "김길동");	//이름으로 검색
	if (idx == -1)
		cout << "없다" << endl;
	else
	{
		Account* value = (Account*)arr[idx];
		cout << "검색결과 : ";
		value->Print();
	}
	cout << endl;

	//update
	idx = exam2_nametoidx(arr, "김길동");	//이름으로 검색
	if (idx == -1)
		cout << "없다" << endl;
	else
	{
		Account* value = (Account*)arr[idx];
		value->InputMoney(2000);
	}
	//printall
	for (int i = 0; i < arr.get_size(); i++)
	{
		Account* data = (Account*)arr[i];		//void* data = arr.get_data(i);
		data->Print();
		cout << endl;
	}
	cout << endl << endl;

	//delete
	idx = exam2_nametoidx(arr, "김길동");	//이름으로 검색
	if (idx == -1)
		cout << "없다" << endl;
	else
	{
		arr.erase(idx);
	}
	//printall
	for (int i = 0; i < arr.get_size(); i++)
	{
		Account* data = (Account*)arr[i];		//void* data = arr.get_data(i);
		data->Print();
		cout << endl;
	}
	cout << endl << endl;
}


//구조화된 예외처리!!!!!!!!
//try~catch
//throw
void exam3()
{
	try
	{
		//실제 코드작성 영역
		//이 안에서 예외가 발생할 수 있다.-> 그 예외를 처리하는 catch문을 실행
		//try 다음에는 최소 하나의 catch문이 올수 있다.
		cout << "문장1" << endl;
		cout << "문장2" << endl;
		//throw "예외문장";'
		throw 10.1f;
		cout << "문장3" << endl;
	}
	catch (int n)		
	{
		cout << "예외(int) : " << n << endl;
	}
	catch (const char* msg)
	{
		cout << "예외(const char*) : " << msg << endl;
	}
	catch (...)
	{
		cout << "예외(...) - 모든 예외를 받을 수 있는 영역" << endl;
	}
	cout << "문장4(try~chtch 후)" << endl;
}


float exam4_div(int num1, int num2)
{
	if (num2 == 0)
		throw "0으로 나눌 수 없습니다";

	return (float)num1 / num2; 
}

void exam4()
{
	try
	{
		cout << exam4_div(10, 20) << endl;
		cout << exam4_div(10, 0) << endl;
		cout << exam4_div(10, 20) << endl;	//실행이 안된다.
	}
	catch (const char* msg)
	{
		cout << "에러 : " << msg << endl;
	}
}

int main()
{
	exam4();

	return 0;
}