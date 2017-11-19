/*
 * cPokerGame.h
 *
 *  Created on: Nov 13, 2017
 *      Author: Jonathan
 */

#ifndef CPOKERGAME_H_
#define CPOKERGAME_H_

#include <vector>
#include <string>

#include "Player.h"
#include "Dealer.h"
#include "Bet.h"
#include "Rules.h"
#include "Chip.h"


class cPokerGame {

public:
	cPokerGame();
	virtual ~cPokerGame();

private:
std::vector<cPlayer*> mPlayers;
std::vector<std::string> mActivePlayers;
cDealer* mDealer;
cBet* mBet;
cRules* Rules;
int mRoundsPerGame;
};

#endif /* CPOKERGAME_H_ */
