//wbfile.c

#include "std.h"

void file_read(wbarr *parr)
{
	//파일오픈
	FILE *fin;
	fopen_s(&fin, "drinklist.txt", "r");
	if (fin == NULL)
	{
		printf("파일이 존재하지 않습니다\n");
		return;
	}

	//파일 read
	int size;
	fscanf_s(fin, "%d", &size); 

	drink dr;
	for (int i = 0; i < size; i++)
	{
		fscanf_s(fin, "%s %d", dr.name, sizeof(dr.name), &dr.price);

		arr_insert(parr, dr);
	}

	//파일 종료
	fclose(fin);
}

void file_write(wbarr *parr)
{
	//파일오픈
	FILE *fout;
	fopen_s(&fout, "drinklist.txt", "w");

	int size = parr->size;
	fprintf(fout, "%d\n", size);

	for (int i = 0; i < parr->size; i++)
	{
		drink dr = parr->base[i];
		fprintf(fout, "%10s %10d\n", dr.name, dr.price);
	}

	//파일 종료
	fclose(fout);

}