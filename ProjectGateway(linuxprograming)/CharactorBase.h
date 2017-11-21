#pragma once
#ifndef __CHARACTORBASE
#define __CHARACTORBASE


class CharactorCard {
protected:

	string mExplainText;
	int mPower;
	int mDiamond;
	string mName;

	int mSkillSerialNumber;
	int mCardSerialNumber;

	int mRequiredNumberCardCount;

public:
	virtual bool ConditionOfGetPower() {
	}
	
};

#endif // !