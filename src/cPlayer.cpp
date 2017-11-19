/*
 * cPlayer.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: Jonathan
 */
#include "SystemEnums.h"
#include "cPlayer.h"

cPlayer::cPlayer(std::string aName, PlayerStyles aPlayerStyle, uint32_t aChips) {
	mName = aName;
	mPlayerStyle = aPlayerStyle;
	mChips = aChips;

	mPlayerPosition = NotAssigned;

	mIsSmallBlind = false;
	mIsBigBlind = false;
	mIsDealer = false;

	//Empty hand of cards until the game starts
	mCards = new std::vector<cCard>();
}

cPlayer::~cPlayer() {
	// TODO Auto-generated destructor stub
}

bool cPlayer::IsDealer(){
	return mIsDealer;
}

bool cPlayer::IsSmallBlind()
{
	return mIsSmallBlind;
}

bool cPlayer::IsBigBlind()
{
	return mIsBigBlind;
}

bool cPlayer::setPosition(PlayerPositions aPosition)
{
	bool lSuccess = false;

	mPlayerPosition = aPosition;

	if(mPlayerPosition == aPosition){
		lSuccess = true;
	}

	return lSuccess;
}

bool cPlayer::receiveCard(cCard aCard)
{
	bool lSuccess = false;

	mCards->push_back(aCard);

	if(mCards->back().mValue == aCard.mValue &&
			mCards->back().mSuit == aCard.mSuit)
	{
		lSuccess = true;
	}

	return lSuccess;
}

Bets cPlayer::GetBet()
{
	return SelectBet();
}

Bets cPlayer::SelectBet()
{
	Bets lBet = NoBetSelected;
	return lBet;
}
