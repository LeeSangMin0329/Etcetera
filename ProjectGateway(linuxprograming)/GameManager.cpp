
#include "GameManager.h"
#include <random>
#include <cmath>

GameManager::GameManager(int totalPlayer) {
	this->mGamePhase = 0;
	this->mOpendCharactorCards = new CharactorCard[2];
	this->mTotalPlayer = totalPlayer;
	this->mPlayerList = new Player[totalPlayer];
};

void GameManager::InitDefaultStatus(int player) {
	this->mGamePhase = 0;

};

int GameManager::GamePhase0() {
	this->mCurrentPlayer = mPlayerList[rand() % mTotalPlayer + 1];
};

