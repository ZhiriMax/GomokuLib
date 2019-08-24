#include"GameInterface.h"
#include"Tools.h"
#include"Board.h"
#include<windows.h>
#include<string>
#include<iostream>
#include<conio.h>
#include<direct.h>

using namespace std;

void gameInterface::start() {
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	system("cls");
	setWindowSize(30, 45);
	setColor(FOREGROUND_GREEN);
	cout << endl;
	cout << "    ■■  ■" << endl;
	cout << "  ■    ■■                                           ■" << endl;
	cout << "  ■                                                   ■        " << endl;
	cout << "  ■              ■■■    ■■  ■■       ■■■    ■      ■    ■■    ■" << endl;
	cout << "  ■            ■      ■    ■■■  ■   ■      ■  ■    ■        ■    ■" << endl;
	cout << "  ■            ■      ■    ■  ■  ■   ■      ■  ■  ■          ■    ■" << endl;
	cout << "  ■    ■■■  ■      ■    ■  ■  ■   ■      ■  ■■            ■    ■" << endl;
	cout << "  ■      ■    ■      ■    ■  ■  ■   ■      ■  ■  ■          ■    ■" << endl;
	cout << "  ■      ■    ■      ■    ■  ■  ■   ■      ■  ■    ■        ■    ■" << endl;
	cout << "  ■      ■    ■      ■    ■  ■  ■   ■      ■  ■      ■      ■  ■■" << endl;
	cout << "    ■■■        ■■■      ■  ■  ■     ■■■    ■        ■      ■  ■■" << endl;
	cout << endl << endl;;
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "╭ ────────────────────────── ╮" << endl;
	cout << "│  ■■■    ■  ■          │" << endl;
	cout << "│    ■      ■  ■          │" << endl;
	cout << "│    ■          ■          │" << endl;
	cout << "│    ■      ■  ■  ■■    │" << endl;
	cout << "│    ■      ■  ■■    ■  │" << endl;
	cout << "│    ■      ■  ■      ■  │" << endl;
	cout << "│    ■      ■  ■      ■  │" << endl;
	cout << "│    ■  ■  ■  ■■    ■  │" << endl;
	cout << "│  ■■■■  ■  ■  ■■    │" << endl;
	cout << "╰ ────────────────────────── ╯" << endl;
	
	setColor(6|FOREGROUND_INTENSITY);
	setCursorPosition(15, 26);
	cout << "操作说明：";
	setCursorPosition(17, 20);
	cout << "↑、↓、←、→ 四个方向键移动选项";
	setCursorPosition(19, 24);
	cout << "回车键或空格键确定";

	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	setCursorPosition(24, 23);
	cout << "Press any key to start";
	setCursorPosition(23,24);
	system("pause");

}

int gameInterface::firstMenu() {
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	//手动清空屏幕
	for (int i = 15; i <= 24; i++) {
		setCursorPosition(i, 20);
		cout << "                                         ";
	}
	//展开菜单
	setCursorPosition(17, 20);
	cout << "[ 菜单 | Menu ]:";
	setCursorPosition(19, 30);
	cout << "正常模式";
	setCursorPosition(21, 30);
	cout << "创意工坊";
	int ch;
	key[1] = 1;
	setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	setCursorPosition(19, 30);
	cout << "正常模式";
	bool flag = false;
	while (ch = _getch()) {
		switch (ch) {
		case 72:	//上
			if (key[1] > 1) {
				setCursorPosition(19, 30);
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				cout << "正常模式";
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				setCursorPosition(21, 30);
				cout << "创意工坊";
				--key[1];
			}
			break;
		case 80:	//下
			if (key[1] < 2) {
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				setCursorPosition(19, 30);
				cout<< "正常模式";
				setCursorPosition(21, 30);
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				cout << "创意工坊";
				++key[1];
			}
			break;
		case 32:
		case 13:
			flag = true;
			break;
		default:
			break;
		
		}
		if (flag) {
			ch = _getch();
			break;
		}
		setCursorPosition(30, 0);
	}
	return secondMenu();
}

