#include"ArtificialIntelligence.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void ai::updateFromBoard(board & GomokuBoard) {
	size = GomokuBoard.getSize();
	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= size; j++) {
			chessBoard[i][j] = GomokuBoard.getChessColor(i, j);
		}
	}
}

bool ai::isLegal(int x, int y) {
	if (x<1 || x>size || y<1 || y>size) return  false;
	return true;
}

bool ai::isSame(int x1, int y1, int x2, int y2) {
	if (!isLegal(x1, y1)) return false;
	if (!isLegal(x2, y2)) return false;
	return (chessBoard[x1][y1] == chessBoard[x2][y2]);
}

int ai::liveFour(int x, int y) {
	int cnt = 0, tmp, j;
	for (int i = 0; i < 4; i++) {		//向四个方向搜索
		tmp = 1;
		j = 1;
		while (isSame(x + dx[i] * j, y + dy[i] * j, x, y)) {
			++j; ++tmp;
		}
		j = -1;
		while (isSame(x + dx[i] * j, y + dy[i] * j, x, y)) {
			--j; ++tmp;
		}
		if (tmp == 4) ++cnt;
	}
	return cnt;
}

int ai::chongFour(int x, int y) {
	int cnt = 0, tmp, j;
	bool flag;
	for (int i = 0; i < 8; i++) {
		tmp = 0;
		flag = true;
		j = 1;
		while (isSame(x + dx[i] * j, y + dy[i] * j, x, y) || flag) {
			if (!isSame(x + dx[i] * j, y + dy[i] * j, x, y)) {
				if (flag && chessBoard[x + dx[i] * j][y + dy[i] * j] >= 0) tmp -= 10;
				flag = false;
			}
			++tmp;
			++j;
		}
		if (!isLegal(x + dx[i] * (--j), y + dy[i] * j)) continue;

		j = -1;
		while (isSame(x + dx[i] * j, y + dy[i] * j, x, y)) {
			--j; ++tmp;
		}
		if (tmp == 4) ++cnt;
	}
	return cnt - liveFour(x, y) * 2;
}

int ai::liveThree(int x, int y) {
	int cnt = 0, tmp, j;
	bool flag;
	for (int i = 0; i < 4; i++) {
		tmp = 1;
		j = 1;
		while (isSame(x + dx[i] * j, y + dy[i] * j, x, y)) {
			++j; ++tmp;
		}
		if (!isLegal(x + dx[i] * j, y + dy[i] * j) || chessBoard[x + dx[i] * j][y + dy[i] * j] >= 0) continue;
		++j;
		if (!isLegal(x + dx[i] * j, y + dy[i] * j) || chessBoard[x + dx[i] * j][y + dy[i] * j] >= 0) continue;
		j = -1;
		while (isSame(x + dx[i] * j, y + dy[i] * j, x, y)) {
			--j; ++tmp;
		}
		if (!isLegal(x + dx[i] * j, y + dy[i] * j) || chessBoard[x + dx[i] * j][y + dy[i] * j] >= 0) continue;
		--j;
		if (!isLegal(x + dx[i] * j, y + dy[i] * j) || chessBoard[x + dx[i] * j][y + dy[i] * j] >= 0) continue;
		if (tmp == 3) ++cnt;
	}
	for (int i = 0; i < 8; i++) {
		tmp = 0;
		flag = true;
		j = 1;
		while (isSame(x + dx[i] * j, y + dy[i] * j, x, y) || flag) {
			if (!isSame(x + dx[i] * j, y + dy[i] * j, x, y)) {
				if (flag && chessBoard[x + dx[i] * j][y + dy[i] * j] >= 0) tmp -= 10;
				flag = false;
			}
			++tmp;
			++j;
		}
		if (!isLegal(x + dx[i] * j, y + dy[i] * j) || chessBoard[x + dx[i] * j][y + dy[i] * j] >= 0) continue;
		if (chessBoard[x + dx[i] * (--j)][y + dy[i] * j] == -1) continue;
		j = 1;
		while (isSame(x + dx[i] * j, y + dy[i] * j, x, y)) {
			++j; ++tmp;
		}
		if (!isLegal(x + dx[i] * j, y + dy[i] * j) || chessBoard[x + dx[i] * j][y + dy[i] * j] >= 0) continue;
		if (tmp == 3) ++cnt;
	}
	return cnt;
}

