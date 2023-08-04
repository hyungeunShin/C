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
const char* name : 검색할 회원의 이름
int : 성공시 배열의 인덱스, 실패시 -1
*********************************************************/
int nametoidx(const char* name); 