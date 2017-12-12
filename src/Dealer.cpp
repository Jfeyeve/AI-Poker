/*
 * cDealer.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: Jonathan
 */

#include <exception>
#include <iostream>

#include "Dealer.h"
#include "SystemEnums.h"

cDealer::cDealer() {
	mDeck = new cDeck();
	mTableCards = new std::vector<cCard>;
}

cDealer::~cDealer() {
	delete mDeck;
}

bool cDealer::DealToPlayers(std::vector<cPlayer*> aPlayers, int aCardsPerPlayer)
{
	bool lSuccess = false;
	try{
		for(int i = 0; i< aCardsPerPlayer; i++)
		{
			for(auto & player : aPlayers) {
			    DealToPlayer(player);
			}
		}

		lSuccess = true;
	}
	catch(std::exception& error)
	{
		std::cout<< error.what() <<std::endl;
	}

	return lSuccess;
}

bool cDealer::DealToPlayer(cPlayer* aPlayer)
{
	bool lSuccess = false;

	try{

		aPlayer->mCards->push_back(mDeck->DrawCard());

		lSuccess = true;
	}
	catch(std::exception& error)
	{
		std::cout<< error.what() <<std::endl;
	}

	return lSuccess;
}

void cDealer::BurnCard()
{
	mDeck->DrawCard();
}

bool cDealer::DealFlop()
{
	bool lSuccess = false;
	BurnCard();

	try{
		for(int i = 0; i< TotalFlopCards; i++)
		{
			mTableCards->push_back(mDeck->DrawCard());
		}

		lSuccess = true;
	}
	catch(std::exception& error)
	{
		std::cout<< error.what() <<std::endl;
	}

	return lSuccess;
}

bool cDealer::DealTurn()
{
	bool lSuccess = false;

	BurnCard();

	try{
		mTableCards->push_back(mDeck->DrawCard());

		lSuccess = true;
	}
	catch(std::exception& error)
	{
		std::cout<< error.what() <<std::endl;
	}

	return lSuccess;
}

bool cDealer::DealRiver()
{
	bool lSuccess = false;

	BurnCard();

	try{
		mTableCards->push_back(mDeck->DrawCard());

		lSuccess = true;
	}
	catch(std::exception& error)
	{
		std::cout<< error.what() <<std::endl;
	}

	return lSuccess;
}


std::vector<cCard>* cDealer::GetTableCards()
{
	return mTableCards;
}
