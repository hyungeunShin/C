//customer.h
#pragma once

class Customer
{
	long arrival_time;	// �� �մ��� ���� �����ߴ���(��)
	int process_time;	// �� �մ��� �ֹ��ϴ� Ŀ�Ǹ� ����µ� �ɸ��� �ð� (�� �ð������� �ٸ� �մ� ������)

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


