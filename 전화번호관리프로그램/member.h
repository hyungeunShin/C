//member.h

typedef struct member member;		
struct member						
{
	int flag;		//������ ���� ����(0 : ����, 1 : �ִ�)
	char name[20];  //�̸�( �ߺ����� �ʴ´�.)
	char phone[20]; //��ȭ��ȣ
};

//���ٿ� ��� ������ ���
void member_print(const member *pmem);

//���ٿ� �ϳ��� ������ ��� 
void member_println(const member *pmem);

member member_createmember(const char* name, const char* phone);
