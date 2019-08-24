#include"CreativeWorkshop.h"
#include"Tools.h"
#include<cstring>
#include<iomanip>
#include<iostream>
#include<conio.h>

using namespace std;

creative::creative() {
	memset(boardRules, false, sizeof(boardRules));
	memset(rules, false, sizeof(rules));
}

bool creative::setRulesIn(string name) {
	rulesIn.open(name, ios::in);
	if (!rulesIn) {
		cout << "文件打开失败，请检查文件存放位置及名称";
		return false;
	}
	else {
		cout << "文件打开成功";
		return true;
	}
}

void creative::setRulesOut(string name) {
	rulesOut.open(name, ios::out);
}

void creative::saveRules() {
	rulesOut << playerNum << " " << getSize() << endl;
	for (int i = 0; i < playerNum; i++) rulesOut << color[i] << " ";
	rulesOut << endl;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			if (rules[i][j]) rulesOut << "1 ";
			else rulesOut << "0 ";
		}
	}
	rulesOut << endl;
	for (int i = 1; i <= getSize(); i++) {
		for (int j = 1; j <= getSize(); j++) {
			if (boardRules[i][j]) rulesOut << "1 ";
			else rulesOut << "0 ";
		}
		rulesOut << endl;
	}
	rulesOut.close();

}

void creative::setPlayerNum(int pn) {
	playerNum = pn;
}

void creative::setChessColor(int a, int c) {
	color[a] = c;
}

int creative::getPlayerNum() {
	return playerNum;
}

int creative::getOnesColor(int i) const {
	return color[i];
}

string creative::getOnesType(int i)const {
	return chessType[i];
}

void creative::rulesAnalysis() {
	int size_tmp = 0, rules_tmp=0;
	rulesIn >> playerNum >> size_tmp;
	setSize(size_tmp);
	for (int i = 0; i < playerNum; i++) {
		rulesIn >> color[i];
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			rulesIn >> rules_tmp;
			if (rules_tmp == 0) rules[i][j] = false;
			else rules[i][j] = true;
		}
	}
	for (int i = 1; i <= size_tmp; i++) {
		for (int j = 1; j <= size_tmp; j++) {
			rulesIn >> rules_tmp;
			if (rules_tmp == 0) boardRules[i][j] = false;
			else boardRules[i][j] = true;
		}
	}
}

void creative::printBoard() const {
	int size = getSize();
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (int i = 0; i <= size; i++) {
		setCursorPosition(ceil(12.5 - size / 2.0) + i, ceil(12.5 - size / 2.0));
		for (int j = 0; j <= size; j++) {
			if (getChessColor(i, j) == -1) {
				//光标打印
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				if (i == getCurPosX() && j == getCurPosY()) { cout << "■"; continue; }
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				//棋盘边界打印
				if (i != 0 && j == 0) cout << setw(2) << i << " ";
				if (i == 0) {
					if (j == 0) cout << "   ";
					else cout << setw(2) << char(j + 'a' - 1);
				}
				if (boardRules[i][j]) {

					if (i >= 1 && j >= 1) {
						if (boardRules[i - 1][j] == 0) {
							if (boardRules[i][j - 1] == 0) cout << "┌ ";
							else if (boardRules[i][j + 1] == 0) cout << "┐ ";
								else  cout << "┬ ";
						}
						if (boardRules[i + 1][j] == 0 && boardRules[i - 1][j] != 0) {
							if (boardRules[i][j - 1] == 0) cout << "└ ";
							else if (boardRules[i][j + 1] == 0) cout << "┘ ";
								else  cout << "┴ ";
							
						}
						if (boardRules[i + 1][j] != 0 && boardRules[i - 1][j] != 0) {
							if (boardRules[i][j - 1] == 0) cout << "├ ";
							else if (boardRules[i][j + 1] == 0) cout << "┤ ";
								else cout << "┼ ";
							
						}
					}
				}
				else {
					if (i>=1 && j>=1) cout << "  ";
				}
			}
			else {	//棋子打印
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				if (i == getCurPosX() && j == getCurPosY()) { cout << "■"; continue; }
				setColor(color[getChessColor(i, j)]); cout << chessType[getChessColor(i, j)];
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			}
		}
		//	cout << endl;
		setCursorPosition(30, 0);
	}
}

