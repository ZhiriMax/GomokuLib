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
	void sgfUpdate(board&);	//�������и���sgf�еļ�¼
	void sgfPrint();
	void boardUpdate(board &);//��sgf Analysis�����ݵ���board
private:
	fstream sgfIn, sgfOut;
	int gameType=-1, size=-1;
	string app="",playerB = "",playerW = "",gameName = "",place = "",
			userName = "",gameTime = "",result = "",playerBRank = "",playerWRank = "";//���̵ĸ�������
	string comment[362];//comment[i] ��ʾ��i����comment
	string sgfOrig;	//��ʼδ�����SGF�ļ��ַ���
	SYSTEMTIME gameSysTime;
	int chessNum = 0;
	int chessOrder[362][3];
	int chessBoard[20][20];
};
#endif // !SGF_H
