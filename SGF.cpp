#include"SGF.h"
#include"Board.h"
#include<iostream>
#include<fstream>
#include<cstring>

sgf::sgf() {
	memset(chessOrder, 0, sizeof(chessOrder));
	memset(chessBoard, 0, sizeof(chessBoard));
}

bool sgf::setInFile(string fileName){
	sgfIn.open(fileName, ios::in);
	if (!sgfIn) {
		cout << "文件打开失败，请检查文件存放位置及名称";
		return false;
	}
	else {
		cout << "文件打开成功";
		return true;
	}
}

void sgf::setOutFile(string fileName) {
	sgfOut.open(fileName,ios::out);
}

void sgf::sgfAnalysis() {
	//getline(sgfIn, sgfOrig); 入读方法2
	sgfIn >> sgfOrig;
	chessNum = 0;
	memset(chessBoard, 0, sizeof(chessBoard));	//初始化棋局记录
	memset(chessOrder, 0, sizeof(chessOrder));
	int pos = 0,braNum=0;//pos 当前sgf字符串处理的指针位置，braNum 当前括号圆括号未配对个数；
	string type, txt;			//type[txt] : sgf中的通用表达
	while (pos < sgfOrig.size() && sgfOrig[pos] != '(') ++pos;
	if (sgfOrig[pos] == '(') ++pos, ++braNum;
	while (pos < sgfOrig.size()) {			
		while (pos < sgfOrig.size() && sgfOrig[pos] != ';') ++pos;
		if (sgfOrig[pos] == ';') ++pos;
		while (pos < sgfOrig.size() && sgfOrig[pos] != ';') {
			type = ""; txt = "";		//z找到新一个  ;type[txt] 的位置 初始化type、txt
			while (pos < sgfOrig.size() && sgfOrig[pos] != '[') {
				type += sgfOrig[pos];
				++pos;
			}
			if (pos < sgfOrig.size() && sgfOrig[pos] == '[') ++pos;
			while (pos < sgfOrig.size() && sgfOrig[pos] != ']') {
				txt += sgfOrig[pos];
				++pos;
			}
			if (pos < sgfOrig.size() && sgfOrig[pos] == ']') ++pos;
			if (type == ")") {
				--braNum;
				cout << "Analysis Finish" << endl;
				cout << "The size is : " << size << endl;
				sgfIn.close();
				//if (braNum == 0) return;
				return;
			}
			if (type == "B") {		//Black的棋步
				++chessNum;
				chessOrder[chessNum][0] = 0;
				chessOrder[chessNum][1] = txt[0] - 'a' + 1;
				chessOrder[chessNum][2] = txt[1] - 'a' + 1;
				chessBoard[chessOrder[chessNum][1]][chessOrder[chessNum][2]] = chessOrder[chessNum][0];
			}
			if (type == "W") {		//White的棋步
				++chessNum;
				chessOrder[chessNum][0] = 1;
				chessOrder[chessNum][1] = txt[0] - 'a' + 1;
				chessOrder[chessNum][2] = txt[1] - 'a' + 1;
				chessBoard[chessOrder[chessNum][1]][chessOrder[chessNum][2]] = chessOrder[chessNum][0];
			}
			if (type == "C") {
				comment[chessNum] = txt;
			}
			if (type == "GM") {	//游戏类型
				gameType = stoi(txt);
			}
			if (type == "SZ") {	//棋盘大小
				size = stoi(txt);
			}
			if (type == "AP") {	//生成棋谱应用
				app = txt;
			}
			if (type == "DT") {	//游戏时间
				gameTime = txt;
				string y="", m="", d="";
				int cp = 0;
				while (txt[cp] != '-') y += txt[cp], ++cp;
				++cp;
				while (txt[cp] != '-') m += txt[cp], ++cp;
				++cp;
				for (int i = cp; i < txt.size(); i++) d += txt[i];
				gameSysTime.wYear= stoi(y);
				gameSysTime.wMonth = stoi(m);
				gameSysTime.wDay = stoi(d);
			}
			if (type == "PB") {	//Black玩家名字
				playerB = txt;
			}
			if (type == "BR") {	//Black玩家段位
				playerBRank = txt;
			}
			if (type == "PW") {	//White玩家名字
				playerW = txt;
			}
			if (type == "WR") {	//White玩家段位
				playerWRank = txt;
			}
			if (type == "GN" || type=="EV") {	//游戏棋局名称
				gameName = txt;
			}
			if (type == "PC") {	//游戏地点
				place = txt;
			}
			if (type == "RE") {	//游戏结果 - 黑胜/白胜
				result = txt;
			}
		}
	}
	
}

