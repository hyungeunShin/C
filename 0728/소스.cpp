//소스.cpp

#include <iostream>
using namespace std;

#include "simulation.h"

int main()
{
	int simulation_length_in_hours;
	cout << "몇 시간동안 시뮬레이션 할 것인가요?" << endl;
	cout << ">> ";
	cin >> simulation_length_in_hours;

	int average_n_customers_per_hour;
	cout << "시간 당 몇 명의 손님이 올 것 같다고 생각하나요? "<< endl;
	cout << ">> ";
	cin >> average_n_customers_per_hour;

	Simulation simulation(simulation_length_in_hours, average_n_customers_per_hour);
	simulation.run5();
	//결과를 출력하는 메서드 호출>!

	return 0;
}