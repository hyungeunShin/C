//control.h
#pragma once

void con_init();
void con_exit();

void con_printall();
void con_insert();
void con_select();
void con_update();
void con_delete();

/*******************************************************
const char* name : �˻��� ȸ���� �̸�
int : ������ �迭�� �ε���, ���н� -1
*********************************************************/
int nametoidx(const char* name); 