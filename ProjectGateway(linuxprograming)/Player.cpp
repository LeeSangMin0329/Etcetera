#include <iostream>
#include <iterator>
#include <algorithm>
#include <random>
#include "CharactorBase.h"
#include "Player.h"


void Player::TurnStart() {
	this->mTurnCount = this->mMaxTurnCount;

}


void Player::Initialization() {
	mHand.clear();
	delete(mTable);
	mTable = new CharactorCard[2];
	mPassiveList.clear();

	mMaxHandCount = 5;
	mMaxTurnCount = 3;
	mTotalPower = 0;
	mDiamondCount = 0;
}
