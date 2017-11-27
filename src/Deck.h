/*
 * cDeck.h
 *
 *  Created on: Nov 13, 2017
 *      Author: Jonathan
 */

#ifndef CDECK_H_
#define CDECK_H_

#include <vector>

#include "Card.h"
#include "RNG.h"

class cDeck {
public:
	cDeck();

	cRNG* mRandomNumberGenerator;

	void CreateDeck(std::vector<cCard>* aDeckOfCards);
	cCard DrawCard();
	bool Shuffle();

	cCard getCurrentCard();
	uint8_t getCurrentCardPointer();

	virtual ~cDeck();


private:
	std::vector<cCard>* mDeckOfCards;
	uint8_t mCurrentCardPointer;
	uint8_t const mNumberOfCards = 52;
	uint8_t const mNumberOfSuits = 4;
	uint8_t const mNumberOfCardsPerSuit = 13;
	uint8_t const mIndexOfFirstCardInDeck = 0;

	void SwapACard(std::vector<cCard>* aDeckOfCards);
	bool CompareCards(cCard aCard, cCard aCard2);
};

#endif /* CDECK_H_ */
