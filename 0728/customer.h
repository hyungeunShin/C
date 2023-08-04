//customer.h
#pragma once

class Customer
{
	long arrival_time;	// 이 손님이 언제 도착했는지(분)
	int process_time;	// 이 손님이 주문하는 커피를 만드는데 걸리는 시간 (이 시간동안은 다른 손님 못받음)

public:
	Customer(int at);

public:
	long get_arrival_time() const	{ return arrival_time; }
	int get_procss_time() const		{ return process_time;  }

public:
	void print() const;
	void get_print() const;
	void get_print(int time) const;
};


