/*
 * cGames.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: Jonathan
 */
#include <vector>
#include <string>
#include <iostream>

#include "cGames.h"
#include "cLog.h"



std::vector<std::string>* mPlayerNames;
cLog* mLog;

cGames::cGames(int aNumberOfGames, int aRoundsPerGame, int aTotalPlayers,
		    	int aChipsPerPlayer, int aSmallBlind, int aBigBlind,
				std::vector<std::string>* aPlayerNames)
{
	mNumberOfGames = aNumberOfGames;
	mRoundsPerGame = aRoundsPerGame;
	mTotalPlayers = aTotalPlayers;
	mChipsPerPlayer = aChipsPerPlayer;
	mSmallBlind = aSmallBlind;
	mBigBlind = aBigBlind;

	mPlayerNames = aPlayerNames;
	mLog = new cLog();
}

cGames::~cGames() {
	// TODO Auto-generated destructor stub
	delete mLog;
}

/*
 * Display the game parameters requested by the user
 */
void cGames::DisplayGameParameters()
{
	std::cout<< "Total Games: "<< mNumberOfGames<<std::endl;
	std::cout<< "Total Rounds: "<< mRoundsPerGame<<std::endl;
	std::cout<< "Total Players: "<< mTotalPlayers<<std::endl;
	std::cout<< "Total Chips per player: "<< mChipsPerPlayer<<std::endl;
	std::cout<< "Total Small Blind: "<< mSmallBlind<<std::endl;
	std::cout<< "Total Big Blind: "<< mBigBlind<<std::endl;
}

/*
 * Instantiate objects necessary to start a game
 */
bool cGames::StartTheGames()
{
	bool lSuccess = false;

	return lSuccess;
}

