//customervisit.cpp

#include <iostream>
using namespace std;
#include "customervisit.h"

CustomerVisit::CustomerVisit(int hour, int visit_count)
{
	srand((unsigned int)time(0));
	
	max = hour * 60;  //�ð��� ������ ȯ�� -> �迭 ũ�� ����!
	visit_data = new bool[max];

	//0��° �ε������� �ð��� �湮 ����ŭ true�� ����!
	//���� ��� : hour 2, �ð��� �湮���� : 10��
	//            ��ü �迭�� ũ�� : 120�� 
	//	          �湮 �� ��     : 20��
	for (int i = 0; i < max; i++)
	{
		if (i < visit_count *hour) 
			visit_data[i] = true;
		else
			visit_data[i] = false;
	}

	//�����ϰ� ������.
	for (int i = 0; i < 10000; i++)
	{
		int n1 = rand() % max;
		int n2 = rand() % max;
		
		//swap �ڵ�
		int temp = visit_data[n1];
		visit_data[n1] = visit_data[n2];
		visit_data[n2] = temp;
	}
}

bool CustomerVisit::get_visit_data(int idx) 
{ 
	return visit_data[idx]; 
}

void CustomerVisit::print() const
{
	for (int i = 0; i < max; i++)
	{
		printf("[%d] %d\n", i, visit_data[i]);
	}
}