int gameInterface::secondMenu() {
	//手动清空屏幕
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (int i = 17; i <= 24; i++) {
		setCursorPosition(i, 20);
		cout << "                                         ";
	}
	if (key[1] == 1) {		//第一类二级菜单
		//展开二级菜单
		setCursorPosition(17, 20);
		cout << "[ 游戏模式 ]:";
		setCursorPosition(19, 30);
		cout << "双人对战";
		setCursorPosition(20, 30);
		cout << "人机对战";
		setCursorPosition(21, 30);
		cout << "棋谱导入";
		setCursorPosition(22, 30);
		cout << "返回上一层";
		//----------------------------
		int ch;
		key[2] = 1;
		setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		setCursorPosition(19, 30);
		cout << "双人对战";
		bool flag = false;
		while (ch = _getch()) {
			switch (ch) {
			case 72:	//上
				if (key[2] > 1) {
					switch (key[2]) {
					case 2:
						setCursorPosition(19, 30);
						setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
						cout << "双人对战";
						setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
						setCursorPosition(20, 30);
						cout << "人机对战";
						--key[2];
						break;
					case 3:
						setCursorPosition(20, 30);
						setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
						cout << "人机对战";
						setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
						setCursorPosition(21, 30);
						cout << "棋谱导入";
						--key[2];
						break;
					case 4:
						setCursorPosition(21, 30);
						setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
						cout << "棋谱导入";
						setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
						setCursorPosition(22, 30);
						cout << "返回上一层";
						--key[2];
						break;
					}
				}
				break;
			case 80:	//下
				if (key[2] < 4) {
					switch (key[2])
					{
					case 1:
						setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
						setCursorPosition(19, 30);
						cout << "双人对战";
						setCursorPosition(20, 30);
						setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
						cout << "人机对战";
						++key[2];
						break;
					case 2:
						setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
						setCursorPosition(20, 30);
						cout << "人机对战";
						setCursorPosition(21, 30);
						setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
						cout << "棋谱导入";
						++key[2];
						break;
					case 3:
						setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
						setCursorPosition(21, 30);
						cout << "棋谱导入";
						setCursorPosition(22, 30);
						setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
						cout << "返回上一层";
						++key[2];
						break;
					}
				}
				break;
			case 32:
			case 13:
				flag = true;
				break;
			default:
				break;
			}
			if (flag) break;
			setCursorPosition(30, 0);
		}
		switch (key[2]) {
		case 1:
			return 11;
			break;
		case 2:
			return eighthMenu();
			break;
		case 3:
			return 13;
			break;
		case 4:
			ch = _getch();
			return firstMenu();
			break;
		}
	}

	if (key[1] == 2) {
		setCursorPosition(17, 20);
		cout << "[ 创意工坊 ]:";
		setCursorPosition(19, 30);
		cout << "自定义游戏规则";
		setCursorPosition(20, 30);
		cout << "导入游戏规则";
		setCursorPosition(21, 30);
		cout << "返回上一层";
		int ch;
		key[2] = 1;
		setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		setCursorPosition(19, 30);
		cout << "自定义游戏规则";
		bool flag = false;
		while (ch = _getch()) {
			switch (ch) {
			case 72:	//上
				if (key[2] > 1) {
					switch (key[2]) {
					case 2:
						setCursorPosition(19, 30);
						setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
						cout << "自定义游戏规则";
						setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
						setCursorPosition(20, 30);
						cout << "导入游戏规则";
						--key[2];
						break;
					case 3:
						setCursorPosition(20, 30);
						setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
						cout << "导入游戏规则";
						setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
						setCursorPosition(21, 30);
						cout << "返回上一层";
						--key[2];
						break;
					}
				}
				break;
			case 80:	//下
				if (key[2] < 3) {
					switch (key[2])
					{
					case 1:
						setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
						setCursorPosition(19, 30);
						cout << "自定义游戏规则";
						setCursorPosition(20, 30);
						setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
						cout << "导入游戏规则";
						++key[2];
						break;
					case 2:
						setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
						setCursorPosition(20, 30);
						cout << "导入游戏规则";
						setCursorPosition(21, 30);
						setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
						cout << "返回上一层";
						++key[2];
						break;
					}
				}
				break;
			case 32:
			case 13:
				flag = true;
				break;
			default:
				break;
			}
			if (flag) break;
			setCursorPosition(30, 0);
		}
		switch (key[2]) {
		case 1:
			ch = _getch();
			return 16;
			break;
		case 2:
			ch = _getch();
			return 17;
			break;
		case 3:
			ch=_getch();
			return firstMenu();
			break;
		default:
			return 0;
			break;
		}
	}	
	return 0;
}

