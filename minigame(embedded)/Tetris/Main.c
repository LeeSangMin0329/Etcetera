#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

#include "block.h"

#define true 1
#define false 0

#define MaxWidth 9
#define MaxHeight 14

#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define UP 72
#define SPACE 32
#define PAUSE 80
#define PAUSE2 112
#define ESC 27

int level;
int score;
int nextScore;
int key;
int speed;

int map[MaxHeight + 2][MaxWidth + 2] = { 0, };
int bx;
int by;
int blockType;
int blockTypeNext;
int blockLotate;
int clearLineNum;

int createBlockPlz = 1;
int isCrush = 0;
int levelup = 0;
int spaceFlag = 0;

void init(void);
void MapClear(void);
void CreateBlock(void);
void DropBlock(void);
int CollitionDetect(int x, int y, int bLotate);
void MoveBlock(int dir);
void CheckLine(void);

void MainGame(void);
void OnDraw(void);

void MapClear(void) {
	int i, j;

	for (i = 0; i < MaxHeight; ++i)
		for (j = 0; j < MaxWidth; ++j)
			map[i][j] = 0;

	for (i = 1; i < MaxHeight; i++) {
		map[i][0] = 3;
		map[i][MaxWidth- 1] = 3;
	}

	for (i = 0; i < MaxWidth; ++i) {
		map[MaxHeight -1][i] = 3;
	}

}

void init(void) {
	level = 1;
	score = 0;
	nextScore = 1000;
	key = 0;
	isCrush = false;
	speed = 100;
	clearLineNum = 0;

	MapClear();
	OnDraw();

	blockTypeNext = rand() % 7;
	CreateBlock();
}



void CreateBlock(void) {
	int i, j;

	bx = (MaxWidth / 2) - 1;
	by = 0;
	blockType = blockTypeNext;
	blockTypeNext = rand() % 7;
	blockLotate = 0;

	createBlockPlz = false;

	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			if (blocks[blockType][blockLotate][i][j] == 1)
				map[by + i][bx + j] = -1;
}

void DropBlock(void) {
	int i, j;

	if (isCrush && CollitionDetect(bx, by + 1, blockLotate) == true)
		isCrush = false;

	if (isCrush && CollitionDetect(bx, by + 1, blockLotate) == false) {
		for(i=0; i<MaxHeight; ++i)
			for (j = 0; j < MaxWidth; ++j) {
				if (map[i][j] == -1)
					map[i][j] = 1;
			}

		isCrush = false;
		CheckLine();
		createBlockPlz = true;
		return;
	}
	
	if (CollitionDetect(bx, by + 1, blockLotate) == true) {
		MoveBlock(DOWN);
	}
	if (CollitionDetect(bx, by + 1, blockLotate) == false)
		isCrush = true;
}

int CollitionDetect(int bx, int by, int blockLotate) {
	int i, j;

	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			if (blocks[blockType][blockLotate][i][j] == 1 && map[by + i][bx + j] > 0)
				return false;
		}
	}

	return true;
}

void MoveBlock(int dir) {
	int i, j;

	switch (dir) {
	case LEFT:
		for (i = 0; i < 4; ++i)
			for (j = 0; j < 4; ++j)
				if (blocks[blockType][blockLotate][i][j] == 1)
					map[by + i][bx + j] = 0;

		for (i = 0; i < 4; ++i)
			for (j = 0; j < 4; ++j)
				if (blocks[blockType][blockLotate][i][j] == 1)
					map[by + i][bx + j - 1] = -1;
		bx--;
		break;

	case RIGHT:
		for (i = 0; i < 4; ++i)
			for (j = 0; j < 4; ++j)
				if (blocks[blockType][blockLotate][i][j] == 1)
					map[by + i][bx + j] = 0;

		for (i = 0; i < 4; ++i)
			for (j = 0; j < 4; ++j)
				if (blocks[blockType][blockLotate][i][j] == 1)
					map[by + i][bx + j + 1] = -1;
		bx++;
		break;

	case DOWN:
		for (i = 0; i < 4; ++i)
			for (j = 0; j < 4; ++j)
				if (blocks[blockType][blockLotate][i][j] == 1)
					map[by + i][bx + j] = 0;

		for (i = 0; i < 4; ++i)
			for (j = 0; j < 4; ++j)
				if (blocks[blockType][blockLotate][i][j] == 1)
					map[by + i + 1][bx + j] = -1;
		by++;
		break;

	case UP:
		for(i = 0; i<4; ++i)
			for(j = 0; j<4; ++j)
				if (blocks[blockType][blockLotate][i][j] == 1)
					map[by + i][bx + j] = 0;

		blockLotate = (blockLotate + 1) % 4;
		for (i = 0; i<4; ++i)
			for (j = 0; j<4; ++j)
				if (blocks[blockType][blockLotate][i][j] == 1)
					map[by + i][bx + j] = -1;
		break;

	case 100:
		for (i = 0; i<4; ++i)
			for (j = 0; j<4; ++j)
				if (blocks[blockType][blockLotate][i][j] == 1)
					map[by + i][bx + j] = 0;
		blockLotate = (blockLotate + 1) % 4;
		for(i = 0; i<4; ++i)
			for(j = 0; j<4; ++j)
				if (blocks[blockType][blockLotate][i][j] == 1)
					map[by + i - 1][bx + j] = -1;
		by--;
		break;
	}
}

