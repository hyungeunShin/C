//customervisit.h

#pragma once

class CustomerVisit
{
	bool* visit_data;		//bool형을 저장하는 동적 배열.
	int max;				//배열의 크기
public:
	CustomerVisit(int hour, int visit_count);

public:
	bool get_visit_data(int idx);

public:
	void print() const;
};