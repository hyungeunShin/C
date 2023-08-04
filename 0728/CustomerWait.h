//CustomerWait.h

#pragma once

#include <queue>		//STL Queue
using namespace std;
#include "customer.h"

class CustomerWait
{
	// ��� ����.
	queue<Customer*>  wait_queue;   //push, pop
	
	// [�ǽð�] ��� ������ �ֹ� �ð��� ����
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

