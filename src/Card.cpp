/*
 * cCard.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: Jonathan
 */

#include "Card.h"

cCard::cCard(std::string aSuit, uint8_t aValue) {
	mSuit = aSuit;
	mValue = aValue;
}

cCard::~cCard() {
	// TODO Auto-generated destructor stub
}

