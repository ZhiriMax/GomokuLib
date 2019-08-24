#include "Board.h"
#include"Tools.h"
#include<cstring>
#include<string>
#include<iostream>
#include<iomanip>

board::board() {
	GetLocalTime(&gameTime);
	memset(chessOrder, 0, sizeof(chessOrder));
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			chessBoard[i][j] = -1;
}

void board::reset() {
	memset(chessOrder, 0, sizeof(chessOrder));
	GetLocalTime(&gameTime);
	currentPoint = 0;
	chessNum = 0;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			chessBoard[i][j] = -1;
}

void board::setTime() {
	GetLocalTime(&gameTime);
}

void board::setSysTime(SYSTEMTIME time) {
	gameTime = time;
}

void board::decMaxNum() {
	if (maxNum > 0) --maxNum;
}

void board::update(chessPoint chess) {
	if (chessBoard[chess.x][chess.y] == -1) {
		++chessNum;
		++currentPoint;
		chessOrder[chessNum][0] = chess.color;
		chessOrder[chessNum][1] = chess.x;
		chessOrder[chessNum][2] = chess.y;
		chessBoard[chess.x][chess.y] = chess.color;
	}
}

void board::printBoard() const {
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (int i = 0; i <= size; i++) {
		setCursorPosition(ceil(12.5 - size / 2.0) + i, ceil(12.5 - size / 2.0));
		for (int j = 0; j <= size; j++) {
			if (chessBoard[i][j] == -1) {
				//
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				if (i == curPosX && j == curPosY) { cout << "■"; continue; }
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				//棋盘边界打印
				if (i != 0 && j==0 ) cout <<setw(2)<< i << " ";
				if (i == 0) {
					if (j == 0) cout << "   ";
					else cout << setw(2)<<char(j+'a'-1);
				}
				if (i == 1) {
					if (j == 1)  cout << "┌ ";
					else if (j == size) cout << "┐ ";
						else if (j>1 && j<size) cout << "┬ ";
				}
				if (i == size) {
					if (j==1)  cout << "└ ";
					else if (j == size) cout << "┘ ";
						else if (j > 1 && j < size) cout << "┴ ";
				}
				if (i > 1 && i < size) {
					if (j == 1) cout << "├ ";
					else if (j == size) cout << "┤ ";
						else if (j > 1 && j < size) cout << "┼ ";
				}
			}
			else {	//棋子打印
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				if (i == curPosX && j == curPosY) { cout << "■"; continue; }
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				if (i == chessOrder[currentPoint][1] && j == chessOrder[currentPoint][2]) setColor(3);
				if (chessBoard[i][j] == 1) cout << "●";
				else cout << "○";
			}
		}
		//	cout << endl;
		setCursorPosition(30, 0);
	}
}

void board::repent() {
	if (chessNum > 0) {
		chessBoard[chessOrder[chessNum][1]][chessOrder[chessNum][2]] = -1;
		chessOrder[chessNum][0] = 0;
		chessOrder[chessNum][1] = 0;
		chessOrder[chessNum][2] = 0;
		--chessNum;
		--currentPoint;
		//whosTurn = !whosTurn;
	}
}

void board::lastBoard() {
	if (currentPoint > 0) {
		chessBoard[chessOrder[currentPoint][1]][chessOrder[currentPoint][2]] = -1;
		--currentPoint;
		printBoard();
	}
}

void board::nextBoard() {
	if (currentPoint < chessNum) {
		++currentPoint;
		chessBoard[chessOrder[currentPoint][1]][chessOrder[currentPoint][2]] = chessOrder[currentPoint][0];
		printBoard();
	}
}

void board::setWhosTurn(bool wt) {
	whosTurn = wt;
}

void board::setCurrentpoint(int cp) {
	currentPoint = cp;
}

void board::setPlayerB(string pb) {
	playerB = pb;
}

void board::setPlayerW(string pw) {
	playerW = pw;
}

void board::setPlayerBRank(string br) {
	playerBRank = br;
}

void board::setPlayerWRank(string wr) {
	playerWRank = wr;
}

void board::setPlace(string p) {
	place = p;
}

void board::setGameName(string gn) {
	gameName = gn;
}

void board::setUserName(string un) {
	userName = un;
}

