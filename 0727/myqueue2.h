//myqueue2.h

#pragma once
class myqueue2
{
	void** base;
	int max;
	int rear;		//저장 위치 
	int front;		//삭제 위치 

public:
	myqueue2(int _max = 10);
	~myqueue2();

public:
	int get_max() const { return max;  }
	int get_rear() const { return rear; }
	int get_front() const { return front; }
	void* operator[](int idx) { return base[idx]; }

public:
	//개수 반환
	int count();

	//오버플로우 검사
	bool overflow();
	//언더플로우(empty)검사
	bool empty();

	//저장
	bool put( void* value);
	//삭제
	void* get();

	//가장 상단에 있는 데이터 반환
	void* peek();
};

