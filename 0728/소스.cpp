//�ҽ�.cpp

#include <iostream>
using namespace std;

#include "simulation.h"

int main()
{
	int simulation_length_in_hours;
	cout << "�� �ð����� �ùķ��̼� �� ���ΰ���?" << endl;
	cout << ">> ";
	cin >> simulation_length_in_hours;

	int average_n_customers_per_hour;
	cout << "�ð� �� �� ���� �մ��� �� �� ���ٰ� �����ϳ���? "<< endl;
	cout << ">> ";
	cin >> average_n_customers_per_hour;

	Simulation simulation(simulation_length_in_hours, average_n_customers_per_hour);
	simulation.run5();
	//����� ����ϴ� �޼��� ȣ��>!

	return 0;
}