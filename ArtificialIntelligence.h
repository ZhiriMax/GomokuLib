#ifndef  ARTIFICIAL_INTELLIGENCE_H
#define ARTIFICIAL_INTELLIGENCE_H

#include"Board.h"

class ai {
public:
	void updateFromBoard(board &);
	bool isSame(int, int, int, int);
	bool isLegal(int, int);
	int liveFour(int, int);
	int liveThree(int, int);
	int chongFour(int, int);
	int point(int, int);
	bool isEnd(int, int);
	int search2();
	int search3(int);
	chessPoint getPoint(board &,int);

private:
	int chessBoard[30][30];
	int size = 15;
	int color = 0;
	int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 }; //向多个方向搜索
	int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	chessPoint ans;

};

#endif // ! ARTIFICIAL_INTELLIGENCE_H
