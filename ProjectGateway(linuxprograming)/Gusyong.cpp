#include <iostream>
#include "CharactorBase.h"

using namespace std;

class Gusyong : public CharactorCard {
	
public:
	Gusyong() {
		this->mDiamond = 0;
		this->mExplainText = "���¿��Դϴ�.";
		this->mName = "������";
		this->mPower = 1;
		this->mRequiredNumberCardCount = 2;
		this->mSkillSerialNumber = 584;
		this->mCardSerialNumber = 1;
	}

	//@override
	bool ConditionOfGetPower(int card1, int card2) {
		if (card1 == 1 && card2 == 8)
			return true;
		return false;
	}

};