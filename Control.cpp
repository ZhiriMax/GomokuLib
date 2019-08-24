#include"Control.h"
#include"SGF.h"
#include"CreativeWorkshop.h"
#include"ArtificialIntelligence.h"
#include<conio.h>
#include<iostream>
#include<direct.h>

void commonGomoku() {
	gameInterface gameCon;
	board GomokuBoard;
	sgf sgfCout;
	int ch, x, y, size = 15, nextStep = 0;
	chessPoint tmp;
	gameCon.drawGame();
	gameCon.thirdMenu(GomokuBoard);
	GomokuBoard.setSize(15);

	GomokuBoard.setWhosTurn(1);

	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	setCursorPosition(22, 34); cout << "【 悔棋 】";
	setCursorPosition(24, 32); cout << "(将光标移到上方悔棋)";

	if (GomokuBoard.getWhosTurn()) {
		setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		setCursorPosition(14, 30); cout << "                            ";
		setCursorPosition(14, 31);
		cout << "现在是  " << GomokuBoard.getPlayerB() << "  的回合";
	}
	else {
		setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		setCursorPosition(14, 30); cout << "                            ";
		setCursorPosition(14, 31);
		cout << "现在是  " << GomokuBoard.getPlayerW() << "  的回合";
	}

	x = 8, y = 8;
	GomokuBoard.setCurPos(x, y);
	while (1) {
		GomokuBoard.printBoard();
		while (ch = _getch()) {
			switch (ch)
			{
			case 72:	//上
				if (x > 1) {
					GomokuBoard.setCurPos(--x, y);
					GomokuBoard.printBoard();
				}
				break;
			case 80:	//下
				if (x < 15) {
					GomokuBoard.setCurPos(++x, y);
					GomokuBoard.printBoard();
				}
				break;
			case 75:	//左
				if (y > 1 && y <= 15) {
					GomokuBoard.setCurPos(x, --y);
					GomokuBoard.printBoard();
				}
				if (y > 15) {
					GomokuBoard.setCurPos(x, --y);
					setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					setCursorPosition(22, 34); cout << "【 悔棋 】";
					GomokuBoard.printBoard();
				}
				break;
			case 77:	//右
				if (y == 15) {
					GomokuBoard.setCurPos(x, ++y);
					setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					setCursorPosition(22, 34); cout << "【 悔棋 】";
					GomokuBoard.printBoard();
				}
				if (y < 15) {
					GomokuBoard.setCurPos(x, ++y);
					GomokuBoard.printBoard();
				}
				break;
			case 32:
			case 13:
				if (y <= 15) {
					if (GomokuBoard.getChessColor(x, y) == -1) {
						tmp.x = x; tmp.y = y;
						if (GomokuBoard.getWhosTurn()) tmp.color = 0;
						else tmp.color = 1;
						GomokuBoard.setWhosTurn(!GomokuBoard.getWhosTurn());
						GomokuBoard.update(tmp);
						GomokuBoard.printBoard();
						if (GomokuBoard.getWhosTurn()) {
							setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
							setCursorPosition(14, 30); cout << "                            ";
							setCursorPosition(14, 31);
							cout << "现在是  " << GomokuBoard.getPlayerB() << "  的回合";
						}
						else {
							setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
							setCursorPosition(14, 30); cout << "                            ";
							setCursorPosition(14, 31);
							cout << "现在是  " << GomokuBoard.getPlayerW() << "  的回合";
						}
						switch (GomokuBoard.judge(x, y)) {
						case 1:
							setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
							setCursorPosition(14, 30); cout << "                            ";
							setCursorPosition(14, 32);
							if (!GomokuBoard.getWhosTurn()) cout << GomokuBoard.getPlayerB();
							else cout << GomokuBoard.getPlayerW();
							setCursorPosition(14, 38);
							setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
							cout << " 获胜！";
							setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
							ch = _getch();
							nextStep = gameCon.forthMenu();
							break;
						case 0:
							setCursorPosition(14, 35);
							cout << "< 平局 >";
							ch = _getch();
							nextStep = gameCon.forthMenu();
							break;
						}
						if (nextStep == 41) {
							nextStep = 0;
							GomokuBoard.reset();
							GomokuBoard.setWhosTurn(true);
							x = 8, y = 8;
							GomokuBoard.setCurPos(x, y);
							GomokuBoard.printBoard();

							if (GomokuBoard.getWhosTurn()) {
								setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
								setCursorPosition(14, 30); cout << "                            ";
								setCursorPosition(14, 31);
								cout << "现在是  " << GomokuBoard.getPlayerB() << "  的回合";
							}
							else {
								setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
								setCursorPosition(14, 30); cout << "                            ";
								setCursorPosition(14, 31);
								cout << "现在是  " << GomokuBoard.getPlayerW() << "  的回合";
							}


							setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
							setCursorPosition(22, 34); cout << "【 悔棋 】";
							setCursorPosition(24, 32); cout << "(将光标移到上方悔棋)";
						}
						if (nextStep == 42) {
							ch = _getch();
							gameCon.sgfInterface(GomokuBoard);
							nextStep = 0;
							return;
						}
						if (nextStep == 43) {
							nextStep = 0;
							return;
						}
						break;
					}
					else break;
				}
				else {
					GomokuBoard.repent();
					GomokuBoard.setWhosTurn(!GomokuBoard.getWhosTurn());
					GomokuBoard.printBoard();
					if (GomokuBoard.getWhosTurn()) {
						setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
						setCursorPosition(14, 30); cout << "                            ";
						setCursorPosition(14, 31);
						cout << "现在是  " << GomokuBoard.getPlayerB() << "  的回合";
					}
					else {
						setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
						setCursorPosition(14, 30); cout << "                            ";
						setCursorPosition(14, 31);
						cout << "现在是  " << GomokuBoard.getPlayerW() << "  的回合";
					}
					break;
				}
			}
		}
	}
}

