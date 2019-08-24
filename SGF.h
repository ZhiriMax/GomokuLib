#ifndef SGF_H
#define SGF_H
#include<string>
#include<fstream>
#include"Board.h"
using namespace std;
class sgf {
public:
	sgf();
	~sgf() {};
	bool setInFile(string);
	void setOutFile(string);
	void sgfAnalysis();
	void sgfUpdate(board&);	//从棋谱中更新sgf中的记录
	void sgfPrint();
	void boardUpdate(board &);//将sgf Analysis的数据导入board
private:
	fstream sgfIn, sgfOut;
	int gameType=-1, size=-1;
	string app="",playerB = "",playerW = "",gameName = "",place = "",
			userName = "",gameTime = "",result = "",playerBRank = "",playerWRank = "";//棋盘的各类属性
	string comment[362];//comment[i] 表示第i步的comment
	string sgfOrig;	//初始未处理的SGF文件字符串
	SYSTEMTIME gameSysTime;
	int chessNum = 0;
	int chessOrder[362][3];
	int chessBoard[20][20];
};
#endif // !SGF_H
