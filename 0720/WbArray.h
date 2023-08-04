//wbarray.h

#pragma once

class WbArray
{
private:
	void* *base;   //void*를 저장!, *base : 동적배열
	int max;
	int size;

public:
	WbArray(int _max = 10);		//기본값은 선언부에만 처리
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

