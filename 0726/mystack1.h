//mystack1.h

#pragma once

class mystack1
{
private:
	void* *base;  //void* �� ������ ���ִ� �迭
	int max;
	int top;	//���� & ���� ��ġ ����

public:
	mystack1(int _max = 10);
	~mystack1();

public:
	int gettop() const					{ return top; }
	void* getdata(int idx) const		{ return base[idx]; }
	void* operator[](int idx)	const	{ return base[idx]; }
private:
	//�����÷ο� �˻�
	bool overflow();
	//����÷ο�(empty)�˻�
	bool empty();

public:
	//����
	bool push(void *value);
	//����
	void* pop();
	//���� ��ܿ� �ִ� ������ ��ȯ
	void* peek();
};

