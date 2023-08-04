//CustomerWait.cpp

#include <iostream>
using namespace std;
#include "CustomerWait.h"

CustomerWait::CustomerWait() :waitingtime(0)
{

}

CustomerWait::~CustomerWait()
{

}

void CustomerWait::put(Customer* cust)
{
	//push : put 알고리즘.
	wait_queue.push(cust);

	waitingtime = waitingtime + cust->get_procss_time();
}

int CustomerWait::size() const
{
	return (int)wait_queue.size();
}
	
Customer* CustomerWait::get()
{
	//front() : 삭제할 위치의 데이터를 획득 
	Customer* cust = wait_queue.front();

	//pop() : 삭제할 위치의 데이터가 제거
	wait_queue.pop();

	waitingtime = waitingtime - cust->get_procss_time();

	return cust;
}

int CustomerWait::get_waitingtime() const
{
	return waitingtime;
}
