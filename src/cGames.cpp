/*
 * cGames.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: Jonathan
 */
#include <vector>
#include <string>

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
}



