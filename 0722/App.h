//App.h

#pragma once
#include "StuManager.h"	//����
#include "AccManager.h"
class App
{
	StuManager ma;  //����
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

