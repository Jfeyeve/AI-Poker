/*
 * cDeck.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: Jonathan
 */

#include "Card.h"
#include "Deck.h"
#include "SystemEnums.h"

cDeck::cDeck() {
	mDeckOfCards = new std::vector<cCard>;
	mCurrentCardPointer = 0;
}

cDeck::~cDeck() {
	// TODO Auto-generated destructor stub
}

void cDeck::CreateDeck(std::vector<cCard>* aDeckOfCards)
{
	Suits lSuit;
	Cards lValue;
	uint8_t lNumberOfSuits = 4;
	uint8_t lNumberOfCardsPerSuit = 13;

	for(int i = 0; i< lNumberOfSuits; i++)
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

		for(int j = 0; j < lNumberOfCardsPerSuit; j++)
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

void cDeck::DrawCard()
{

}

void cDeck::Shuffle( cDeck* aDeck )
{

}

void cDeck::Deal()
{

}

void cDeck::BurnCard()
{

}

void cDeck::River()
{

}

void cDeck::Turn()
{

}