void sgfReadIn() {
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (int i = 17; i <= 24; i++) {
		setCursorPosition(i, 20);
		cout << "                                         ";
	}

	setCursorPosition(18, 20); cout << "请将SGF棋谱文件放置在 .../sgfManual 文件夹内";
	setCursorPosition(20, 20); cout << "并输入棋谱文件名(无后缀)：";

	sgf sgfIn;
	gameInterface gameCon;
	board GomokuBoard;
	string tmp;
	int ch,key=1;
	bool flag;
	char buffer[300];

	_getcwd(buffer, sizeof(buffer));
	setCursorPosition(21, 20); cin >> tmp;
	tmp = "\\sgfManual\\" + tmp;
	tmp = tmp + ".sgf";
	setCursorPosition(23, 20);
	while (!sgfIn.setInFile(buffer + tmp)) {
		setCursorPosition(24, 20);
		system("pause");
		for (int i = 17; i <= 24; i++) {
			setCursorPosition(i, 20);
			cout << "                                         ";
		}
		setCursorPosition(18, 20); cout << "请将SGF棋谱文件放置在 .../sgfManual 文件夹内";
		setCursorPosition(20, 20); cout << "并输入棋谱文件名(无后缀)：";
		setCursorPosition(21, 20); cin >> tmp;
		tmp = "\\sgfManual\\" + tmp;
		tmp = tmp + ".sgf";
		setCursorPosition(23, 20);
	}
	setCursorPosition(24, 20);
	system("pause");
	sgfIn.sgfAnalysis();
	sgfIn.boardUpdate(GomokuBoard);
	gameCon.drawGame();
	GomokuBoard.setCurrentpoint(GomokuBoard.getChessNum());
	GomokuBoard.printBoard();

	setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	setCursorPosition(4, 33); cout << "玩家1：";
	setCursorPosition(8, 33); cout << "玩家2：";

	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	setCursorPosition(6, 37); cout << GomokuBoard.getPlayerB();
	setCursorPosition(10, 37); cout << GomokuBoard.getPlayerW();

	setCursorPosition(20, 36); cout << "回退一步";
	setCursorPosition(22, 36); cout << "前进一步";
	setCursorPosition(24, 36); cout << "返回主菜单";

	setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	setCursorPosition(20, 36); cout << "回退一步";

	while (1) {
		flag = false;
		while (ch = _getch()) {
			switch (ch) {
			case 72: //上
				if (key > 1) {
					switch (key) {
					case 2:
						setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
						setCursorPosition(22, 36); cout << "前进一步";
						setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
						setCursorPosition(20, 36); cout << "回退一步";
						--key;
						break;
					case 3:
						setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
						setCursorPosition(24, 36); cout << "返回主菜单";
						setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
						setCursorPosition(22, 36); cout << "前进一步";
						--key;
					}
					
				}
				break;
			case 80: //下
				if (key < 3) {
					switch (key){
					case 1:
						setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
						setCursorPosition(20, 36); cout << "回退一步";
						setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
						setCursorPosition(22, 36); cout << "前进一步";
						++key;
						break;
					case 2:
						setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
						setCursorPosition(22, 36); cout << "前进一步";
						setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
						setCursorPosition(24, 36); cout << "返回主菜单";
						++key;
						break;
					}
				}
				break;
			case 32:
			case 13:
				flag = true;
				break;
			}
			if (flag) {
				switch (key){
				case 1:
					GomokuBoard.lastBoard();
					break;
				case 2:
					GomokuBoard.nextBoard();
					break;
				case 3:
					ch = _getch();
					return;
					break;
				}
			}
		}
	}
	return;
}

