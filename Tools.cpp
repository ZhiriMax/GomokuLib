#include"Tools.h"
#include"windows.h"
#include<cstdio>

void setWindowSize(int c, int r) {
	system("title GomokuLib");
	char cmd[30];
	sprintf_s(cmd,"mode con cols=%d lines=%d", r*2,c);
	system(cmd);
}

void setCursorPosition(int x, int y) {
	COORD pos;
	pos.X = y * 2;
	pos.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setColor(int col) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}