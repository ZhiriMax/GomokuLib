#ifndef GAME_INTERFACE_H
#define GAME_INTERFACE_H
#include"Board.h"
#include"CreativeWorkshop.h"
#include"SGF.h"
class gameInterface {
public:
	~gameInterface(){}
	void start();
	void select();
	//	Menu����ֵ�涨��һ���˵���1-10�������˵���11-30�������˵���31-40���ļ��˵� 41-50��
	int firstMenu();
	int secondMenu();
	void thirdMenu(board &);
	int forthMenu();
	void fifthMenu(creative &);
	int sixthMenu();
	void seventhMenu(creative &);
	int eighthMenu();
	void drawGame();
	void boardClear(int,int);
	void creativeTips1()const;
	void creativeTips2()const;
	void creativeTips3()const;
	void sgfInterface(board &);
	void clearInfo(int,int) const;
private:
	int gameType; //1: ��-�˶�ս��2����-����ս��3:����ģ�⣻4�����⹤��
	int key[10];//key[i] ��ʾ��i��ѡ��;
};
#endif // !GAMEINTERFACE_H
