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
	void showRules() const;//��Ϸ����չʾrules
	void updateRules(int, int);
	void deleteBoardRules(int, int);
	void resetRules();	//���û�ʤ����
	void resetBoardRules();	//����������״
	void setWhosTurn(int);
	void setRules();
	void setBoardRules();
	bool isLegal(int, int);//�ж�(x,y)��ĸ����ܷ�ɾ��
	bool canSet(int, int); //�ж�(x,y)�����ܷ�����;
	int getWhosTurn() const;
	int getOnesColor(int) const;
	string getOnesType(int) const;
	short judge(int, int);
	

private:
	bool rules[5][5];	//false��ʾ�����ǣ�true��ʾ����
	bool boardRules[33][33];	//false�������£�true������
	int whosTurn,playerNum;
	string chessType[5] = {"��","��","��","��","��"};
	fstream rulesIn, rulesOut;
	int color[5];
};

#endif // !CREATIVE_WORKSHOP_H


