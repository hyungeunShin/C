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
	//push : put �˰���.
	wait_queue.push(cust);

	waitingtime = waitingtime + cust->get_procss_time();
}

int CustomerWait::size() const
{
	return (int)wait_queue.size();
}
	
Customer* CustomerWait::get()
{
	//front() : ������ ��ġ�� �����͸� ȹ�� 
	Customer* cust = wait_queue.front();

	//pop() : ������ ��ġ�� �����Ͱ� ����
	wait_queue.pop();

	waitingtime = waitingtime - cust->get_procss_time();

	return cust;
}

int CustomerWait::get_waitingtime() const
{
	return waitingtime;
}
