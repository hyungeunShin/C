//app.h
#pragma once  //h ���� include �ߺ� ����[���� ��ܿ� �־�� �Ѵ�.]

class App
{
private:
	Control con;		//has s(��ü ����)App�� ������ �� Control��ü�� ���� ������ �ȴ�.
	
public:
	void init();
	void run();
	void exit();

private:
	void logo();
	char menuprint();
	void ending();
}; 