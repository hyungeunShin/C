//start.cpp
#include <iostream>
using namespace std;
#include "ehglobal.h"
#include "App.h"

//#include "AccList.h"
int main()
{
	//AccList alist(111, 1000, 0, 2000);
	//alist.Print();

	App app;
	app.Init();
	app.Run();
	app.Exit();

	return 0;
}