void creativeGame(int type) {
	creative CreativeBoard;
	gameInterface gameCon;
	int ch, size, x, y, playerNum,nextStep=0;
	chessPoint tmp;
	if (type == 16) {
		gameCon.drawGame();
		gameCon.fifthMenu(CreativeBoard);
	}
	else if (type == 17)
		gameCon.seventhMenu(CreativeBoard);
	//else
	gameCon.boardClear(2, 26);
	size = CreativeBoard.getSize();
	playerNum = CreativeBoard.getPlayerNum();
	CreativeBoard.setWhosTurn(0);

	for (int i = 1; i <= playerNum; i++) {
		setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		setCursorPosition(2 + 2 * i,32); cout << "玩家  " << i;
		setColor(CreativeBoard.getOnesColor(i-1)); cout << "   < " << CreativeBoard.getOnesType(i-1) << " >";
	}

	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	setCursorPosition(16, 32);  cout << "轮到  玩家  " <<  1 << "  下棋";
	setCursorPosition(18, 34); cout << "获胜棋形";
	CreativeBoard.showRules();
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	setCursorPosition(24, 34); cout << "【 悔棋 】";
	setCursorPosition(26, 32); cout << "(将光标移到上方悔棋)";

	x = size/2, y = size/2;
	CreativeBoard.setCurPos(x, y);
	while (1) {
		CreativeBoard.printBoard();
		while (ch = _getch()) {
			switch (ch)
			{
			case 72:	//上
				if (x > 1) {
					CreativeBoard.setCurPos(--x, y);
					CreativeBoard.printBoard();
				}
				break;
			case 80:	//下
				if (x < size) {
					CreativeBoard.setCurPos(++x, y);
					CreativeBoard.printBoard();
				}
				break;
			case 75:	//左
				if (y > 1 && y <= size) {
					CreativeBoard.setCurPos(x, --y);
					CreativeBoard.printBoard();
				}
				if (y > size) {
					CreativeBoard.setCurPos(x, --y);
					setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					setCursorPosition(24, 34); cout << "【 悔棋 】";
					CreativeBoard.printBoard();
				}
				break;
			case 77:	//右
				if (y == size) {
					CreativeBoard.setCurPos(x, ++y);
					setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					setCursorPosition(24, 34); cout << "【 悔棋 】";
					CreativeBoard.printBoard();
				}
				if (y < size) {
					CreativeBoard.setCurPos(x, ++y);
					CreativeBoard.printBoard();
				}
				break;
			case 32:
			case 13:
				if (y <= size) {
					if (CreativeBoard.canSet(x, y)  ) {
						tmp.x = x; tmp.y = y;
						tmp.color = CreativeBoard.getWhosTurn() ;
						CreativeBoard.setWhosTurn(tmp.color+1);
						CreativeBoard.update(tmp);
						CreativeBoard.printBoard();
						
						setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
						setCursorPosition(16, 32);  cout << "轮到  玩家  " << (tmp.color + 1) % playerNum + 1 << "  下棋";
						switch (CreativeBoard.judge(x, y)) {
						case 1:
							setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
							for (int i = 16; i <= 24; i++) {
								setCursorPosition(i, 30);
								cout << "                            ";
							}
							setCursorPosition(16, 32);
						    cout <<"玩家  "<< (CreativeBoard.getWhosTurn()-1 +playerNum) % playerNum +1;
							setCursorPosition(16, 37);
							setColor(3);
							cout << " 获胜！";
							setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
							ch = _getch();
							nextStep = gameCon.sixthMenu();
							break;
						case 0:
							setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
							for (int i = 16; i <= 24; i++) {
								setCursorPosition(i, 30);
								cout << "                            ";
							}
							setColor(3); setCursorPosition(17, 35);
							cout << "< 平局 >";
							ch = _getch();
							nextStep = gameCon.sixthMenu();
							break;
						default:
								break;
						}
						if (nextStep == 61) {
							nextStep = 0;
							CreativeBoard.reset();
							CreativeBoard.setWhosTurn(0);
							x = size / 2, y = size / 2;
							CreativeBoard.setCurPos(x, y);
							CreativeBoard.printBoard();
							setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
							setCursorPosition(16, 32);  cout << "轮到  玩家  " << 1 << "  下棋";
							setCursorPosition(18, 34); cout << "获胜棋形";
							CreativeBoard.showRules();
							setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
							setCursorPosition(24, 34); cout << "【 悔棋 】";
							setCursorPosition(26, 32); cout << "(将光标移到上方悔棋)";
						}
						if (nextStep == 62) {
							nextStep = 0;
							return;
						}
						break;
					}
					else break;
				}
				else {
					CreativeBoard.repent();
					CreativeBoard.setWhosTurn(CreativeBoard.getWhosTurn() + playerNum - 1);
					setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					setCursorPosition(16, 32);  cout << "轮到  玩家  " << (CreativeBoard.getWhosTurn()) + 1 << "  下棋";
					CreativeBoard.printBoard();
					break;
				}
			}
		}
	}
}

