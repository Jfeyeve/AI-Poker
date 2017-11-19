/*
 * cPlayer.h
 *
 *  Created on: Nov 13, 2017
 *      Author: Jonathan
 */

#ifndef CPLAYER_H_
#define CPLAYER_H_

#include <string>
#include <vector>

#include "Card.h"
#include "cChip.h"
#include "cPlayerStyle.h"
#include "SystemEnums.h"

class cPlayer {
public:
	cPlayer(std::string aName, PlayerStyles aPlayerStyle, uint32_t aChips);
	virtual ~cPlayer();

	std::string mName;
	PlayerStyles mPlayerStyle;
	uint32_t mChips;
	std::vector<cCard>* mCards;
	PlayerPositions mPlayerPosition;

	bool mIsDealer;
	bool mIsSmallBlind;
	bool mIsBigBlind;

	bool IsDealer();
	bool IsSmallBlind();
	bool IsBigBlind();

	bool setPosition(PlayerPositions aPosition);
	bool receiveCard(cCard aCard);

	Bets GetBet();

private:
	Bets SelectBet();
};

#endif /* CPLAYER_H_ */
