/*
 * cDealer.h
 *
 *  Created on: Nov 13, 2017
 *      Author: Jonathan
 */

#ifndef CDEALER_H_
#define CDEALER_H_

#include <vector>

#include "cDeck.h"
#include "cGame.h"
#include "cPlayerPosition.h"
#include "SystemEnums.h"

class cGame;

class cDealer {
public:
	cDealer();
	virtual ~cDealer();

	cDeck mDeck;
	cPlayerPosition mPlayerPositionManager;

	std::vector<GamePhases> mGamePhases;
	std::string mCurrentGamePhase;
	std::vector<std::string> mTableCards;

	void DealCards();
	void UpdatePhase();
	void UpdatePlayerPositions();

};

#endif /* CDEALER_H_ */
