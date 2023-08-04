//start.cpp
#include <iostream>
using namespace std;
#include "ehglobal.h"
#include "App.h"

int main()
{
	App app;
	app.Init();
	app.Run();
	app.Exit();

	return 0;
}