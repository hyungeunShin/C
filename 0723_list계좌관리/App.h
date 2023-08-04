//App.h

#pragma once
#include "StuManager.h"	//삭제
#include "AccManager.h"
class App
{
	StuManager ma;  //삭제
	AccManager ama;
public:
	App();
	~App();

public:
	void Init();
	void Run();
	void Exit();

private:
	void Logo();
	void Ending();
	keydata MenuPrint();
};