void gameInterface::thirdMenu(board &Gomoku) {
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	int ch;
	bool flag = false;
	if (key[1] = 1) {
		if (key[2] = 1) {
			setCursorPosition(10, 5);
			cout << "[ 请设定棋局信息 ]:";
			setCursorPosition(12, 9);
			cout << "玩家1 昵称：";
			setCursorPosition(14, 9);
			cout << "玩家2 昵称：";
			setCursorPosition(16, 9);
			cout << "开始游戏";

			string player1, player2;
			setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			setCursorPosition(12, 9);
			cout << "玩家1 昵称：";
			setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			cin >> player1; Gomoku.setPlayerB(player1);
			setCursorPosition(12, 9);
			cout << "玩家1 昵称：";

			setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			setCursorPosition(14, 9);
			cout << "玩家2 昵称：";
			setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			cin >> player2; Gomoku.setPlayerW(player2);
			setCursorPosition(14, 9);
			cout << "玩家2 昵称：";
			ch = _getch();

			setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
			setCursorPosition(16, 9);
			cout << "开始游戏";
			setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			while (ch = _getch()) {
				switch (ch){
				case 32:
				case 13:
					ch = _getch();
					for (int i = 10; i <= 16; i += 2) {
						setCursorPosition(i, 5);
						cout << "                             ";
					}
					setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					setCursorPosition(4, 33); cout << "玩家1：";
					setCursorPosition(8, 33); cout << "玩家2：";

					setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					setCursorPosition(6, 37); cout << player1;
					setCursorPosition(10, 37); cout << player2;
					return;
				}
			}
		}
	}

}

int gameInterface::forthMenu() {
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (int i = 18; i <= 24; i++) {
		setCursorPosition(i, 30); cout << "                            ";
	}
	setCursorPosition(18, 35);
	cout << "重新开始";
	setCursorPosition(20, 35);
	cout << "导出SGF棋谱文件";
	setCursorPosition(22, 35);
	cout << "返回主菜单";

	setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	setCursorPosition(18, 35);
	cout << "重新开始";
	key[4] = 1;
	int ch;
	bool flag = false;
	while (ch = _getch()) {
		switch (ch){
		case 72:
			if (key[4] > 1) {
				switch (key[4]) {
				case 2:
					setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					setCursorPosition(20, 35);
					cout << "导出SGF棋谱文件";
					setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					setCursorPosition(18, 35);
					cout << "重新开始";
					--key[4];
					break;
				case 3:
					setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					setCursorPosition(22, 35);
					cout << "返回主菜单";
					setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					setCursorPosition(20, 35);
					cout << "导出SGF棋谱文件";
					--key[4];
					break;
				}
			}
			break;
		case 80:
			if (key[4] < 3) {
				switch (key[4]) {
				case 1:
					setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					setCursorPosition(18, 35);
					cout << "重新开始";
					setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					setCursorPosition(20, 35);
					cout << "导出SGF棋谱文件";
					++key[4];
					break;
				case 2:
					setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					setCursorPosition(20, 35);
					cout << "导出SGF棋谱文件";
					setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					setCursorPosition(22, 35);
					cout << "返回主菜单";
					++key[4];
					break;
				}
			}
			break;
		case 32:
		case 13:
			flag = true;
			//ch = _getch();
			break;
		}
		if (flag) break;
	}

	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (int i = 11; i <= 24; i++) {
		setCursorPosition(i, 30); cout << "                            ";
	}

	switch (key[4]) {
	case 1:
		return 41;
		break;
	case 2:
		return 42;
		break;
	case 3:
		return 43;
		break;
	default:
		return 0;
		break;
	}
}


