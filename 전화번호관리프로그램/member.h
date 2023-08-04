//member.h

typedef struct member member;		
struct member						
{
	int flag;		//데이터 존재 유무(0 : 없다, 1 : 있다)
	char name[20];  //이름( 중복되지 않는다.)
	char phone[20]; //전화번호
};

//한줄에 모든 정보를 출력
void member_print(const member *pmem);

//한줄에 하나의 정보를 출력 
void member_println(const member *pmem);

member member_createmember(const char* name, const char* phone);
