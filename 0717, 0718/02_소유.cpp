//02_����
/*
[������ �Ҹ��� �����ϴ� ������ ������ ����]
TV�� Remocon�� ����
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

//Remocon�� ������ �� TV�� ����.
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