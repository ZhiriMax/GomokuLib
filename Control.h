#ifndef CONTROL_H
#define CONTROL_h
#include"Board.h"
#include"GameInterface.h"
#include"SGF.h"
#include"Tools.h"
using namespace std;

void commonGomoku();
void sgfReadIn();
void creativeGame1(creative &);	//设置规则、导出规则
void creativeGmae2(creative &);	//导入规则
void creativeGame(int);	//正式游戏
void AIGame(int);
#endif // !CONTROL_H
