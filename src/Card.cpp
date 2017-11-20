/*
 * cCard.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: Jonathan
 */

#include "Card.h"

cCard::cCard(Suits aSuit, Cards aValue) {
	mSuit = aSuit;
	mValue = aValue;
}

cCard::~cCard() {
}

