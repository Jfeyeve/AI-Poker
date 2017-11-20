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

class cDeck {
public:
	cDeck();

	void CreateDeck(std::vector<cCard>* aDeckOfCards);
	void DrawCard();
	void Shuffle( cDeck* aDeck );

	void Deal();
	void BurnCard();
	void River();
	void Turn();

	virtual ~cDeck();

private:
	std::vector<cCard>* mDeckOfCards;
	uint8_t mCurrentCardPointer;
};

#endif /* CDECK_H_ */
