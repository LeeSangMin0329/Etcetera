#pragma once


#ifndef __GAMEMANAGER
#define __GAMEMANAGER


#include <iostream>
#include <iterator>
#include <random>
#include <algorithm>
#include <vector>

#include "CharactorBase.h"
#include "Player.h"

using namespace std;

class GameManager {

private:
	vector<int> mSuffledNumberCards;
	vector<CharactorCard> mSuffledCharactorCards;

	int mOpenedNumberCards[4];
	CharactorCard* mOpendCharactorCards;

	int mTotalPlayer;
	Player* mPlayerList;
	Player* mCurrentPlayer;
	int mGamePhase;

	void InitDefaultStatus(int player);

	GameManager(int totalPlayer);
	~GameManager();

	int GamePhase0();
	void GamePhase1(int command);
	void GamePhase2(int command);
	void PlayerTurnChange();


};


#endif