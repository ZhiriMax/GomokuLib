#ifndef  BOARD_H
#define BOARD_H
#include<string>
#include"windows.h"
using namespace std;
struct chessPoint {
	short x, y, color;	//0表示黑色，1表示白色
};

class board {
public:
	board();
	~board() {};
	void reset();
	void setTime();
	void decMaxNum();
	void setSysTime(SYSTEMTIME);
	void update(chessPoint);	//(x,y) 坐标 以及 棋子color，0表示黑色，1表示白色
	virtual void printBoard() const;	//打印棋盘
	void repent();	//悔棋操作
	void lastBoard();
	void nextBoard();
	virtual void setWhosTurn(bool);		//设置当前下棋方
	void setCurrentpoint(int);
	void setPlayerB(string);		//设置棋手名字
	void setPlayerW(string);
	void setPlayerBRank(string);
	void setPlayerWRank(string);
	void setPlace(string);
	void setGameName(string);
	void setUserName(string);
	void setSize(int);
	void setCurPos(int, int);
	int getMaxNum() const;
	chessPoint getNextChess();
	bool isFree(int,int);	//判断(x,y)上是否为空
	int getChessNum() const;	//获取棋盘总棋数
	int getChessColor(int, int) const;
	int getSize()const;
	int getCurPosX() const;
	int getCurPosY() const;
	SYSTEMTIME getTime() const;
	virtual int getWhosTurn() const;
	string getPlayerB() const;
	string getPlayerW() const;
	string getPlayerBRank() const;
	string getPlayerWRank() const;
	string getPlace() const;
	string getGameName() const;
	string getUserName() const;
	string getResult() const;
	chessPoint getChessOrder(int) const;
	virtual short judge(int,int) ;	//判断游戏局面 1：(x,y)所代表的子胜；0：平局； -1：游戏未结束
private:
	string playerB = "", playerW = "", gameName = "", place = "", 
			userName = "", result = "", playerBRank = "", playerWRank = "";//棋盘的各类属性
	SYSTEMTIME gameTime;
	int whosTurn=true;//true-黑棋，false-白棋
	int size;
	int maxNum; //棋盘所能放下最多的棋子数目
	int curPosX, curPosY;
	int currentPoint = 0;
	int chessNum = 0;
	int chessOrder[362][3];	//chessOrder[i][0] 表示第i个棋子的颜色（0表示黑色，1表示白色）	chessOrder[i][1/2] 则分别表示第i个棋子的坐标（x,y）
	int chessBoard[35][35];
};

#endif // ! BOARD_H
