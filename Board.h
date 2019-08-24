#ifndef  BOARD_H
#define BOARD_H
#include<string>
#include"windows.h"
using namespace std;
struct chessPoint {
	short x, y, color;	//0��ʾ��ɫ��1��ʾ��ɫ
};

class board {
public:
	board();
	~board() {};
	void reset();
	void setTime();
	void decMaxNum();
	void setSysTime(SYSTEMTIME);
	void update(chessPoint);	//(x,y) ���� �Լ� ����color��0��ʾ��ɫ��1��ʾ��ɫ
	virtual void printBoard() const;	//��ӡ����
	void repent();	//�������
	void lastBoard();
	void nextBoard();
	virtual void setWhosTurn(bool);		//���õ�ǰ���巽
	void setCurrentpoint(int);
	void setPlayerB(string);		//������������
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
	bool isFree(int,int);	//�ж�(x,y)���Ƿ�Ϊ��
	int getChessNum() const;	//��ȡ����������
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
	virtual short judge(int,int) ;	//�ж���Ϸ���� 1��(x,y)���������ʤ��0��ƽ�֣� -1����Ϸδ����
private:
	string playerB = "", playerW = "", gameName = "", place = "", 
			userName = "", result = "", playerBRank = "", playerWRank = "";//���̵ĸ�������
	SYSTEMTIME gameTime;
	int whosTurn=true;//true-���壬false-����
	int size;
	int maxNum; //�������ܷ�������������Ŀ
	int curPosX, curPosY;
	int currentPoint = 0;
	int chessNum = 0;
	int chessOrder[362][3];	//chessOrder[i][0] ��ʾ��i�����ӵ���ɫ��0��ʾ��ɫ��1��ʾ��ɫ��	chessOrder[i][1/2] ��ֱ��ʾ��i�����ӵ����꣨x,y��
	int chessBoard[35][35];
};

#endif // ! BOARD_H
