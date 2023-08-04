//CustomerWait.h

#pragma once

#include <queue>		//STL Queue
using namespace std;
#include "customer.h"

class CustomerWait
{
	// 대기 고객들.
	queue<Customer*>  wait_queue;   //push, pop
	
	// [실시간] 대기 고객들의 주문 시간의 총합
	int waitingtime;

public:
	CustomerWait();
	~CustomerWait();

public:
	int get_waitingtime() const;
	int size() const;
public:
	void put(Customer *cust);
	Customer* get();
};

