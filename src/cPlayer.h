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

#include "cChip.h"
#include "cPlayerStyle.h"
#include "SystemEnums.h"

class cPlayer {
public:
	cPlayer();
	virtual ~cPlayer();

	std::string mName;
	PlayerStyles mPlayerStyle;
	cChip mChips;
	std::vector<std::string> mCards;
	PlayerPositions mPlayerPosition;

	bool IsDealer();
	bool IsSmallBlind();
	bool IsBigBlind();

};

#endif /* CPLAYER_H_ */
