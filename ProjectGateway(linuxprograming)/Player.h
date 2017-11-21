#pragma once
#ifndef __PLAYER
#define __PLAYER


class Player {
private:
	vector<int> mHand;
	CharactorCard* mTable;

	vector<int> mPassiveList;

	int mMaxHandCount;
	int mMaxTurnCount;
	int mTurnCount;
	int mTotalPower;
	int mDiamondCount;


public:
	void TurnStart();
private:
	void Initialization();

};


#endif