void gameInterface::drawGame() {
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY); 
	system("cls");
	for (int i = 1; i <= 27; i++) {
		setColor(FOREGROUND_GREEN);
		setCursorPosition(1, i); cout << "■";
		setCursorPosition(i, 1); cout << "■";
		Sleep(30);
	}
	for (int i = 1; i <= 27; i++) {
		setCursorPosition(27, i); cout << "■";
		setCursorPosition(i, 27); cout << "■";
		Sleep(30);
	}
	setCursorPosition(1, 28);
	setColor(6 | FOREGROUND_INTENSITY);
	for (int i = 28; i <45; i++) {
		cout << "■";
		Sleep(30);
	}
	for (int i = 1; i <= 27; i++) {
		setCursorPosition(i, 44);
		cout << "■";
		Sleep(30);
	}
	setCursorPosition(27, 28);
	for (int i = 44; i >= 28; i--) {
		setCursorPosition(27, i);
		cout << "■";
		Sleep(30);
	}
}

void gameInterface::sgfInterface(board &Gomoku) {
	string tmp;
	sgf sgfCout;
	char buffer[300]="";
	int buffer_len=0;
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (int i = 16; i <= 22; i++) {
		setCursorPosition(i, 32); cout << "                    ";
	}
	_getcwd(buffer, sizeof(buffer));
	setCursorPosition(16, 32);
	cout << "请输入棋谱文件名：";
	setCursorPosition(18, 32);
	cin >> tmp;
	tmp = "\\sgfManual\\" + tmp;
	tmp = tmp + ".sgf";
	sgfCout.setOutFile(buffer +tmp );
	sgfCout.sgfUpdate(Gomoku);
	sgfCout.sgfPrint();
	setCursorPosition(20, 32);
	cout << "输出完成...";
	setCursorPosition(22, 32);
	system("pause");
}