void CheckLine(void) {
	int i, j, k, l;

	int oneLineBlockAmount;
	int combo = 0;

	for (i = MaxHeight - 2; i > 3; ) {
		oneLineBlockAmount = 0;
		for (j = 1; j < MaxWidth - 1; ++j) {
			if (map[i][j] > 0)
				oneLineBlockAmount++;
		}
		if (oneLineBlockAmount == MaxWidth - 2) {
			if (levelup == false) {
				score += 100 * level;
				clearLineNum++;
				combo++;
			}
			for (k = i; k > 1; --k) {
				for (l = 1; l < MaxWidth - 1; ++l) {
					map[k][l] = map[k - 1][l];
				}
			}
		}
		else
			i--;
	}

	if (combo) {
		score += (combo * level * 100);
	}
}

void CheckLevelUp(void) {

	if (clearLineNum >= 10) {
		levelup = true;
		level++;
		clearLineNum = 0;
	}

	switch (level) {
	case 2:
		speed = 50;
		break;
	case 3:
		speed = 25;
		break;
	case 4:
		speed = 10;
		break;
	case 5:
		speed = 5;
		break;
	case 6:
		speed = 4;
		break;
	case 7:
		speed = 2;
		break;
	case 8:
		speed = 0;
		break;
	}

	levelup = false;
}

void CheckGameOver(void) {
	int i;

	for(i=1; i<MaxWidth - 2; ++i)
		if (map[3][i] > 0) {
			printf("gameover");
			init();
		}
}

void InputKey(void) {
	key = 0;

	if (_kbhit()) {
		key = _getch();
		if (key == 224) {
			do {
				key = _getch();
			} while (key == 224);

			switch (key) {
			case LEFT:
				if (CollitionDetect(bx - 1, by, blockLotate) == true)
					MoveBlock(LEFT);
				break;
			case RIGHT:
				if (CollitionDetect(bx + 1, by, blockLotate) == true)
					MoveBlock(RIGHT);
				break;
			case DOWN:
				if (CollitionDetect(bx, by + 1, blockLotate) == true)
					MoveBlock(DOWN);
				break;
			case UP:
				if (CollitionDetect(bx, by, (blockLotate + 1) % 4) == true)
					MoveBlock(UP);
				else if (isCrush == true && CollitionDetect(bx, by - 1, (blockLotate + 1) % 4) == true)
					MoveBlock(100);
			}
		}
		else {
			switch (key) {
			case SPACE:
				spaceFlag = true;
				while (isCrush == false) {
					DropBlock();
				}
				break;
			case PAUSE:
			case PAUSE2:
			case ESC:
				exit(0);
			}
		}
	}
	while (_kbhit())
		_getch();
}

void OnDraw(void) {
	int i, j;
	system("cls");
	for (i = 0; i < MaxHeight; ++i) {
		for (j = 0; j < MaxWidth; ++j) {
			
			
			if (map[i][j] == 0)
				printf("  ");
			else
				printf("бс");
			
			//printf("%d", map[i][j]);
		}
		printf("\n");
	}
}

void MainGame(void) {
	int i;

	srand(time(NULL));

	init();

	
	
	while (1) {
		for (i = 0; i < 5; ++i) {
			
			InputKey();
			OnDraw();

			Sleep(speed);
			if (isCrush && CollitionDetect(bx, by + 1, blockLotate) == false)
				Sleep(100);

			if (spaceFlag == true) {
				spaceFlag = 0;
				break;
			}
		}
		
		DropBlock();
		CheckLevelUp();
		CheckGameOver();
		if (createBlockPlz == 1)
			CreateBlock();
	}
}

int main(void) {

	MainGame();
	return 0;
}