//control.h
#pragma once

#define DATA_MAX	10

class Control
{
	//Member members[DATA_MAX];		//Member啊 10俺 积己
	Member* members[DATA_MAX];		//Member狼 林家甫 10俺 历厘 硅凯 积己

	//积己磊 & 家戈磊
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