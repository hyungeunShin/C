//control.h
#pragma once

#define DATA_MAX	10

class Control
{
	//Member members[DATA_MAX];		//Member�� 10�� ����
	Member* members[DATA_MAX];		//Member�� �ּҸ� 10�� ���� �迭 ����

	//������ & �Ҹ���
public:
	Control();
	~Control();

public:
	void printall() const;
	void insert();
	void select() const;
	void update();
	void delete1();

private:
	int nametoidx(string name) const;
};