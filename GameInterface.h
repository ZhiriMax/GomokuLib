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
	//	Menu返回值规定：一级菜单：1-10；二级菜单：11-30；三级菜单：31-40；四级菜单 41-50；
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
	int gameType; //1: 人-人对战；2：人-机对战；3:棋谱模拟；4：创意工坊
	int key[10];//key[i] 表示第i级选择;
};
#endif // !GAMEINTERFACE_H
