//customervisit.h

#pragma once

class CustomerVisit
{
	bool* visit_data;		//bool���� �����ϴ� ���� �迭.
	int max;				//�迭�� ũ��
public:
	CustomerVisit(int hour, int visit_count);

public:
	bool get_visit_data(int idx);

public:
	void print() const;
};