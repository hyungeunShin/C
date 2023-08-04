//simulation.h

#pragma once

#include <iostream>
using namespace std;
#include "customer.h"			//step1)
#include "customervisit.h"		//step1)
#include "CustomerWait.h"		//step2)

class Simulation
{	
	//결과를 보관할 수 있는 맴버 변수 선언, 생성자에서 초기화
	//결과를 출력할 수 있는 맴버 함수를 구성.
	//------------------------------------------

	int hour;
	int visit_count;

	CustomerVisit* pcustomervisit;
	CustomerWait* pcustomerwait;

public:
	Simulation(int _hour, int _visit_count);
	~Simulation();

public:
	//step1) 방문자 처리
	void run1();

	//step2) 방문할 경우 queue에 저장- PUT
	void run2();

	//step3) 대기시간이 10분 이상일 경우 방문하지 않게 처리
	void run3();

	//step4) 대기고객이 있을 경우 주문 처리(큐에 데이가 있다면)->POP
	void run4();

	//step5) 주문을 처리할 동안 재 주문을 받지 못하도록 처리
	void run5();
};


