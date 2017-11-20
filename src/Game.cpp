/*
 * cGames.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: Jonathan
 */
#include <vector>
#include <string>
#include <iostream>

#include "Game.h"

cGame::cGame(uint32_t aNumberOfGames, uint16_t aRoundsPerGame,
		uint8_t aTotalPlayers, uint32_t aChipsPerPlayer, uint32_t aSmallBlind,
		uint32_t aBigBlind, std::map<std::string, PlayerStyles>* aPlayerProfiles)
{
	mNumberOfGames = aNumberOfGames;
	mRoundsPerGame = aRoundsPerGame;
	mTotalPlayers = aTotalPlayers;
	mChipsPerPlayer = aChipsPerPlayer;
	mSmallBlind = aSmallBlind;
	mBigBlind = aBigBlind;
	mPlayerProfiles = aPlayerProfiles;

	mRules = new cRules();
	mLog = new cLog();
}

cGame::~cGame()
{
	delete mLog;
    delete mRules;
}
/*
 * DmLog = new cLisplay the game parameters requested by the user
 */
void cGame::DisplayGameParameters()
{
	std::cout << "Total Games: " << mNumberOfGames << std::endl;
	std::cout << "Total Rounds: " << mRoundsPerGame << std::endl;
	std::cout << "Total Players: " << mTotalPlayers << std::endl;
	std::cout << "Total Chips per player: " << mChipsPerPlayer << std::endl;
	std::cout << "Total Small Blind: " << mSmallBlind << std::endl;
	std::cout << "Total Big Blind: " << mBigBlind << std::endl;
}

/*
 * Instantiate objects necessary to start a game
 */
bool cGame::StartTheGame()
{
	bool lSuccess = false;

	lSuccess = CreatePlayers(mTotalPlayers, mPlayerProfiles, &mGamePlayers);
	//lSuccess = CreateDealer();
	//lSuccess = CreateMoneyManager();

	return lSuccess;
}

/*
 * Create the players
 */
bool cGame::CreatePlayers(uint8_t aTotalPlayers, std::map<std::string, PlayerStyles>* aPlayerProfiles,
							std::vector<cPlayer*>* aGamePlayers)
{
	/*
	 * Local variables
	 */
	bool lSuccess = false;
	size_t lTotalPlayers = (size_t)aTotalPlayers;

	/*
	 * Iterator for map
	 */
	std::map<std::string, PlayerStyles>::iterator it;

	/*
	 * Save the Player Profiles which include name and style, in the Game Player vector
	 */
	for(it = aPlayerProfiles->begin(); it != aPlayerProfiles->end(); it++)
	{
		//TODO: Make a Factory for the player creation
		cPlayer* lPlayer = new cPlayer(it->first, it->second, mChipsPerPlayer);

		aGamePlayers->push_back(lPlayer);
	}

	/*
	 * Check that we saved the correct amount of players
	 */
	if( aGamePlayers->size() == lTotalPlayers)
	{
		lSuccess = true;
	}

	return lSuccess;
}

/*
 * Create the dealer
 */
bool cGame::CreateDealer()
{
	bool lSuccess = false;

	return lSuccess;
}

/*
 * Create the money manager
 */
bool cGame::CreateMoneyManager()
{
	bool lSuccess = false;

	return lSuccess;
}
