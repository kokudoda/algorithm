#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define FIELD_WIDTH 24 
#define FIELD_HEIGHT 24

int cells[2][FIELD_HEIGHT][FIELD_WIDTH]; //盤面のセルの状態。2つの盤面を用意し、ダブルバッファリング
int current; //現在の世代
 
int cursorX, cursorY;  //カーソル

int getAdjacentLiveCount(int _x,int _y) {  //隣り合う生きているセルの数を数える
	int count = 0;
	for (int y = -1; y <= 1; y++) {
		for (int x = -1; x <= 1; x++) {
			if ((x == 0) && (y == 0)) continue;

			int x2 = (FIELD_WIDTH +_x + x) % FIELD_WIDTH;  //フィールドの範囲外に行かないようにする
			int y2 = (FIELD_HEIGHT + _y + y) % FIELD_HEIGHT;
			count += cells[current][y2][x2];
		}
	}
	return count;
}
int main() {
	while (1) {
		system("cls");  //画面クリア
		for (int y = 0; y < FIELD_HEIGHT; y++) {
			for (int x = 0; x < FIELD_WIDTH; x++) {
				if ((x == cursorX) && (y == cursorY)) printf("+"); //+はカーソル
				else
					printf("%s",cells[current][y][x]?"*":"."); 
			}
			printf("\n");
		}
		switch (_getch()) {
		case 'w':	cursorY--; break;   //上
		case 's':	cursorY++; break;   //下
		case 'a':	cursorX--; break;   //左
		case 'd':	cursorX++; break;   //右
		case ' ':	cells[current][cursorY][cursorX] ^= 1; break; //spaceキーでセル選択
		case 0x1B:	//escキーで初期化
			for (int y = 0; y < FIELD_HEIGHT; y++) {
				for (int x = 0; x < FIELD_WIDTH; x++) {
					cells[current][y][x] = 0;
				}
			}
			break;
		case '\r':	//enterキーで世代更新
			for (int y = 0; y < FIELD_HEIGHT; y++) {
				for (int x = 0; x < FIELD_WIDTH; x++) {
					int n = getAdjacentLiveCount(x, y); //周りのセルの生存数
					int next = cells[current][y][x]; //次の世代で,その場所のセルの状態
					if (cells[current][y][x] == 1) { //セルが生きているとき
						if ((n <= 1) || (n >= 4)) next = 0;  // 周りのセルの生存数が1以下or4以上の時、死滅
					}
					else { //セルが死んでいるとき
						if (n == 3) next = 1;  //周りのセルの生存数が3の時、誕生
					}
					cells[current ^ 1][y][x] = next; // 更新
				}
			}
			current ^= 1;
			break;
		}
	}
}