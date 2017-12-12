/*
 * cDealer.h
 *
 *  Created on: Nov 13, 2017
 *      Author: Jonathan
 */

#ifndef CDEALER_H_
#define CDEALER_H_

#include <vector>

#include "Deck.h"
#include "Game.h"
#include "PlayerPosition.h"
#include "SystemEnums.h"

class cGame;

class cDealer {
public:
	cDealer();
	virtual ~cDealer();

	cDeck* mDeck;
	cPlayerPosition mPlayerPositionManager;

	std::vector<GamePhases> mGamePhases;
	GamePhases mCurrentGamePhase;
	std::vector<cCard>* mTableCards;

	uint8_t mFlopCard1;
	uint8_t mFlopCard2;
	uint8_t mFlopCard3;
	uint8_t mRiverCard;
	uint8_t mTurnCard;

	void UpdatePhase();
	void UpdatePlayerPositions();

	bool DealToPlayers(std::vector<cPlayer*> aPlayers, int aCardsPerPlayer);
	void BurnCard();
	bool DealFlop();
	bool DealRiver();
	bool DealTurn();

	std::vector<cCard>* GetTableCards();

private:
	bool DealToPlayer(cPlayer* aPlayer);
};

#endif /* CDEALER_H_ */
