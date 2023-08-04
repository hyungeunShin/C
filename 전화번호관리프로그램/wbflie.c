//wbfile.c

#include "std.h"

void file_read(wbarr *parr)
{
	//파일오픈
	FILE *fin;
	fopen_s(&fin, "전화번호부.txt", "r");
	if (fin == NULL)
	{
		printf("파일이 존재하지 않습니다\n");
		return;
	}

	//파일 read
	int size;
	fscanf_s(fin, "%d", &size); 

	member mem;
	for (int i = 0; i < size; i++)
	{
		fscanf_s(fin, "%s %s",mem.name, sizeof(mem.name), mem.phone, sizeof(mem.phone));

		arr_insert(parr, mem);
	}

	//파일 종료
	fclose(fin);
}

void file_write(wbarr *parr)
{
	//파일오픈
	FILE *fout;
	fopen_s(&fout, "전화번호부.txt", "w");

	int size = parr->size;
	fprintf(fout, "%d\n", size);

	for (int i = 0; i < parr->size; i++)
	{
		member mem = parr->base[i];
		fprintf(fout, "%10s %10s\n", mem.name, mem.phone);
	}

	//파일 종료
	fclose(fout);

}