void gameInterface::fifthMenu(creative &CreativeBoard) {
	string chessType[5] = { "●","○","⊙","◇","⊕" };
	int color_tmp[5] = { 1,2,4, 6,5 };
	int back = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
	bool flag;
	int playerNum_tmp = 2;
	int size_tmp = 15;
	int ch;
	int curposX, curposY;
	creativeTips1();
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	setCursorPosition(6, 12); cout << "棋盘大小";
	setCursorPosition(8, 11);  cout << "<   " << size_tmp << "   >";
	setCursorPosition(10, 12); cout << "玩家人数";
	setCursorPosition(12, 11); cout << "<    " << playerNum_tmp << "    >";
	setCursorPosition(14, 11); cout << "设置棋子颜色";
	for (int i = 1; i <= playerNum_tmp; i++) {
		setCursorPosition(2 * i + 14, 10);
		setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "玩家 " << i; setColor(color_tmp[i - 1]);
		cout << "   < " << chessType[i - 1] << " >";
	}
	setCursorPosition(2 * playerNum_tmp + 16, 12); cout << "下一步";
	key[5] = 1; flag = false;
	setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	setCursorPosition(8, 11);  cout << "<    " << size_tmp << "    >";
	ch = _getch();
	while (ch = _getch()) {
		switch (ch) {
		case 72:
			if (key[5] == 2) {
				boardClear(8, 8);
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				setCursorPosition(8, 11);  cout << "<    " << size_tmp << "    >";
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				setCursorPosition(12, 11); cout << "<    " << playerNum_tmp << "    >";
				--key[5]; break;
			}
			if (key[5] == 3 + playerNum_tmp) {
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				setCursorPosition(2 * playerNum_tmp + 14, 10);
				cout << "玩家 " << playerNum_tmp; setColor(color_tmp[playerNum_tmp - 1]);
				cout << "   < " << chessType[playerNum_tmp - 1] << " >";
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				setCursorPosition(2 * playerNum_tmp + 16, 12); cout << "下一步";
				--key[5]; break;
			}
			if (key[5] == 3) {
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				setCursorPosition(12, 11); cout << "<    " << playerNum_tmp << "    >";
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				setCursorPosition(16, 10);
				cout << "玩家 " << 1; setColor(color_tmp[0]);
				cout << "   < " << chessType[0] << " >";
				--key[5]; break;
			}
			if (key[5] > 3 && key[5] < 3 + playerNum_tmp) {
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				setCursorPosition(2 * (key[5] - 3) + 14, 10);
				cout << "玩家 " << (key[5] - 3); setColor(color_tmp[(key[5] - 3) - 1] );
				cout << "   < " << chessType[(key[5] - 3) - 1] << " >";
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				setCursorPosition(2 * (key[5] - 2) + 14, 10);
				cout << "玩家 " << (key[5] - 2); setColor(color_tmp[(key[5] - 2) - 1]);
				cout << "   < " << chessType[(key[5] - 2) - 1] << " >";
				--key[5]; break;
			}
			break;
		case 80://下
			if (key[5] == 1) {
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				setCursorPosition(12, 11); cout << "<    " << playerNum_tmp << "    >";
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				boardClear(8, 8);
				setCursorPosition(8, 11);  cout << "<    " << size_tmp << "    >";
				++key[5]; break;
			}
			if (key[5] == 2) {
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				setCursorPosition(16, 10);
				cout << "玩家 " << 1; setColor(color_tmp[0] );
				cout << "   < " << chessType[0] << " >";
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				setCursorPosition(12, 11); cout << "<    " << playerNum_tmp << "    >";
				++key[5]; break;
			}
			if (key[5] == 2 + playerNum_tmp) {
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				setCursorPosition(2 * playerNum_tmp + 16, 12); cout << "下一步";
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				setCursorPosition(2 * playerNum_tmp + 14, 10);
				cout << "玩家 " << playerNum_tmp; setColor(color_tmp[playerNum_tmp - 1]);
				cout << "   < " << chessType[playerNum_tmp - 1] << " >";
				++key[5]; break;
			}
			if (key[5] > 2 && key[5] < 2 + playerNum_tmp) {
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				setCursorPosition(2 * (key[5] - 1) + 14, 10);
				cout << "玩家 " << (key[5] - 1); setColor(color_tmp[(key[5] - 1) - 1] );
				cout << "   < " << chessType[(key[5] - 1) - 1] << " >";
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				setCursorPosition(2 * (key[5] - 2) + 14, 10);
				cout << "玩家 " << (key[5] - 2); setColor(color_tmp[(key[5] - 2) -1]);
				cout << "   < " << chessType[(key[5] - 2)-1] << " >";
				++key[5]; break;
			}
			break;
		case 75://左
			if (key[5] == 1 && size_tmp > 3) {
				--size_tmp;
				boardClear(8, 8);
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				setCursorPosition(8, 11);  cout << "<    " << size_tmp << "    >";
			}
			if (key[5] == 2 && playerNum_tmp > 2) {
				--playerNum_tmp;
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				setCursorPosition(12, 11); cout << "<    " << playerNum_tmp << "    >";
				boardClear(16, 26);
				for (int i = 1; i <= playerNum_tmp; i++) {
					setCursorPosition(2 * i + 14, 10); setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "玩家 " << i; setColor(color_tmp[i - 1]);
					cout << "   < " << chessType[i - 1] << " >";
				}
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				setCursorPosition(2 * playerNum_tmp + 16, 12); cout << "下一步";
			}
			if (key[5] >= 3 && key[5] <= 2 + playerNum_tmp) {
				if (color_tmp[key[5] - 3] > 1) {
					--color_tmp[key[5] - 3];
					setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					setCursorPosition(2 * (key[5] - 2) + 14, 10);
					cout << "玩家 " << (key[5] - 2); setColor(color_tmp[key[5] - 3] );
					cout << "   < " << chessType[key[5] - 3] << " >";
				}
			}
			break;
		case 77:
			if (key[5] == 1 && size_tmp < 20) {
				++size_tmp;
				boardClear(8, 8);
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				setCursorPosition(8, 11);  cout << "<    " << size_tmp << "    >";
			}
			if (key[5] == 2 && playerNum_tmp < 5) {
				++playerNum_tmp;
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				setCursorPosition(12, 11); cout << "<    " << playerNum_tmp << "    >";
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				boardClear(16, 2 * 5 + 3);
				for (int i = 1; i <= playerNum_tmp; i++) {
					setCursorPosition(2 * i + 14, 10); setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "玩家 " << i; setColor(color_tmp[i - 1]);
					cout << "   < " << chessType[i - 1] << " >";
				}
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				setCursorPosition(2 * playerNum_tmp + 16, 12); cout << "下一步";
			}
			if (key[5] >= 3 && key[5] <= 2 + playerNum_tmp) {
				if (color_tmp[key[5] - 3] < 7) {
					++color_tmp[key[5] - 3];
					setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					setCursorPosition(2 * (key[5] - 2) + 14, 10);
					cout << "玩家 " << (key[5] - 2); setColor(color_tmp[key[5] - 3] );
					cout << "   < " << chessType[key[5] - 3] << " >";
				}
			}
			break;
		case 32:
		case 13:
			if (key[5] == 3 + playerNum_tmp) flag = true;
			break;
		}
		if (flag) break;
	}
	CreativeBoard.setSize(size_tmp);
	CreativeBoard.resetBoardRules();
	CreativeBoard.setPlayerNum(playerNum_tmp);
	creativeTips2();
	for (int i = 1; i <= playerNum_tmp; i++) {
		CreativeBoard.setChessColor(i - 1, color_tmp[i - 1]);
	}
	boardClear(2, 26);
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	setCursorPosition(6, 10); cout << "请设置获胜棋形";
	setCursorPosition(14, 12); cout << "下一步";
	curposX = 2; curposY = 2;
	CreativeBoard.setCurPos(curposX, curposY);
	CreativeBoard.printRules();
	flag = false;
	ch = _getch();
	while (ch = _getch()) {
		switch (ch){
		case 72:
			if (curposX > 3) {
				CreativeBoard.setCurPos(--curposX, curposY);
				CreativeBoard.printRules();
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				setCursorPosition(14, 12); cout << "下一步";
				break;
			}
			if (curposX > 1) {
				CreativeBoard.setCurPos(--curposX, curposY);
				CreativeBoard.printRules();
				break;
			}
			break;
		case 80:
			if (curposX < 3) {
				CreativeBoard.setCurPos(++curposX, curposY);
				CreativeBoard.printRules();
				break;
			}
			if (curposX == 3) {
				CreativeBoard.setCurPos(30, curposY);
				++curposX;
				CreativeBoard.printRules();
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				setCursorPosition(14, 12); cout << "下一步";
				break;
			}
			break;

		case 75:
			if (curposY > 1) {
				CreativeBoard.setCurPos(curposX, --curposY);
				CreativeBoard.printRules();
			}
			break;
		case 77:
			if (curposY < 3) {
				CreativeBoard.setCurPos(curposX, ++curposY);
				CreativeBoard.printRules();
			}
			break;
		case 32:
		case 13:
			if (curposX == 4) {
				flag = true;
				break;
			}
			else {
				CreativeBoard.updateRules(curposX, curposY);
				CreativeBoard.printRules();
				ch = _getch();
				break;

			}
		}
		if (flag) break;
	}
	boardClear(2, 26);
	creativeTips3();
	setCursorPosition(2, 10); cout << "请设置游戏棋盘";
	setCursorPosition(25, 11); cout << "保存游戏规则";
	curposX = size_tmp / 2; curposY = size_tmp / 2;
	CreativeBoard.setCurPos(curposX, curposY);
	CreativeBoard.printBoard();
	flag = false;
	ch = _getch();
	while (ch = _getch()) {
		switch (ch) {
		case 72:
			if (curposX > size_tmp) {
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				setCursorPosition(25, 11); cout << "保存游戏规则";
				CreativeBoard.setCurPos(--curposX, curposY);
				CreativeBoard.printBoard();
				break;
			}
			if (curposX > 1) {
				CreativeBoard.setCurPos(--curposX, curposY);
				CreativeBoard.printBoard();
				break;
			}
			break;
		case 80:
			if (curposX < size_tmp) {
				CreativeBoard.setCurPos(++curposX, curposY);
				CreativeBoard.printBoard();
				break;
			}
			if (curposX == size_tmp) {
				CreativeBoard.setCurPos(30, curposY);
				CreativeBoard.printBoard();
				setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
				setCursorPosition(25, 11); cout << "保存游戏规则";
				++curposX;
				break;
			}
			break;
		case 75:
			if (curposY > 1) {
				CreativeBoard.setCurPos(curposX, --curposY);
				CreativeBoard.printBoard();
			}
			break;
		case 77:
			if (curposY < size_tmp) {
				CreativeBoard.setCurPos(curposX, ++curposY);
				CreativeBoard.printBoard();
			}
			break;
		case 32:
		case 13:
			if (curposX == size_tmp + 1) {
				flag = true;
				break;
			}
			else {
				if (CreativeBoard.isLegal(curposX,curposY))
					CreativeBoard.deleteBoardRules(curposX, curposY);
				CreativeBoard.printBoard();
				ch = _getch();
			}
			break;
		}
		if (flag) break;
	}

	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	boardClear(2, 26);
	string tmp;
	char buffer[300];

	setCursorPosition(10, 10); cout << "请命名当前游戏规则";
	setCursorPosition(13, 10); cout << "文件名：";
	cin >> tmp;
	_getcwd(buffer, sizeof(buffer));
	tmp = "\\creativeWorkshop\\" + tmp;
	tmp = tmp + ".rls";
	CreativeBoard.setRulesOut(buffer + tmp);
	CreativeBoard.saveRules();
	setCursorPosition(16, 11); cout << "成功保存文件";
	setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	setCursorPosition(19, 12); cout << "开始游戏";
	ch = _getch(); flag = false;
	while (ch = _getch()) {
		switch (ch) {
		case 32:
		case 13:
			flag = true;
			break;
		}
		if (flag) break;
	}
	clearInfo(2, 26);

}


