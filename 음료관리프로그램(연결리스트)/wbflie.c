//wbfile.c

#include "std.h"

void file_read(linkedlist *parr)
{
	//파일오픈
	FILE *fin;
	fopen_s(&fin, "drinklist1.txt", "r");
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
		list_frontinsert(parr, dr);
	}

	//파일 종료
	fclose(fin);
}

void file_write(linkedlist *parr)
{
	//파일오픈
	FILE *fout;
	fopen_s(&fout, "drinklist1.txt", "w");

	int size = parr->size;
	fprintf(fout, "%d\n", size);

	node* cur = parr->head;
	while (cur != NULL)
	{
		drink dr = cur->data;
		fprintf(fout, "%10s %10d\n", dr.name, dr.price);
		cur = cur->next;
	}	

	//파일 종료
	fclose(fout);
}