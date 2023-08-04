//mystack1.h

#pragma once

class mystack1
{
private:
	void* *base;  //void* 를 저장할 수있는 배열
	int max;
	int top;	//저장 & 삭제 위치 관리

public:
	mystack1(int _max = 10);
	~mystack1();

public:
	int gettop() const					{ return top; }
	void* getdata(int idx) const		{ return base[idx]; }
	void* operator[](int idx)	const	{ return base[idx]; }
private:
	//오버플로우 검사
	bool overflow();
	//언더플로우(empty)검사
	bool empty();

public:
	//저장
	bool push(void *value);
	//삭제
	void* pop();
	//가장 상단에 있는 데이터 반환
	void* peek();
};

