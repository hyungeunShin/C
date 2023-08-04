//wbarray.h

#pragma once

class WbArray
{
private:
	void* *base;   //void*�� ����!, *base : �����迭
	int max;
	int size;

public:
	WbArray(int _max = 10);		//�⺻���� ����ο��� ó��
	~WbArray();

public:
	int get_size() const			{ return size;		}

public:
	void* get_data(int idx) const	{ return base[idx]; }
	void* operator[](int idx)		{ return base[idx]; }

public:
	bool push_back(void* value);
	bool erase(int idx);	
};

