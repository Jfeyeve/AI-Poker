/*
 * cDeck.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: Jonathan
 */

#include "Card.h"
#include "Deck.h"
#include "RNG.h"
#include "SystemEnums.h"

cDeck::cDeck() {
	mDeckOfCards = new std::vector<cCard>;
	CreateDeck(mDeckOfCards);
	mCurrentCardPointer = mIndexOfFirstCardInDeck;
	mRandomNumberGenerator = new cRNG();
}

cDeck::~cDeck() {
	// TODO Auto-generated destructor stub
}

void cDeck::CreateDeck(std::vector<cCard>* aDeckOfCards)
{
	Suits lSuit;
	Cards lValue;

	for(int i = 0; i< mNumberOfSuits; i++)
	{
		switch(i)
		{
			case 0:
				lSuit = Spades;
				break;
			case 1:
				lSuit = Hearts;
				break;
			case 2:
				lSuit = Diamonds;
				break;
			case 3:
				lSuit = Clubs;
				break;
			default:
				break;
		}

		for(int j = 0; j < mNumberOfCardsPerSuit; j++)
		{
			switch(j)
			{
			case 0:
				lValue = Ace;
				break;
			case 1:
				lValue = Two;
				break;
			case 2:
				lValue = Three;
				break;
			case 3:
				lValue = Four;
				break;
			case 4:
				lValue = Five;
				break;
			case 5:
				lValue = Six;
				break;
			case 6:
				lValue = Seven;
				break;
			case 7:
				lValue = Eight;
				break;
			case 8:
				lValue = Nine;
				break;
			case 9:
				lValue = Ten;
				break;
			case 10:
				lValue = Jack;
				break;
			case 11:
				lValue = Queen;
				break;
			case 12:
				lValue = King;
				break;
			default:
				break;
			}
			cCard lCard(lSuit, lValue);

			aDeckOfCards->push_back(lCard);
		}
	}
}

cCard cDeck::DrawCard()
{
	cCard lCardToDraw = getCurrentCard();
	mCurrentCardPointer++;

	return lCardToDraw;
}

bool cDeck::Shuffle()
{
	bool lSuccess = false;

	cCard lCard1( Spades, Ace);
	cCard lCard2(Diamonds, Two);
	cCard lCard3(Clubs, Three);
	cCard lCard4(Hearts, Four);

	uint8_t lIndexToSwapFrom = mRandomNumberGenerator->getRandomNumber();
	uint8_t lIndexToSwapTo = mRandomNumberGenerator->getRandomNumber();

	lCard1 = mDeckOfCards->at(lIndexToSwapFrom);
	lCard2 = mDeckOfCards->at(lIndexToSwapTo);

	SwapACard(mDeckOfCards);

	lCard3 = mDeckOfCards->at(lIndexToSwapFrom);
	lCard4 = mDeckOfCards->at(lIndexToSwapTo);

	while(!lSuccess)
	{
		SwapACard(mDeckOfCards);

		lSuccess = CompareCards(lCard1,lCard3);
		lSuccess = CompareCards(lCard1,lCard3);
	}

	mCurrentCardPointer = mIndexOfFirstCardInDeck;

	return lSuccess;
}

void cDeck::SwapACard(std::vector<cCard>* aDeckOfCards)
{
	uint8_t lIndexToSwapFrom = 0;
	uint8_t lIndexToSwapTo = 0;

	for(int i = 0; i<mNumberOfCards; i++){
		lIndexToSwapFrom = mRandomNumberGenerator->getRandomNumber();
		lIndexToSwapTo = mRandomNumberGenerator->getRandomNumber();

		std::swap(aDeckOfCards->at(lIndexToSwapFrom), aDeckOfCards->at(lIndexToSwapTo));
	}
}

bool cDeck::CompareCards(cCard aCard, cCard aCard2)
{
	bool lSuccess = false;

	if( (aCard.mSuit != aCard2.mSuit || aCard.mValue != aCard2.mValue))
	{
		lSuccess = true;
	}

	return lSuccess;
}

cCard cDeck::getCurrentCard()
{
	return mDeckOfCards->at(mCurrentCardPointer);
}

uint8_t cDeck::getCurrentCardPointer()
{
	return mCurrentCardPointer;
}