bool ai::isEnd(int x, int y) {
	int count;
	int pos_x, pos_y;
	//横向遍历，找到(x,y)点横向的最大连子数；
	count = 1; pos_y = y;
	while (chessBoard[x][--pos_y] == chessBoard[x][y] && pos_y >= 1) ++count;
	pos_y = y;
	while (chessBoard[x][++pos_y] == chessBoard[x][y] && pos_y <= size) ++count;
	if (count >= 5) {
		return true;
	}
	//纵向遍历，找到(x,y)点纵向的最大连子数;
	count = 1; pos_x = x;
	while (chessBoard[--pos_x][y] == chessBoard[x][y] && pos_x >= 1) ++count;
	pos_x = x;
	while (chessBoard[++pos_x][y] == chessBoard[x][y] && pos_x <= size) ++count;
	if (count >= 5) {
		return true;
	}
	//左上-> 右下遍历；
	count = 1; pos_x = x; pos_y = y;
	while (chessBoard[--pos_x][--pos_y] == chessBoard[x][y] && pos_x >= 1 && pos_y >= 1) ++count;
	pos_x = x; pos_y = y;
	while (chessBoard[++pos_x][++pos_y] == chessBoard[x][y] && pos_x <= size && pos_y <= size) ++count;
	if (count >= 5) {
		return true;
	}
	//右上->左下遍历；
	count = 1; pos_x = x; pos_y = y;
	while (chessBoard[--pos_x][++pos_y] == chessBoard[x][y] && pos_x >= 1 && pos_y <= size) ++count;
	pos_x = x; pos_y = y;
	while (chessBoard[++pos_x][--pos_y] == chessBoard[x][y] && pos_x <= size && pos_y >= 1) ++count;
	if (count >= 5) {
		return true;
	}
	return false;
}

int ai::point(int x, int y) {
	if (isEnd(x, y)) {
		return 10000;
	}
	int ret = liveFour(x, y) * 1000 + (chongFour(x, y) + liveThree(x, y)) * 100;
	for (int i = 0; i < 8; i++) {
		if (chessBoard[x + dx[i]][y + dy[i]]>=0) ++ret;
	}
	return ret;
}

int ai::search3(int s2) {
	int res = -100000;
	int tmp;
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			if (chessBoard[i][j] != -1) continue;
			chessBoard[i][j] = color;
			tmp = point(i, j);
			if (tmp == 0) {
				chessBoard[i][j] = -1;
				continue;
			}
			if (tmp == 10000) {
				chessBoard[i][j] = -1;
				return 10000;
			}
			chessBoard[i][j] = -1;
			if (tmp - s2 * 2 > res) res = tmp - s2 * 2;
		}
	}
	return res;
}

int ai::search2() {
	int res = 100000;
	int tmp;
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			if (chessBoard[i][j] != -1) continue;
			chessBoard[i][j] = 1 - color;
			tmp = point(i, j);
			if (tmp == 0) {
				chessBoard[i][j] = -1;
				continue;
			}
			if (tmp == 10000) {
				chessBoard[i][j] = -1;
				return -10000;
			}
			tmp = search3(tmp);
			chessBoard[i][j] = -1;
			if (tmp < res) res = tmp;
		}
	}
	return res;
}

chessPoint ai::getPoint(board & GomokuBoard, int col) {
	srand(time(0));
	color = col;
	chessPoint ans;
	ans.x = 8; ans.y = 8;
	ans.color = col;
	updateFromBoard(GomokuBoard);
	if (chessBoard[8][8] == -1) {
		ans.x = 8; ans.y = 8;
		return ans;
	}
	int res = -100000;
	int tmp;
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			if (chessBoard[i][j] != -1) continue;
			chessBoard[i][j] = color;
			tmp = point(i, j);
			if (tmp == 0) {
				chessBoard[i][j] = -1;
				continue;
			}
			if (tmp == 10000) {
				ans.x = i; ans.y = j;
				return ans;
			}
			tmp = search2();
			chessBoard[i][j] = -1;
			if (tmp == res && rand()%2 == 1) {
				res = tmp;
				ans.x = i; ans.y = j;
			}
			if (tmp > res) {
				res = tmp;
				ans.x = i; ans.y = j;
			}

		}
	}
//	cout << ans.x << " " << ans.y;
	return ans;
}