void board::setSize(int sz) {
	
	if (sz > 25) size = 25;
	else if (sz < 3) size = 3;
		else size = sz;
	
}

void board::setCurPos(int x, int y) {
	curPosX = x;
	curPosY = y;
}

chessPoint board::getNextChess() {
	chessPoint tmp;
	++currentPoint;
	tmp.x = chessOrder[currentPoint][1];
	tmp.y = chessOrder[currentPoint][2];
	tmp.color = chessOrder[currentPoint][0];
	return tmp;
}


int board::getChessNum() const {
	return chessNum;
}

int board::getWhosTurn() const {
	return whosTurn;
}

int board::getChessColor(int x, int y)const {
	return chessBoard[x][y];
}

int board::getSize() const {
	return size;
}

int board::getCurPosX() const {
	return curPosX;
};

int board::getCurPosY() const {
	return curPosY;
};

int board::getMaxNum() const {
	return maxNum;
}

SYSTEMTIME board::getTime() const{
	return gameTime;
}

string board::getPlayerB() const{
	return playerB;
}

string board::getPlayerW() const {
	return playerW;
}

string board::getPlayerBRank() const {
	return playerBRank;
}

string board::getPlayerWRank() const {
	return playerWRank;
}

string board::getPlace() const {
	return place;
}

string board::getGameName() const {
	return gameName;
}

string board::getUserName() const {
	return userName;
}

string board::getResult() const {
	return result;
}

bool board::isFree(int x, int y) {
	if (chessBoard[x][y] == -1) return true;
	else return false;
}


chessPoint board::getChessOrder(int cp) const{ //cp-currentPoint
	chessPoint tmp;
	tmp.x = chessOrder[cp][1];
	tmp.y= chessOrder[cp][2];
	tmp.color = chessOrder[cp][0];
	return tmp;
}

short board::judge(int x,int y) {
	int count;
	int pos_x, pos_y;
	//横向遍历，找到(x,y)点横向的最大连子数；
	count = 1; pos_y = y;
	while (chessBoard[x][--pos_y] == chessBoard[x][y] && pos_y >=1) ++count;
	pos_y = y;
	while (chessBoard[x][++pos_y] == chessBoard[x][y] && pos_y <=size) ++count;
	if (count >= 5) {
		if (chessBoard[x][y] == 0) result = "黑胜";
		if (chessBoard[x][y] == 1) result = "白胜";
		return 1;
	}
	//纵向遍历，找到(x,y)点纵向的最大连子数;
	count = 1; pos_x = x;
	while (chessBoard[--pos_x][y] == chessBoard[x][y] && pos_x >= 1) ++count;
	pos_x = x;
	while (chessBoard[++pos_x][y] == chessBoard[x][y] && pos_x <= size) ++count;
	if (count >= 5) {
		if (chessBoard[x][y] == 0) result = "黑胜";
		if (chessBoard[x][y] == 1) result = "白胜";
		return 1;
	}
	//左上-> 右下遍历；
	count = 1; pos_x = x; pos_y = y;
	while (chessBoard[--pos_x][--pos_y] == chessBoard[x][y] && pos_x >= 1 && pos_y >= 1) ++count;
	pos_x = x; pos_y = y;
	while (chessBoard[++pos_x][++pos_y] == chessBoard[x][y] && pos_x <= size && pos_y <= size) ++count;
	if (count >= 5) {
		if (chessBoard[x][y] == 0) result = "黑胜";
		if (chessBoard[x][y] == 1) result = "白胜";
		return 1;
	}
	//右上->左下遍历；
	count = 1; pos_x = x; pos_y = y;
	while (chessBoard[--pos_x][++pos_y] == chessBoard[x][y] && pos_x >= 1 && pos_y <= size) ++count;
	pos_x = x; pos_y = y;
	while (chessBoard[++pos_x][--pos_y] == chessBoard[x][y] && pos_x <= size && pos_y >= 1) ++count;
	if (count >= 5) {
		if (chessBoard[x][y] == 0) result = "黑胜";
		if (chessBoard[x][y] == 1) result = "白胜";
		return 1;
	}
	if (chessNum == size * size) {
		result = "平局";
		return 0;
	}
	return -1;
}