void gameInterface::boardClear(int a,int b) {
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (int i = a; i <= b; i++) {
		setCursorPosition(i, 2);
		cout << "                                                  ";
	}
}


int gameInterface::sixthMenu() {
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (int i = 20; i <= 26; i++) {
		setCursorPosition(i, 30); cout << "                            ";
	}
	setCursorPosition(20, 34);
	cout << "重新开始";
	setCursorPosition(22, 34);
	cout << "返回主菜单";

	setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	setCursorPosition(20, 34);
	cout << "重新开始";
	key[4] = 1;
	int ch;
	bool flag = false;
	while (ch = _getch()) {
		switch (ch) {
		case 72:
			if (key[4] > 1) {
				switch (key[4]) {
				case 2:
					setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					setCursorPosition(22, 34);
					cout << "返回主菜单";
					setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					setCursorPosition(20, 34);
					cout << "重新开始";
					--key[4];
					break;
				}
			}
			break;
		case 80:
			if (key[4] < 2) {
				switch (key[4]) {
				case 1:
					setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					setCursorPosition(20, 34);
					cout << "重新开始";
					setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
					setCursorPosition(22, 34);
					cout << "返回主菜单";
					++key[4];
					break;
				}
			}
			break;
		case 32:
		case 13:
			flag = true;
			//ch = _getch();
			break;
		}
		if (flag) break;
	}

	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (int i = 11; i <= 24; i++) {
		setCursorPosition(i, 30); cout << "                            ";
	}

	switch (key[4]) {
	case 1:
		return 61;
		break;
	case 2:
		return 62;
		break;
	default:
		return 0;
		break;
	}
}