void creative::printRules() const {
	int size = 3;
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (int i = 1; i <= size; i++) {
		setCursorPosition(8 + i, 12);
		for (int j = 1; j <= size; j++) {
			if (!rules[i][j]) {
				//光标打印
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				if (i == getCurPosX() && j == getCurPosY()) { cout << "■"; continue; }
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				//棋盘边界打印
				if (i == 1) {
					if (j == 1)  cout << "┌ ";
					else if (j == size) cout << "┐ ";
					else if (j > 1 && j < size) cout << "┬ ";
				}
				if (i == size) {
					if (j == 1)  cout << "└ ";
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
				if (i == getCurPosX() && j == getCurPosY()) { cout << "■"; continue; }
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "●";
			}
		}
		//	cout << endl;
		setCursorPosition(30, 0);
	}
}

void creative::showRules() const {
	int size = 3;
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (int i = 1; i <= size; i++) {
		setCursorPosition(19 + i, 35);
		for (int j = 1; j <= size; j++) {
			if (!rules[i][j]) {
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				//棋盘边界打印
				if (i == 1) {
					if (j == 1)  cout << "┌ ";
					else if (j == size) cout << "┐ ";
					else if (j > 1 && j < size) cout << "┬ ";
				}
				if (i == size) {
					if (j == 1)  cout << "└ ";
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
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "●";
			}
		}
		//	cout << endl;
		setCursorPosition(30, 0);
	}
}

void creative::updateRules(int x, int y) {
	if (!rules[x][y]) rules[x][y] = true;
}

void creative::deleteBoardRules(int x, int y) {
	boardRules[x][y] = false;
	decMaxNum();
}

void creative::resetRules() {
	memset(rules, 0, sizeof(rules));
}

void creative::resetBoardRules() {
	int size = getSize();
	for (int i = 0; i <= 30; i++) {
		for (int j = 0; j <= 30; j++) {
			if (i>=1 && i<=size && j>=1 && j<=size ) boardRules[i][j] = true;
			else boardRules[i][j] = false;
		}
	}
}

void creative::setWhosTurn(int t) {
	whosTurn = t % playerNum;
}

void creative::setRules() {
	int ch, x, y;
	bool flag = false;
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (int i = 2; i <= 26; i++) {
		setCursorPosition(i, 2); cout << "                                                  ";
	}
	setCursorPosition(10, 10); cout << "请输入获胜棋形：";
	setCursorPosition(13, 20); cout << "输入完成";
	x = 1; y = 1;
	setCurPos(x, y);
	while (1) {
		printRules();
		while (ch = _getch()) {
			switch (ch) {
			case 72: //上
				if (x > 0) {
					setCurPos(--x, y);
					printRules();
				}
				break;
			case 80://下
				if (x < 4) {
					setCurPos(++x, y);
					printRules();
				}
				break;
			case 75://左
				if (y > 0 && y <= 3) {
					setCurPos(x, --y);
					printRules();
				}
				if (y > 3) {
					setCurPos(x, --y);
					setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					setCursorPosition(13, 20); cout << "输入完成";
				}
				break;
			case 77://右
				if (y == 3) {
					setCurPos(x, ++y);
					setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					setCursorPosition(13, 20); cout << "输入完成";
				}
				if (y < 3) {
					setCurPos(x, ++y);
					printRules();
				}
				break;
			case 32:
			case 13:
				if (y <= 3)
					updateRules(x, y);
				else flag = true;
				break;
			}
		}
		if (flag) break;
	}
}

void creative::setBoardRules() {
	for (int i = 2; i <= 26; i++) {
		setCursorPosition(i, 2); cout << "                                                  ";
	}
	int size = getSize();

	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (int i = 0; i <= size; i++) {
		setCursorPosition(ceil(12.5 - size / 2.0) + i, ceil(12.5 - size / 2.0));
		for (int j = 0; j <= size; j++) {
			if (!boardRules[i][j]) {
				//
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				if (i == getCurPosX() && j == getCurPosY()) { cout << "■"; continue; }
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				//棋盘边界打印
				if (i != 0 && j == 0) cout << setw(2) << i << " ";
				if (i == 0) {
					if (j == 0) cout << "   ";
					else cout << setw(2) << char(j + 'a' - 1);
				}
				if (i == 1) {
					if (j == 1)  cout << "┌ ";
					else if (j == size) cout << "┐ ";
					else if (j > 1 && j < size) cout << "┬ ";
				}
				if (i == size) {
					if (j == 1)  cout << "└ ";
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
				if (i == getCurPosX() && j == getCurPosY()) { cout << "■"; continue; }
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				if (boardRules[i][j]) cout << "●";
			}
		}
		//	cout << endl;
		setCursorPosition(30, 0);
	}

}

bool creative::isLegal(int x, int y) {
	if (x >= 2 && boardRules[x - 2][y] && boardRules[x][y])   return true;
	if (boardRules[x + 2][y] && boardRules[x][y]) return true;
	if (y >= 2 && boardRules[x][y - 2] && boardRules[x][y]) return true;
	if (boardRules[x][y + 2] && boardRules[x][y]) return true;
	return false;
}

bool creative::canSet(int x, int y) {
	if (boardRules[x][y] && getChessColor(x, y) == -1) return true;
	else return false;
}

int creative::getWhosTurn() const {
	return whosTurn;
}

short creative::judge(int x, int y) {
	bool flag = true, res = false;
	int rulesX, rulesY;
	int size = getSize();
	//case 1棋子位于九宫格左上角;
	if (rules[1][1]) {
		//case 1
		if (x + 2 <= size && y + 2 <= size) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x + i - 1, y + j - 1) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 2
		if (x - 2 >= 1 && y + 2 <= size) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x - j + 1, y + i - 1) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 3
		if (x - 2 >= 1 && y - 2 >= 1) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x - i + 1, y - j + 1) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 4
		if (x + 2 <= size && y - 2 >= 1) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x + j - 1, y - i + 1) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}
	}
	//case 2棋子位于第一行第二列;
	if (rules[1][2]) {
		//case 1
		if (x + 2 <= size && y + 1 <= size && y - 1 >= 1) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x + i - 1, y + j - 2) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 2
		if (x + 1 <= size && x - 1 >= 1 && y + 2 <= size) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x - j + 2, y + i - 1) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 3
		if (x - 2 >= 1 && y - 1 >= 1 && y + 1 <= size) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x - i + 1, y - j + 2) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 4
		if (x - 1 >= 1 && x + 1 <= size && y - 2 >= 1) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x + j - 2, y - i + 1) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}
	}
	//case 3棋子位于第一行第三列;
	if (rules[1][3]) {
		//case 1
		if (x + 2 <= size && y - 2 >= 1) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x + i - 1, y + j - 3) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 2
		if (x + 2 <= size && y + 2 <= size) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x - j + 3, y + i - 1) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 3
		if (x - 2 >= 1 && y + 2 <= size) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x - i + 1, y - j + 3) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 4
		if (x - 2 >= 1 && y - 2 >= 1) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x + j - 3, y - i + 1) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}
	}
	//case 4棋子位于第二行第一列;
	if (rules[2][1]) {
		//case 1
		if (x - 1 >= 1 && x + 1 <= size && y + 2 <= size) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x + i - 2, y + j - 1) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 2
		if (x - 2 >= 1 && y + 1 <= size && y - 1 >= 1) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x - j + 1, y + i - 2) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 3
		if (x + 1 <= size && x - 1 >= 1 && y - 2 >= 1) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x - i + 2, y - j + 1) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 4
		if (x + 2 <= size && y - 1 >= 1 && y + 1 <= size) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x + j - 1, y - i + 2) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}
	}
	//case 5棋子位于棋盘中央;
	if (rules[2][2]) {
		//case 1
		if (x - 1 >= 1 && x + 1 <= size && y + 1 <= size && y - 1 >= 1) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x + i - 2, y + j - 2) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 2
		if (x + 1 <= size && x - 1 >= 1 && y + 1 <= size && y - 1 >= 1) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x - j + 2, y + i - 2) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 3
		if (x + 1 <= size && x - 1 >= 1 && y - 1 >= 1 && y + 1 <= size) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x - i + 2, y - j + 2) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 4
		if (x - 1 >= 1 && x + 1 <= size && y - 1 >= 1 && y + 1 <= size) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x + j - 2, y - i + 2) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}
	}
	//case 6棋子位于棋盘第二行第三列：
	if (rules[2][3]) {
		//case 1
		if (x - 1 >= 1 && x + 1 <= size && y - 2 >= 1) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x + i - 2, y + j - 3) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 2
		if (x + 2 <= size && y + 1 <= size && y - 1 >= 1) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x - j + 3, y + i - 2) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 3
		if (x + 2 <= size && y - 1 >= 1 && y + 1 <= size) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x - i + 2, y - j + 3) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 4
		if (x - 2 >= 1 && y - 1 >= 1 && y + 1 <= size) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x + j - 3, y - i + 2) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}
	}
	//case 7棋子位于棋盘第三行第一列：
	if (rules[3][1]) {
		//case 1
		if (x - 2 >= 1 && y + 2 <= size) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x + i - 3, y + j - 1) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 2
		if (x - 2 >= 1 && y -2>=1) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x - j + 1, y + i - 3) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 3
		if (x - 2 >= 1 && y + 2 <=size) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x - i + 3, y - j + 1) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 4
		if (x + 2 <= size && y +2<=size) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x + j - 1, y - i + 3) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}
	}
	//case 8 棋子位于棋盘第三行第二列：
	if (rules[3][2]) {
		//case 1
		if (x - 2 >=1 && y + 1 <= size && y-1>=1) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x + i - 3, y + j - 2) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 2
		if (x - 1 >= 1 && x+1<=size && y -2>=1) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x - j + 2, y + i - 3) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 3
		if (x + 2 <=size && y+1<=size && y-1>=1) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x - i + 3, y - j + 2) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 4
		if (x-1>=1 && x + 1 <= size && y +2 <=size) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x + j - 2, y - i + 3) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}
	}
	//case 9棋子位于左下角;
	if (rules[3][3]) {
		//case 1
		if (x  -2>=1 && y - 2 >=1) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x + i - 3, y + j - 3) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 2
		if (x + 2 <= size && y -2 >=1) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x - j + 3, y + i - 3) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 3
		if (x + 2 <=size && y + 2 <= size) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x - i + 3, y - j + 3) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}

		//case 4
		if (x -2 >=1 && y +2<=size) {
			flag = true;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (rules[i][j]) {
						if (getChessColor(x + j - 3, y - i + 3
) != getChessColor(x, y)) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (flag) res = true;
		}
	}

	if (res) return 1;
	else if (getChessNum() == getMaxNum()) return 0;
	else return -1;
}