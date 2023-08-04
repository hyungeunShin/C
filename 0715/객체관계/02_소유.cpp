//02_소유
/*
[생성과 소멸을 같이하는 강력한 소유의 관계]
TV와 Remocon의 관계
*/

#include <iostream>
using namespace std;


class TV
{
private:
	bool isonoff;
public:
	TV() : isonoff(false)	{ }

public:
	void OnOff()	{			isonoff = !isonoff;		}
};

//Remocon이 생성될 때 TV가 생성.
class Remocon
{
	TV *ptv;
public:
	Remocon()	{ ptv = new TV;		}
	~Remocon()	{ delete ptv;		}

public:
	void OnOff()
	{
		ptv->OnOff();
	}
};

int main()
{
	Remocon rcon;
	rcon.OnOff();
	return 0;
}