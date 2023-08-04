//customer.cpp
#include <iostream>
using namespace std;
#include "customer.h"

Customer::Customer(int at) : arrival_time(at)
{
	process_time = rand() % 3 + 1;// 1,2,3 �� �ϳ�. �մ��� Ŀ�Ǹ� ����� �ð��� ��������
}

void Customer::print() const
{
	cout << arrival_time << "�п� ���� ���� ���̽��ϴ�." << process_time << endl;
}

void Customer::get_print() const
{
	cout << arrival_time << "�п� ������ ������ Ŀ�Ǹ� ";
	cout << process_time << "�� ���� ����� �����մϴ�." << endl;
}

void Customer::get_print(int time) const
{
	cout << arrival_time << "�п� ������ ������ Ŀ�� �ϼ����� ";
	cout << time << "�� ���ҽ��ϴ�." << endl;
}