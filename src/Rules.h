/*
 * cRules.h
 *
 *  Created on: Nov 13, 2017
 *      Author: Jonathan
 */

#ifndef CRULES_H_
#define CRULES_H_

#include <vector>

#include "Card.h"

class cRules {
public:
	cRules();
	virtual ~cRules();

	bool IsPlayerTheWinner();
	bool IsRoyalFlush(std::vector<cCard*> aHand);
	bool IsStraightFlush(std::vector<cCard*> aHand);
	bool IsBetLegal();

	std::vector<cCard*> mRoyalFlush;
	std::vector<cCard*> mStraightFlush;

	struct myCardCompare {
	  inline bool operator()(const cCard* i,const cCard* j)
	  {
		  return (i->mValue < j->mValue);
	  }
	}compare;

private:
	void InitializeWinningHands();


};

#endif /* CRULES_H_ */
