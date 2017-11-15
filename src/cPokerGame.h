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

#include "cPlayer.h"
#include "cDealer.h"
#include "cBet.h"
#include "cRules.h"
#include "cChip.h"


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
int mRounds;
};

#endif /* CPOKERGAME_H_ */