void gameInterface::seventhMenu(creative &CreativeBoard) {
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (int i = 17; i <= 27; i++) {
		setCursorPosition(i, 20);
		cout << "                                         ";
	}

	setCursorPosition(16, 20); cout << "请将.rls创意工坊规则文件放置在";
	setCursorPosition(18, 20); cout << " ... / creativeWorkshop 文件夹内";
	setCursorPosition(20, 20); cout << "并输入游戏规则文件名(无后缀)：";

	gameInterface gameCon;
	string tmp;

	int ch, key = 1;
	bool flag;
	char buffer[300];

	_getcwd(buffer, sizeof(buffer));
	setCursorPosition(22, 20);  cin >> tmp;
	tmp = "\\creativeWorkshop\\" + tmp;
	tmp = tmp + ".rls";
	setCursorPosition(24, 20);

	while (!CreativeBoard.setRulesIn(buffer + tmp)) {
		setCursorPosition(25, 20);
		system("pause");
		for (int i = 16; i <= 27; i++) {
			setCursorPosition(i, 20);
			cout << "                                         ";
		}
		setCursorPosition(16, 20); cout << "请将.rls创意工坊规则文件放置在";
		setCursorPosition(18, 20);cout<<" ... / creativeWorkshop 文件夹内";
		setCursorPosition(20, 20); cout << "并输入游戏规则文件名(无后缀)：";
		setCursorPosition(22, 20); cin >> tmp;
		tmp = "\\creativeWorkshop\\" + tmp;
		tmp = tmp + ".rls";
		setCursorPosition(24, 20);
	}
	setCursorPosition(25, 20);
	system("pause");
	CreativeBoard.rulesAnalysis();
	gameCon.drawGame();
}

