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
		cout << "�ļ���ʧ�ܣ������ļ����λ�ü�����";
		return false;
	}
	else {
		cout << "�ļ��򿪳ɹ�";
		return true;
	}
}

void sgf::setOutFile(string fileName) {
	sgfOut.open(fileName,ios::out);
}

void sgf::sgfAnalysis() {
	//getline(sgfIn, sgfOrig); �������2
	sgfIn >> sgfOrig;
	chessNum = 0;
	memset(chessBoard, 0, sizeof(chessBoard));	//��ʼ����ּ�¼
	memset(chessOrder, 0, sizeof(chessOrder));
	int pos = 0,braNum=0;//pos ��ǰsgf�ַ��������ָ��λ�ã�braNum ��ǰ����Բ����δ��Ը�����
	string type, txt;			//type[txt] : sgf�е�ͨ�ñ��
	while (pos < sgfOrig.size() && sgfOrig[pos] != '(') ++pos;
	if (sgfOrig[pos] == '(') ++pos, ++braNum;
	while (pos < sgfOrig.size()) {			
		while (pos < sgfOrig.size() && sgfOrig[pos] != ';') ++pos;
		if (sgfOrig[pos] == ';') ++pos;
		while (pos < sgfOrig.size() && sgfOrig[pos] != ';') {
			type = ""; txt = "";		//z�ҵ���һ��  ;type[txt] ��λ�� ��ʼ��type��txt
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
			if (type == "B") {		//Black���岽
				++chessNum;
				chessOrder[chessNum][0] = 0;
				chessOrder[chessNum][1] = txt[0] - 'a' + 1;
				chessOrder[chessNum][2] = txt[1] - 'a' + 1;
				chessBoard[chessOrder[chessNum][1]][chessOrder[chessNum][2]] = chessOrder[chessNum][0];
			}
			if (type == "W") {		//White���岽
				++chessNum;
				chessOrder[chessNum][0] = 1;
				chessOrder[chessNum][1] = txt[0] - 'a' + 1;
				chessOrder[chessNum][2] = txt[1] - 'a' + 1;
				chessBoard[chessOrder[chessNum][1]][chessOrder[chessNum][2]] = chessOrder[chessNum][0];
			}
			if (type == "C") {
				comment[chessNum] = txt;
			}
			if (type == "GM") {	//��Ϸ����
				gameType = stoi(txt);
			}
			if (type == "SZ") {	//���̴�С
				size = stoi(txt);
			}
			if (type == "AP") {	//��������Ӧ��
				app = txt;
			}
			if (type == "DT") {	//��Ϸʱ��
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
			if (type == "PB") {	//Black�������
				playerB = txt;
			}
			if (type == "BR") {	//Black��Ҷ�λ
				playerBRank = txt;
			}
			if (type == "PW") {	//White�������
				playerW = txt;
			}
			if (type == "WR") {	//White��Ҷ�λ
				playerWRank = txt;
			}
			if (type == "GN" || type=="EV") {	//��Ϸ�������
				gameName = txt;
			}
			if (type == "PC") {	//��Ϸ�ص�
				place = txt;
			}
			if (type == "RE") {	//��Ϸ��� - ��ʤ/��ʤ
				result = txt;
			}
		}
	}
	
}

void sgf::sgfUpdate(board &Gomoku) {	//���������и������¼
	memset(comment, 0, sizeof(comment));
	chessNum = Gomoku.getChessNum();
	size = Gomoku.getSize();
	app = "GomokuLib";
	gameSysTime = Gomoku.getTime();	//��gameSysTime ת��Ϊ �ַ���gameTime
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
	//��ֻ�����Ϣ����
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
	//����岽��Ϣ����
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