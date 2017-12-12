/*
 * cRules.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: Jonathan
 */
#include <algorithm>
#include "Rules.h"
#include "SystemEnums.h"

cRules::cRules() {
	InitializeWinningHands();
}

cRules::~cRules() {
	// TODO Auto-generated destructor stub
}

bool cRules::IsRoyalFlush(std::vector<cCard*> aHand)
{
	bool lSuccess = false;
	Suit lSuitOfHand = aHand.at(0)->mSuit;
	cCard lCard();

	for(std::vector<cCard*>::iterator it = aHand.begin(); it != aHand.end(); ++it) {
		//If we don't have the same suit, we cant have a Royal Flush
		if( (*it)->mSuit != lSuitOfHand){
			lSuccess = false;
			break;
		}

		if((*it)->mValue != mRoyalFlush.at(FlopCard1)->mValue &&
				(*it)->mValue != mRoyalFlush.at(FlopCard2)->mValue &&
				(*it)->mValue != mRoyalFlush.at(FlopCard3)->mValue &&
				(*it)->mValue != mRoyalFlush.at(TurnCard4)->mValue &&
				(*it)->mValue != mRoyalFlush.at(RiverCard5)->mValue)
		{
			lSuccess = false;
			break;
		}

		if(it == aHand.end()-1){
			lSuccess = true;
		}
	}

	return lSuccess;
}

bool cRules::IsStraightFlush(std::vector<cCard*> aHand)
{
	bool lSuccess = false;
	Suit lSuitOfHand = aHand.at(0)->mSuit;
	cCard* lPreviousCard = aHand.at(0);

	std::sort(aHand.begin(), aHand.end(), compare);

	for(std::vector<cCard*>::iterator it = aHand.begin(); it != aHand.end(); ++it) {
		//If we don't have the same suit, we cant have a straight Flush
		if( (*it)->mSuit != lSuitOfHand){
			lSuccess = false;
			break;
		}

		if(it >= aHand.begin()+1)
		{
			if(lPreviousCard->mValue > (*it)->mValue){
				break;
			}
			else if(it == aHand.end()-1){
				lSuccess = true;
				break;
			}
		}

		lPreviousCard = (*it);
	}

	return lSuccess;
}

void cRules::InitializeWinningHands()
{
	cCard *lAceCard = new cCard(Spades, Ace);
	cCard *lKingCard = new cCard(Spades, King);
	cCard *lQueenCard = new cCard(Spades, Queen);
	cCard *lJackCard = new cCard(Spades, Jack);
	cCard *lTenCard = new cCard(Spades, Ten);

	mRoyalFlush.push_back(lAceCard);
	mRoyalFlush.push_back(lKingCard);
	mRoyalFlush.push_back(lQueenCard);
	mRoyalFlush.push_back(lJackCard);
	mRoyalFlush.push_back(lTenCard);
}
