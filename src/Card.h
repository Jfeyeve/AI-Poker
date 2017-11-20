/*
 * cCard.h
 *
 *  Created on: Nov 19, 2017
 *      Author: Jonathan
 */

#ifndef CCARD_H_
#define CCARD_H_

#include <string>

#include "SystemEnums.h"

class cCard {
public:
	cCard(Suits aSuit, Cards aValue);
	virtual ~cCard();

	Suits mSuit;
	Cards mValue;
};

#endif /* CCARD_H_ */
