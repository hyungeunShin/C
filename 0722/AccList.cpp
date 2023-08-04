//acclist.cpp

#include <ctime> 
using namespace std;
#include "AccList.h"

AccList::AccList(int accid, int inputmoney, int outputmoney, int balance)
	: accid(accid), inputmoney(inputmoney), outputmoney(outputmoney), balance(balance)
{
	time_t long_time;
	time(&long_time);
	localtime_s(&newtime, &long_time);

	int curr_year = newtime.tm_year + 1900;
	int curr_month = newtime.tm_mon + 1;
	int curr_day = newtime.tm_mday;
	int curr_hour = newtime.tm_hour;
	int curr_minute = newtime.tm_min;
	int curr_second = newtime.tm_sec;

	char temp[50] = { 0 };
	sprintf_s(temp, "%04d-%02d-%02d", curr_year, curr_month, curr_day);
	accdate = temp;

	char temp1[50] = { 0 };
	sprintf_s(temp1, "%02d:%02d:%02d", curr_hour, curr_minute, curr_second);
	acctime = temp1;
}


AccList::~AccList()
{
}

void AccList::Print() const
{
	cout << accid << "\t";
	cout << accdate.c_str() << "\t";
	cout << acctime.c_str() << "\t";
	cout << inputmoney << "\t";
	cout << outputmoney << "\t";
	cout << balance << endl; 
}
