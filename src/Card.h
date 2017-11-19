/*
 * cCard.h
 *
 *  Created on: Nov 19, 2017
 *      Author: Jonathan
 */

#ifndef CCARD_H_
#define CCARD_H_

#include <string>

class cCard {
public:
	cCard(std::string aSuit, uint8_t aValue);
	virtual ~cCard();

	std::string mSuit;
	uint8_t mValue;
};

#endif /* CCARD_H_ */
