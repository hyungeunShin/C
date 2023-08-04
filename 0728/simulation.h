//simulation.h

#pragma once

#include <iostream>
using namespace std;
#include "customer.h"			//step1)
#include "customervisit.h"		//step1)
#include "CustomerWait.h"		//step2)

class Simulation
{	
	//����� ������ �� �ִ� �ɹ� ���� ����, �����ڿ��� �ʱ�ȭ
	//����� ����� �� �ִ� �ɹ� �Լ��� ����.
	//------------------------------------------

	int hour;
	int visit_count;

	CustomerVisit* pcustomervisit;
	CustomerWait* pcustomerwait;

public:
	Simulation(int _hour, int _visit_count);
	~Simulation();

public:
	//step1) �湮�� ó��
	void run1();

	//step2) �湮�� ��� queue�� ����- PUT
	void run2();

	//step3) ���ð��� 10�� �̻��� ��� �湮���� �ʰ� ó��
	void run3();

	//step4) ������ ���� ��� �ֹ� ó��(ť�� ���̰� �ִٸ�)->POP
	void run4();

	//step5) �ֹ��� ó���� ���� �� �ֹ��� ���� ���ϵ��� ó��
	void run5();
};


