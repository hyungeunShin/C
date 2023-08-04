//simulation.cpp
#include <windows.h>
#include "simulation.h"

Simulation::Simulation(int _hour, int _visit_count) 
	:hour(_hour), visit_count(_visit_count)
{
	srand((unsigned int)time(0));

	pcustomervisit = new CustomerVisit(_hour, _visit_count);
	pcustomerwait = new CustomerWait();
}

Simulation::~Simulation()
{
	delete pcustomervisit;
	delete pcustomerwait;
}

void Simulation::run1()
{
	int simulation_min = hour * 60;

	for (int i = 0; i < simulation_min; i++)  //for문 한번을 1분으로 ...
	{
		if (pcustomervisit->get_visit_data(i))
			cout << "방문함" << endl;
		else
			cout << "......" << endl;
	}
}

void Simulation::run2()
{
	int simulation_min = hour * 60;

	for (int i = 0; i < simulation_min; i++)  //for문 한번을 1분으로 ...
	{
		if (pcustomervisit->get_visit_data(i))
		{
			//방문을 했다면 큐에 저장.=========================
			Customer* pc = new Customer(i);
			pcustomerwait->put(pc);
			pc->print();
			//==================================================
		}
		else
			cout << "......" << endl;

		Sleep(1000);	 //#include <windows.h>
	}
}

void Simulation::run3()
{
	int simulation_min = hour * 60;

	for (int i = 0; i < simulation_min; i++)  //for문 한번을 1분으로 ...
	{
		if (pcustomervisit->get_visit_data(i))
		{
			//------------------------------------------------------------
			if (pcustomerwait->get_waitingtime() > 10)
			{
				cout << "대기시간 ";
				cout << pcustomerwait->get_waitingtime() << "분" ;
				cout << "이라서 되돌아 갔습니다." << "\t";
				cout << "대기인원 : " << pcustomerwait->size() << "명" << endl;
			}//------------------------------------------------------------
			else
			{
				Customer* pc = new Customer(i);
				pcustomerwait->put(pc);
				pc->print();
				//cout << pcustomerwait->get_waitingtime() << "분" << endl;
			}
		}
		else
			cout << "......" << endl;

		Sleep(1000);
	}
}

void Simulation::run4()
{
	int simulation_min = hour * 60;

	for (int i = 0; i < simulation_min; i++)  //for문 한번을 1분으로 ...
	{
		//대기 처리 
		if (pcustomervisit->get_visit_data(i))
		{
			if (pcustomerwait->get_waitingtime() > 10)
			{
				cout << "대기시간 ";
				cout << pcustomerwait->get_waitingtime() << "분";
				cout << "이라서 되돌아 갔습니다." << "\t";
				cout << "대기인원 : " << pcustomerwait->size() << "명" << endl;
			}
			else
			{
				Customer* pc = new Customer(i);
				pcustomerwait->put(pc);
				pc->print();
				cout << pcustomerwait->get_waitingtime() << "분" << endl;
			}
		}
		else
			cout << "......" << endl;
	
		//주문 처리 -----------------------------------------------
		if (pcustomerwait->size() > 0)  // 대기큐에 고객이 존재할 경우
		{			
			Customer* pcust  = pcustomerwait->get(); //고객을 GET
			pcust->get_print();
		}
		//------------------------------------------------------------
		Sleep(1000);
	}
}

void Simulation::run5()
{
	int simulation_min = hour * 60;
	int wait_time = 0;  //점원이 주문을 받아서 제품을 만드는 시간 //<------------ 추가 

	for (int i = 0; i < simulation_min; i++)  //for문 한번을 1분으로 ...
	{
		//대기 처리 
		if (pcustomervisit->get_visit_data(i))
		{
			if (pcustomerwait->get_waitingtime() > 3)
			{
				cout << "대기시간 ";
				cout << pcustomerwait->get_waitingtime() << "분";
				cout << "이라서 되돌아 갔습니다." << "\t";
				cout << "대기인원 : " << pcustomerwait->size() << "명" << endl;
			}
			else
			{
				Customer* pc = new Customer(i);
				pcustomerwait->put(pc);
				pc->print();
				//cout << pcustomerwait->get_waitingtime() << "분" << endl;
			}
		}
		else
			cout << "......" << endl;

		//주문 처리
		Customer* pcust = NULL;
		if (wait_time <= 0 && pcustomerwait->size() > 0) //<----- [수정]
		{
			pcust = pcustomerwait->get();
			pcust->get_print();
			wait_time = pcust->get_procss_time();  //<---------------
		}

		//주문 중일 경우 재 주문을 받지 못하도록======================
		if (wait_time > 0)
		{
			wait_time--;
			if( pcust != NULL)
				pcust->get_print(wait_time);
		}
		//=============================================================
		Sleep(1000);
	}
}