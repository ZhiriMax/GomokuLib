#ifndef CONTROL_H
#define CONTROL_h
#include"Board.h"
#include"GameInterface.h"
#include"SGF.h"
#include"Tools.h"
using namespace std;

void commonGomoku();
void sgfReadIn();
void creativeGame1(creative &);	//���ù��򡢵�������
void creativeGmae2(creative &);	//�������
void creativeGame(int);	//��ʽ��Ϸ
void AIGame(int);
#endif // !CONTROL_H