int gameInterface::eighthMenu() {
	{		//第一类二级菜单
	   //展开二级菜单
		setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		for (int i = 17; i <= 24; i++) {
			setCursorPosition(i, 20);
			cout << "                                         ";
		}
		setCursorPosition(17, 20);
		cout << "[ 玩家执棋 ]:";
		setCursorPosition(19, 31);
		cout << "黑棋";
		setCursorPosition(22, 31);
		cout << "白棋";
		int ch=_getch();
		key[3] = 1;
		setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
		setCursorPosition(19, 31);cout << "黑棋";
		bool flag = false;
		while (ch = _getch()) {
			switch (ch) {
			case 72:	//上
				if (key[3] > 1) {
					switch (key[3]) {
					case 2:
						setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
						setCursorPosition(19, 31); cout << "黑棋";
						setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
						setCursorPosition(22, 31);cout << "白棋";
						--key[3];
						break;
					}
				}
				break;
			case 80:	//下
				if (key[3] < 2) {
					switch (key[3])
					{
					case 1:
						setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
						setCursorPosition(19, 31); cout << "黑棋";
						setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
						setCursorPosition(22, 31); cout << "白棋";
						++key[3];
						break;
					}
				}
				break;
			case 32:
			case 13:
				flag = true;
				break;
			default:
				break;
			}
			if (flag) break;
			setCursorPosition(30, 0);
		}
		switch (key[3]) {
		case 1:
			ch = _getch();
			return 31;
			break;
		case 2:
			ch = _getch();
			return 32;
			break;
		}
	}
}

void gameInterface::clearInfo(int x,int y) const{
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (int i = x; i <= y; i++) {
		setCursorPosition(i, 28);
		cout << "                                ";
	}
}

void gameInterface::creativeTips1()const {
	clearInfo(2, 26);
	setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	setCursorPosition(3, 30); cout << "创意工坊简介";
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	setCursorPosition(5, 30); cout << "    创意工坊是GomokuLib的";
	setCursorPosition(7, 30); cout << "实验功能，您可以通过创意工";
	setCursorPosition(9, 30); cout << "坊设计自己的游戏规则。不仅";
	setCursorPosition(11, 30); cout << "可以更改棋盘大小、棋盘形";
	setCursorPosition(13,30); cout << "状，也可以决定玩家数、棋子";
	setCursorPosition(15, 30); cout << "颜色，甚至能自定义获胜棋形";
	setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	setCursorPosition(18, 30); cout << "操作说明";
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	setCursorPosition(20, 30); cout << "↑、↓方向键用于切换选项";
	setCursorPosition(22, 30); cout << "←、→方向键更改选项内容";
	setCursorPosition(24, 30); cout << "回车键、空格键用于选定内容";
}

void gameInterface::creativeTips2()const {
	clearInfo(2, 26);
	setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	setCursorPosition(7, 31); cout << "操作说明";
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	setCursorPosition(9, 31); cout << "↑、↓、←、→";
	setCursorPosition(11, 31); cout << "四个方向键用于切换格子";
	setCursorPosition(13, 31); cout << "回车键、空格键用于落子";
	setCursorPosition(17, 31); cout << "九宫格内的棋形为判胜棋形";
	setCursorPosition(19, 31); cout << "即率先完成九宫格棋形的";
	setCursorPosition(21, 31); cout << "玩家最终胜利";
}

void gameInterface::creativeTips3()const {
	clearInfo(2, 26);
	setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	setCursorPosition(6, 30); cout << "操作说明";
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	setCursorPosition(8, 30);cout << "↑、↓、←、→";
	setCursorPosition(10, 30); cout << "四个方向键用于切换格子";
	setCursorPosition(12, 30); cout << "回车键、空格键用于删除格子";
	setCursorPosition(14, 30); cout << "可通过以上操作改变棋盘形状";
	setColor(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	setCursorPosition(16, 30); cout << "注意";
	setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	setCursorPosition(18, 30); cout << "如果棋盘有毛刺";
	setCursorPosition(20, 30); cout << "为了保障棋盘公平性";
	setCursorPosition(22, 30); cout << "请自行移动光标到毛刺出删除";
}