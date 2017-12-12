/*
 * cGames.h
 *
 *  Created on: Nov 13, 2017
 *      Author: Jonathan
 */

#ifndef CGAMES_H_
#define CGAMES_H_

#include <map>

#include "Bet.h"
#include "Chip.h"
#include "Log.h"
#include "MoneyManager.h"
#include "Player.h"
#include "Rules.h"
#include "SystemEnums.h"

class cDealer;

class cGame
{
public:
	cGame(uint32_t aNumberOfGames, uint16_t aRoundsPerGame,
			uint8_t aTotalPlayers, uint32_t aChipsPerPlayer,
			uint32_t aSmallBlind, uint32_t aBigBlind,
			std::map<std::string, PlayerStyles>* aPlayerProfiles);

	virtual ~cGame();

	void DisplayGameParameters();
	bool StartTheGame();

	std::vector<cPlayer*> getGamePlayers();

private:
	uint32_t mNumberOfGames;
	uint16_t mRoundsPerGame;
	uint8_t mTotalPlayers;
	uint32_t mChipsPerPlayer;
	uint32_t mSmallBlind, mBigBlind;

	std::map<std::string, PlayerStyles>* mPlayerProfiles;
	std::vector<std::string> mActivePlayers;

	cRules* mRules;
	cLog* mLog;

	std::vector<cPlayer*> mGamePlayers;

	bool CreatePlayers(uint8_t aTotalPlayers, std::map<std::string, PlayerStyles>* aPlayerProfiles, std::vector<cPlayer*>* aGamePlayers);
	bool CreateDealer();
	bool CreateMoneyManager();
};

#endif /* CGAMES_H_ */
