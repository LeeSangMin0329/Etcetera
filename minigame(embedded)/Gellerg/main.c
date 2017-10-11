#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#include "Enemy.h"

#define DEBUG 1

#define MapWidth (13)
#define MapHeight (15)

#define EnemyDelay (1)
#define EnemyHp (5)
#define PatternCategory (5)
#define PatternSize (12)

struct pos {
	char x;
	char y;
};
struct Player {
	struct pos shape[4];
	int hp;
}typedef Player;

struct {
	int x;
	int y;
	int enable;
}typedef Bullet;

struct EnemyBullet {
	int x;
	int y;
	int hp;
	int enable;
	int delay;
}typedef EnemyBullet;

struct Enemy{
	struct pos shape[4];
	int hp;
	int delay;
	int pattern;
	int patternCount;
}typedef Enemy;

void MoveBullet(Bullet* b, int count) {
	int i;
	for (i = 0; i < count; ++i) {
		if ((b+i)->enable == 1) {
			if ((b + i)->y - 1 < 0)
				(b + i)->enable = 0;
			else
				(b + i)->y--;
		}
	}
}

int createEnemy(Enemy* enemy, int count) {
	int i, rnd;
	for (i = 0; i < count;++i) {
		srand(time(NULL));
		rnd = (rand() % 7) + 3;
		if (enemy[i].hp <= 0) {
			enemy[i].shape[0].x = rnd;
			enemy[i].shape[0].y = 3;
			enemy[i].shape[1].x = rnd - 1;
			enemy[i].shape[1].y = 2;
			enemy[i].shape[2].x = rnd;
			enemy[i].shape[2].y = 2;
			enemy[i].shape[3].x = rnd + 1;
			enemy[i].shape[3].y = 2;

			enemy[i].delay = EnemyDelay;
			enemy[i].pattern = rand() % PatternCategory;
			enemy[i].patternCount = 0;
			enemy[i].hp = EnemyHp;
			return 1;
		}
	}
	return 0;
}

void MoveEnemy(Enemy* enemy, int count) {
	int i, j;
	for (i = 0; i < count; ++i) {
		if (enemy[i].hp > 0) {
			if (enemy[i].delay > 0) {
				enemy[i].delay--;
			}
			else {
				enemy[i].delay = EnemyDelay;
				for (j = 0; j < 4; ++j) {
					enemy[i].shape[j].x += Pattern[enemy[i].pattern][enemy[i].patternCount * 2];
					enemy[i].shape[j].y += Pattern[enemy[i].pattern][enemy[i].patternCount * 2 + 1];
				}

				// out of map ( x 1~11, y 14 )
				if (enemy[i].shape[1].x < 1 || enemy[i].shape[3].x > 11 || enemy[i].shape[0].y > 14) {
					enemy[i].hp = 0;
					continue;
				}

				enemy[i].patternCount++;
				if (enemy[i].patternCount == PatternSize) {
					enemy[i].patternCount = 0;
					enemy[i].pattern = rand() % PatternCategory;
				}
			}
		}
	}
}

void CollitionDetect(Enemy* enemy, int enemyCount, Player* player, Bullet* bullet, int bulletCount) {
	int i, j, k;
	for (i = 0; i < enemyCount; ++i) {
		for (j = 0; j < 4; ++j) {
			if (enemy[i].hp > 0 && player->shape[2].x == enemy[i].shape[j].x && player->shape[2].y == enemy[i].shape[j].y) {
				player->hp--;
			}
		}
	}
	for (i = 0; i < bulletCount; ++i) {
		for (j = 0; j < enemyCount; ++j) {
			for(k = 0; k<4; ++k)
				if (enemy[j].hp > 0 && bullet[i].enable == 1 && bullet[i].x == enemy[j].shape[k].x && bullet[i].y == enemy[j].shape[k].y) {
					bullet[i].enable = 0;
					enemy[j].hp--;
				}
		}
	}
}

void MainGame(void) {

	int i, j;
	int key;
	srand(time(NULL));

	char map[MapHeight][MapWidth] = { 0, };

	struct Player player = { {{6,11},{5,12},{6,12},{7,12}}, 1 };

	Bullet bullet[5];
	for (i = 0; i < 5; ++i) {
		bullet[i].enable = 0;
		bullet[i].x = 0;
		bullet[i].y = 0;
	}

	Enemy enemy[5];
	for (i = 0; i < 5; ++i) {
		enemy[i].hp = 0;
	}

	EnemyBullet eBullet[10];
	for (i = 0; i < 10; ++i) {
		eBullet[i].enable = 0;
		eBullet[i].hp = 1;
		eBullet[i].x = 0;
		eBullet[i].y = 0;
	}
	
	int loopCount = 0;
	// Game Loop
	while (player.hp > 0) {
		loopCount++;
		system("cls");

		for (i = 0; i < MapHeight; ++i)
			for (j = 0; j < MapWidth; ++j)
				map[i][j] = 0;


		// key input
		if (_kbhit() != 0) {
			key = _getch();

			switch (key) {
			case 'a':
				if (player.shape[1].x == 3)
					break;
				for (i = 0; i < 4; ++i)
					player.shape[i].x--;
				break;
			case 'd':
				if (player.shape[3].x == 9)
					break;
				for (i = 0; i < 4; ++i)
					player.shape[i].x++;
				break;
			case 'f':
				for (i = 0; i < 5; ++i) {
					if (bullet[i].enable == 0) {
						bullet[i].enable = 1;
						bullet[i].x = player.shape[0].x;
						bullet[i].y = player.shape[0].y;
						break;
					}
				}
				break;
			}

		}

		if (loopCount%5 == 0) {
			createEnemy(enemy, 5);
		}

		MoveEnemy(enemy, 5);
		MoveBullet(bullet, 5);
		CollitionDetect(enemy, 5, &player, bullet, 5);

		for (i = 0; i < 5; ++i) {
			map[bullet[i].y][bullet[i].x] = 2;
		}
		for (i = 0; i < 4; ++i)
			map[player.shape[i].y][player.shape[i].x] = 1;
		for (i = 0; i < 5; ++i)
			for (j = 0; j < 4; ++j)
				map[enemy[i].shape[j].y][enemy[i].shape[j].x] = 3;


		if (!DEBUG) {
			// Width 3 ~ 9
			// Height 3 ~ 12
			// map print
			for (i = 3; i < 13; ++i) {
				for (j = 3; j < 10; ++j)
					if (map[i][j] == 0)
						printf(" ");
					else printf("%d", map[i][j]);
				printf("\n");
			}
		}
		else {
			for (i = 0; i < MapHeight; ++i) {
				for (j = 0; j < MapWidth; ++j)
					if (map[i][j] == 0)
						printf(" ");
					else printf("%d", map[i][j]);
				printf("\n");
			}
		}
		
		Sleep(100);
	}
}

int main(void) {

	MainGame();
	return 0;

}