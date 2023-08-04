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

	for (int i = 0; i < simulation_min; i++)  //for�� �ѹ��� 1������ ...
	{
		if (pcustomervisit->get_visit_data(i))
			cout << "�湮��" << endl;
		else
			cout << "......" << endl;
	}
}

void Simulation::run2()
{
	int simulation_min = hour * 60;

	for (int i = 0; i < simulation_min; i++)  //for�� �ѹ��� 1������ ...
	{
		if (pcustomervisit->get_visit_data(i))
		{
			//�湮�� �ߴٸ� ť�� ����.=========================
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

	for (int i = 0; i < simulation_min; i++)  //for�� �ѹ��� 1������ ...
	{
		if (pcustomervisit->get_visit_data(i))
		{
			//------------------------------------------------------------
			if (pcustomerwait->get_waitingtime() > 10)
			{
				cout << "���ð� ";
				cout << pcustomerwait->get_waitingtime() << "��" ;
				cout << "�̶� �ǵ��� �����ϴ�." << "\t";
				cout << "����ο� : " << pcustomerwait->size() << "��" << endl;
			}//------------------------------------------------------------
			else
			{
				Customer* pc = new Customer(i);
				pcustomerwait->put(pc);
				pc->print();
				//cout << pcustomerwait->get_waitingtime() << "��" << endl;
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

	for (int i = 0; i < simulation_min; i++)  //for�� �ѹ��� 1������ ...
	{
		//��� ó�� 
		if (pcustomervisit->get_visit_data(i))
		{
			if (pcustomerwait->get_waitingtime() > 10)
			{
				cout << "���ð� ";
				cout << pcustomerwait->get_waitingtime() << "��";
				cout << "�̶� �ǵ��� �����ϴ�." << "\t";
				cout << "����ο� : " << pcustomerwait->size() << "��" << endl;
			}
			else
			{
				Customer* pc = new Customer(i);
				pcustomerwait->put(pc);
				pc->print();
				cout << pcustomerwait->get_waitingtime() << "��" << endl;
			}
		}
		else
			cout << "......" << endl;
	
		//�ֹ� ó�� -----------------------------------------------
		if (pcustomerwait->size() > 0)  // ���ť�� ���� ������ ���
		{			
			Customer* pcust  = pcustomerwait->get(); //���� GET
			pcust->get_print();
		}
		//------------------------------------------------------------
		Sleep(1000);
	}
}

void Simulation::run5()
{
	int simulation_min = hour * 60;
	int wait_time = 0;  //������ �ֹ��� �޾Ƽ� ��ǰ�� ����� �ð� //<------------ �߰� 

	for (int i = 0; i < simulation_min; i++)  //for�� �ѹ��� 1������ ...
	{
		//��� ó�� 
		if (pcustomervisit->get_visit_data(i))
		{
			if (pcustomerwait->get_waitingtime() > 3)
			{
				cout << "���ð� ";
				cout << pcustomerwait->get_waitingtime() << "��";
				cout << "�̶� �ǵ��� �����ϴ�." << "\t";
				cout << "����ο� : " << pcustomerwait->size() << "��" << endl;
			}
			else
			{
				Customer* pc = new Customer(i);
				pcustomerwait->put(pc);
				pc->print();
				//cout << pcustomerwait->get_waitingtime() << "��" << endl;
			}
		}
		else
			cout << "......" << endl;

		//�ֹ� ó��
		Customer* pcust = NULL;
		if (wait_time <= 0 && pcustomerwait->size() > 0) //<----- [����]
		{
			pcust = pcustomerwait->get();
			pcust->get_print();
			wait_time = pcust->get_procss_time();  //<---------------
		}

		//�ֹ� ���� ��� �� �ֹ��� ���� ���ϵ���======================
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