void sgf::sgfUpdate(board &Gomoku) {	//从主棋盘中更新类记录
	memset(comment, 0, sizeof(comment));
	chessNum = Gomoku.getChessNum();
	size = Gomoku.getSize();
	app = "GomokuLib";
	gameSysTime = Gomoku.getTime();	//将gameSysTime 转换为 字符串gameTime
	gameTime = to_string(gameSysTime.wYear) + "-" + to_string(gameSysTime.wMonth) + "-" + to_string(gameSysTime.wDay);
	gameName = Gomoku.getGameName();
	playerB = Gomoku.getPlayerB();
	playerBRank = Gomoku.getPlayerBRank();
	playerW = Gomoku.getPlayerW();
	playerWRank = Gomoku.getPlayerWRank();
	userName = Gomoku.getUserName();
	place = Gomoku.getPlace();
	gameType = 4;
	chessPoint tmp;
	for (int i = 1; i <= chessNum; i++) {
		tmp = Gomoku.getChessOrder(i);
		chessOrder[i][0] = tmp.color;
		chessOrder[i][1] = tmp.x;
		chessOrder[i][2] = tmp.y;
		chessBoard[tmp.x][tmp.y] = tmp.color;
	}
}

void sgf::sgfPrint() {
	sgfOut << "(";
	//棋局基本信息导出
	sgfOut << ";";
	if (gameType != -1) {
		sgfOut << "GM[" << gameType << "]";
	}
	if (size != -1) {
		sgfOut << "SZ[" << size << "]";
	}
	if (app != "") {
		sgfOut << "AP[" << app << "]";
	}
	if (gameTime != "") {
		sgfOut << "DT[" << gameTime << "]";
	}
	if (playerB != "") {
		sgfOut << "PB[" << playerB << "]";
	}
	if (playerBRank != "") {
		sgfOut << "BR[" << playerBRank << "]";
	}
	if (playerW != "") {
		sgfOut << "PW[" << playerW << "]";
	}
	if (playerWRank != "") {
		sgfOut << "WR[" << playerWRank << "]";
	}
	if (gameName != "") {
		sgfOut << "GN[" << gameName << "]";
	}
	if (place != "") {
		sgfOut << "PC[" << place << "]";
	}
	if (result != "") {
		sgfOut << "RE[" << result << "]";
	}
	//棋局棋步信息导出
	for (int i = 1; i <= chessNum; i++) {
		sgfOut << ";";
		if (chessOrder[i][0] == 0) sgfOut << "B";
		if (chessOrder[i][0] == 1) sgfOut << "W";
		sgfOut << "[" << char(chessOrder[i][1] + 'a' - 1)<<char( chessOrder[i][2] + 'a' - 1 )<< "]";
		sgfOut << "C[" << comment[i] << "]";
	}
	sgfOut << ";)";
	sgfOut.close();
}

void sgf::boardUpdate(board &Gomoku){
	chessPoint tmp;
	Gomoku.setSize(size);
	Gomoku.setPlayerB(playerB);
	Gomoku.setPlayerW(playerW);
	Gomoku.setPlayerBRank(playerBRank);
	Gomoku.setPlayerWRank(playerWRank);
	Gomoku.setGameName(gameName);
	Gomoku.setPlace(place);
	Gomoku.setSysTime(gameSysTime);
	for (int i = 1; i <= chessNum; i++) {
		
		tmp.x = chessOrder[i][1];
		tmp.y = chessOrder[i][2];
		tmp.color = chessOrder[i][0];
		Gomoku.update(tmp);
		
	}
}