void AIGame(int aiColor) {
	gameInterface gameCon;
	board GomokuBoard;
	ai AIGamer;
	int ch, x, y, size = 15, nextStep = 0;
	chessPoint tmp;
	gameCon.drawGame();
	GomokuBoard.setWhosTurn(1);
	GomokuBoard.setSize(15);
	if (aiColor == 0) {
		GomokuBoard.setPlayerB("GomokuLib");
		GomokuBoard.setPlayerW("游戏者");
	}
	else {
		GomokuBoard.setPlayerB("游戏者");
		GomokuBoard.setPlayerW("GomokuLib");
	}

	setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	setCursorPosition(4, 33); cout << "玩家1：";
	setCursorPosition(8, 33); cout << "玩家2：";

	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	setCursorPosition(6, 37); cout << GomokuBoard.getPlayerB();
	setCursorPosition(10, 37); cout << GomokuBoard.getPlayerW();

	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	setCursorPosition(22, 34); cout << "【 悔棋 】";
	setCursorPosition(24, 32); cout << "(将光标移到上方悔棋)";

	x = 8, y = 8;
	GomokuBoard.setCurPos(x, y);
	if (aiColor == 0) {
		tmp = AIGamer.getPoint(GomokuBoard, aiColor);
		GomokuBoard.update(tmp);
		GomokuBoard.setWhosTurn(!GomokuBoard.getWhosTurn());
	}

	if (GomokuBoard.getWhosTurn()) {
		setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		setCursorPosition(14, 30); cout << "                            ";
		setCursorPosition(14, 31);
		cout << "现在是  " << GomokuBoard.getPlayerB() << "  的回合";
	}
	else {
		setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		setCursorPosition(14, 30); cout << "                            ";
		setCursorPosition(14, 31);
		cout << "现在是  " << GomokuBoard.getPlayerW() << "  的回合";
	}

	while (1) {
		GomokuBoard.printBoard();
		while (ch = _getch()) {
			switch (ch)
			{
			case 72:	//上
				if (x > 1) {
					GomokuBoard.setCurPos(--x, y);
					GomokuBoard.printBoard();
				}
				break;
			case 80:	//下
				if (x < 15) {
					GomokuBoard.setCurPos(++x, y);
					GomokuBoard.printBoard();
				}
				break;
			case 75:	//左
				if (y > 1 && y <= 15) {
					GomokuBoard.setCurPos(x, --y);
					GomokuBoard.printBoard();
				}
				if (y > 15) {
					GomokuBoard.setCurPos(x, --y);
					setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					setCursorPosition(22, 34); cout << "【 悔棋 】";
					GomokuBoard.printBoard();
				}
				break;
			case 77:	//右
				if (y == 15) {
					GomokuBoard.setCurPos(x, ++y);
					setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					setCursorPosition(22, 34); cout << "【 悔棋 】";
					GomokuBoard.printBoard();
				}
				if (y < 15) {
					GomokuBoard.setCurPos(x, ++y);
					GomokuBoard.printBoard();
				}
				break;
			case 32:
			case 13:
				if (y <= 15) {
					if (GomokuBoard.getChessColor(x, y) == -1) {
						tmp.x = x; tmp.y = y;
						if (GomokuBoard.getWhosTurn()) tmp.color = 0;
						else tmp.color = 1;
						GomokuBoard.setWhosTurn(!GomokuBoard.getWhosTurn());
						GomokuBoard.update(tmp);
						GomokuBoard.printBoard();
						if (GomokuBoard.getWhosTurn()) {
							setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
							setCursorPosition(14, 30); cout << "                            ";
							setCursorPosition(14, 31);
							cout << "现在是  " << GomokuBoard.getPlayerB() << "  的回合";
						}
						else {
							setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
							setCursorPosition(14, 30); cout << "                            ";
							setCursorPosition(14, 31);
							cout << "现在是  " << GomokuBoard.getPlayerW() << "  的回合";
						}
						//system("pause");
						switch (GomokuBoard.judge(x, y)) {
						case 1:
							setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
							setCursorPosition(14, 30); cout << "                            ";
							setCursorPosition(14, 32);
							if (!GomokuBoard.getWhosTurn()) cout << GomokuBoard.getPlayerB();
							else cout << GomokuBoard.getPlayerW();
							setCursorPosition(14, 38);
							setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
							cout << " 获胜！";
							setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
							ch = _getch();
							nextStep = gameCon.forthMenu();
							break;
						case 0:
							setCursorPosition(14, 35);
							cout << "< 平局 >";
							ch = _getch();
							nextStep = gameCon.forthMenu();
							break;
						default:
							tmp = AIGamer.getPoint(GomokuBoard, aiColor);
							GomokuBoard.update(tmp);
							GomokuBoard.setWhosTurn(!GomokuBoard.getWhosTurn());
							GomokuBoard.printBoard();
							if (GomokuBoard.getWhosTurn()) {
								setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
								setCursorPosition(14, 30); cout << "                            ";
								setCursorPosition(14, 31);
								cout << "现在是  " << GomokuBoard.getPlayerB() << "  的回合";
							}
							else {
								setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
								setCursorPosition(14, 30); cout << "                            ";
								setCursorPosition(14, 31);
								cout << "现在是  " << GomokuBoard.getPlayerW() << "  的回合";
							}
							switch (GomokuBoard.judge(tmp.x, tmp.y)) {
							case 1:
								setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
								setCursorPosition(14, 30); cout << "                            ";
								setCursorPosition(14, 33);
								if (!GomokuBoard.getWhosTurn()) cout << GomokuBoard.getPlayerB();
								else cout << GomokuBoard.getPlayerW();
								setCursorPosition(14, 38);
								setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
								cout << " 获胜！";
								setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
								ch = _getch();
								nextStep = gameCon.forthMenu();
								break;
							case 0:
								setCursorPosition(14, 35);
								cout << "< 平局 >";
								ch = _getch();
								nextStep = gameCon.forthMenu();
								break;
							}
							break;
						}
						if (nextStep == 41) {
							nextStep = 0;
							GomokuBoard.reset();
							GomokuBoard.setWhosTurn(true);
							x = 8, y = 8;
							GomokuBoard.setCurPos(x, y);
							GomokuBoard.printBoard();




							setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
							setCursorPosition(22, 34); cout << "【 悔棋 】";
							setCursorPosition(24, 32); cout << "(将光标移到上方悔棋)";
							if (aiColor == 0) {
								tmp = AIGamer.getPoint(GomokuBoard, aiColor);
								GomokuBoard.update(tmp);
								GomokuBoard.setWhosTurn(!GomokuBoard.getWhosTurn());
							}
							if (GomokuBoard.getWhosTurn()) {
								setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
								setCursorPosition(14, 30); cout << "                            ";
								setCursorPosition(14, 31);
								cout << "现在是  " << GomokuBoard.getPlayerB() << "  的回合";
							}
							else {
								setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
								setCursorPosition(14, 30); cout << "                            ";
								setCursorPosition(14, 31);
								cout << "现在是  " << GomokuBoard.getPlayerW() << "  的回合";
							}
						}
						if (nextStep == 42) {
							ch = _getch();
							gameCon.sgfInterface(GomokuBoard);
							nextStep = 0;
							return;
						}
						if (nextStep == 43) {
							nextStep = 0;
							return;
						}
						break;
					}
					else break;
				}
				else {
					GomokuBoard.repent();
					GomokuBoard.repent();
					
					GomokuBoard.printBoard();
					break;
				}
			}
		}
	}
}