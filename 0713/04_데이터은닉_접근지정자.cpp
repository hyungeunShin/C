//04_������ ����_����������
//�ɹ������� �ܺη� ������״��� �Ҿ����ϴ�.
//���� ������ ������ �ʿ��ϴ�...
//[����]
//���� ������
//- public		: ����, ������ ��밡��
//- protected	
//- private		: ����, �ܺο����� ���� �Ұ���!
#include <iostream>
using namespace std;

struct TV
{
private:
	int channel;	//1~50

public:
	void inputchannel(int c)
	{
		if (c < 1 || c > 50)
			return;

		channel = c;
	}
};

int main()
{
	TV  tv1;
//	tv1.channel = 100;		//������ ����
	tv1.inputchannel(100);	//�޼��� ����

	return 0;
}