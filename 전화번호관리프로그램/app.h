//app.h
#pragma once

void app_init();
void app_run();
void app_exit();

void logo();

/*---------------------------------------------------------------------
함 수 명 : menuprint
기    능 : 메뉴 출력 및 사용자 선택
반환타입 : char : 사용자가 선택한 정보를 문자 형태로 반환
-----------------------------------------------------------------------*/
char menuprint();
void ending();