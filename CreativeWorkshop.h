#ifndef CREATIVE_WORKSHOP_H
#define CREATIVE_WORKSHOP_H

#include"Board.h"
#include<fstream>

using namespace std;

class creative:public board {
public:
	creative();
	~creative() {};
	bool setRulesIn(string);
	void setRulesOut(string);
	void saveRules();
	void setPlayerNum(int);
	void setChessColor(int, int);
	int getPlayerNum();
	void rulesAnalysis();
	void printBoard() const;
	void printRules() const;
	void showRules() const;//游戏界面展示rules
	void updateRules(int, int);
	void deleteBoardRules(int, int);
	void resetRules();	//重置获胜规则
	void resetBoardRules();	//重置棋盘形状
	void setWhosTurn(int);
	void setRules();
	void setBoardRules();
	bool isLegal(int, int);//判断(x,y)点的格子能否删除
	bool canSet(int, int); //判断(x,y)格子能否下棋;
	int getWhosTurn() const;
	int getOnesColor(int) const;
	string getOnesType(int) const;
	short judge(int, int);
	

private:
	bool rules[5][5];	//false表示不考虑，true表示考虑
	bool boardRules[33][33];	//false不可以下，true可以下
	int whosTurn,playerNum;
	string chessType[5] = {"●","○","⊙","◇","⊕"};
	fstream rulesIn, rulesOut;
	int color[5];
};

#endif // !CREATIVE_WORKSHOP_H


