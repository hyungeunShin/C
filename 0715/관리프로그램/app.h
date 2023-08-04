//app.h
#pragma once  //h 파일 include 중복 방지[제일 상단에 있어야 한다.]

class App
{
private:
	Control con;		//has s(객체 소유)App가 생성될 때 Control객체가 같이 생성이 된다.
	
public:
	void init();
	void run();
	void exit();

private:
	void logo();
	char menuprint();
	void ending();
}; 