#include<iostream>
#include<string>
#include<conio.h>
#include"Board.h"
#include"windows.h"
#include"Tools.h"
#include"GameInterface.h"
#include"SGF.h"
#include"Control.h"
#include<iomanip>
using namespace std;
int main() {
	gameInterface gameCon;
	int menuResult;
	while (1) {
		gameCon.start();
		menuResult = gameCon.firstMenu();
		switch (menuResult) {
		case 11:commonGomoku();
			break;
		case 13:sgfReadIn();
			break;
		case 16:creativeGame(16);
			break;
		case 17:creativeGame(17);
			break;
		case 31:AIGame(1);
			break;
		case 32:AIGame(0);
			break;
		}
	}
	return 0;
}