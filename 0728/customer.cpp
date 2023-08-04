//customer.cpp
#include <iostream>
using namespace std;
#include "customer.h"

Customer::Customer(int at) : arrival_time(at)
{
	process_time = rand() % 3 + 1;// 1,2,3 중 하나. 손님의 커피를 만드는 시간도 랜덤으로
}

void Customer::print() const
{
	cout << arrival_time << "분에 고객이 줄을 서셨습니다." << process_time << endl;
}

void Customer::get_print() const
{
	cout << arrival_time << "분에 입장한 고객님의 커피를 ";
	cout << process_time << "분 동안 만들기 시작합니다." << endl;
}

void Customer::get_print(int time) const
{
	cout << arrival_time << "분에 입장한 고객님의 커피 완성까지 ";
	cout << time << "분 남았습니다." << endl;
}