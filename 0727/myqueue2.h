//myqueue2.h

#pragma once
class myqueue2
{
	void** base;
	int max;
	int rear;		//���� ��ġ 
	int front;		//���� ��ġ 

public:
	myqueue2(int _max = 10);
	~myqueue2();

public:
	int get_max() const { return max;  }
	int get_rear() const { return rear; }
	int get_front() const { return front; }
	void* operator[](int idx) { return base[idx]; }

public:
	//���� ��ȯ
	int count();

	//�����÷ο� �˻�
	bool overflow();
	//����÷ο�(empty)�˻�
	bool empty();

	//����
	bool put( void* value);
	//����
	void* get();

	//���� ��ܿ� �ִ� ������ ��ȯ
	void* peek();
};

