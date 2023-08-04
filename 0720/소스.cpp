//�ҽ�.cpp

#include <iostream>
using namespace std;
#include "Account.h"
#include "WbArray.h"

//char�� ����!
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

//���� ������ : char
//char�� �ּҸ� �����ϰ� �ִ�.
void exam1()
{
	WbArray arr(26);

	//insert
	for (int i = 'a'; i <= 'z'; i++)
	{
		char* value = new char(i); //���޸𸮿� char��������� �����ϰ� i�� �ʱ�ȭ
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
		cout << "����" << endl;
	else
	{
		char* value = (char*)arr[idx];
		cout << "�˻���� : " <<  *value << endl; 
	}

	//update
	idx = exam1_chartoidx(arr, 'c');
	if (idx == -1)
		cout << "����" << endl;
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
		cout << "����" << endl;
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


//���� ������ : Account
//Account�� �ּҸ� ����
void exam2()
{
	WbArray arr(10);

	//insert #include "Account.h"
	Account *p1 = new Account(111, "ȫ�浿");		arr.push_back(p1);
	Account *p2 = new Account(222, "�̱浿", 1000);	arr.push_back(p2);
	Account *p3 = new Account(333, "��浿");		arr.push_back(p3);
	Account *p4 = new Account(444, "�ֱ浿", 2000);	arr.push_back(p4);


	//printall
	for (int i = 0; i < arr.get_size(); i++)
	{
		Account* data = (Account*)arr[i];		//void* data = arr.get_data(i);
		data->Print();
		cout << endl;
	}
	cout << endl << endl;

	//select1
	int idx = exam2_idtoidx(arr, 555);	//���¹�ȣ�� �˻�
	if (idx == -1)
		cout << "����" << endl;
	else
	{
		Account* value = (Account*)arr[idx];
		cout << "�˻���� : ";
		value->Print(); 		
	}
	cout << endl;

	//select2
	idx = exam2_nametoidx(arr, "��浿");	//�̸����� �˻�
	if (idx == -1)
		cout << "����" << endl;
	else
	{
		Account* value = (Account*)arr[idx];
		cout << "�˻���� : ";
		value->Print();
	}
	cout << endl;

	//update
	idx = exam2_nametoidx(arr, "��浿");	//�̸����� �˻�
	if (idx == -1)
		cout << "����" << endl;
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
	idx = exam2_nametoidx(arr, "��浿");	//�̸����� �˻�
	if (idx == -1)
		cout << "����" << endl;
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


//����ȭ�� ����ó��!!!!!!!!
//try~catch
//throw
void exam3()
{
	try
	{
		//���� �ڵ��ۼ� ����
		//�� �ȿ��� ���ܰ� �߻��� �� �ִ�.-> �� ���ܸ� ó���ϴ� catch���� ����
		//try �������� �ּ� �ϳ��� catch���� �ü� �ִ�.
		cout << "����1" << endl;
		cout << "����2" << endl;
		//throw "���ܹ���";'
		throw 10.1f;
		cout << "����3" << endl;
	}
	catch (int n)		
	{
		cout << "����(int) : " << n << endl;
	}
	catch (const char* msg)
	{
		cout << "����(const char*) : " << msg << endl;
	}
	catch (...)
	{
		cout << "����(...) - ��� ���ܸ� ���� �� �ִ� ����" << endl;
	}
	cout << "����4(try~chtch ��)" << endl;
}


float exam4_div(int num1, int num2)
{
	if (num2 == 0)
		throw "0���� ���� �� �����ϴ�";

	return (float)num1 / num2; 
}

void exam4()
{
	try
	{
		cout << exam4_div(10, 20) << endl;
		cout << exam4_div(10, 0) << endl;
		cout << exam4_div(10, 20) << endl;	//������ �ȵȴ�.
	}
	catch (const char* msg)
	{
		cout << "���� : " << msg << endl;
	}
}

int main()
{
	exam4();

	return 0;
}