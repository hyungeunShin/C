//App.h

#pragma once
#include "StuManager.h"
class App
{
	StuManager ma;
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

