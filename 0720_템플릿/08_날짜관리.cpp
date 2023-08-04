//08_날짜관리
#include <iostream> 
#include <ctime> 
using namespace std;

int main()
{
	struct tm newtime;
	time_t long_time;

	time(&long_time);
	localtime_s(&newtime, &long_time);
	
	int curr_year	= newtime.tm_year + 1900; 
	int curr_month	= newtime.tm_mon + 1; 
	int curr_day	= newtime.tm_mday; 
	int curr_hour	= newtime.tm_hour; 
	int curr_minute = newtime.tm_min; 
	int curr_second = newtime.tm_sec; 
	
	printf("%d-%d-%d %d:%d:%d\n", 
		curr_year, curr_month, curr_day, 
		curr_hour, curr_minute, curr_second);

	return 0;
}

