//customervisit.cpp

#include <iostream>
using namespace std;
#include "customervisit.h"

CustomerVisit::CustomerVisit(int hour, int visit_count)
{
	srand((unsigned int)time(0));
	
	max = hour * 60;  //시간을 분으로 환산 -> 배열 크기 셋팅!
	visit_data = new bool[max];

	//0번째 인덱스부터 시간당 방문 고객만큼 true로 설정!
	//예를 들어 : hour 2, 시간당 방문고객수 : 10명
	//            전체 배열의 크기 : 120개 
	//	          방문 고객 수     : 20명
	for (int i = 0; i < max; i++)
	{
		if (i < visit_count *hour) 
			visit_data[i] = true;
		else
			visit_data[i] = false;
	}

	//렌덤하게 섞었다.
	for (int i = 0; i < 10000; i++)
	{
		int n1 = rand() % max;
		int n2 = rand() % max;
		
		//swap 코드
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