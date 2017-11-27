/*
 * Counter_Tests.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: Jonathan
 */

#include "gtest/gtest.h"
#include "../src/Card.h"
#include "../src/Game.h"
#include "../src/Player.h"
#include "../src/SystemEnums.h"

class PlayerTest : public ::testing::Test
{
	protected:
	virtual void SetUp()
	{

	}

	virtual void TearDown()
	{

	}

};

TEST_F(PlayerTest, receiveCard)
{
	bool lActualValue = false;
	Suits lSuit = Spades;
	Cards lValue = Jack;
	Suits lSuit2 = Diamonds;
	Cards lValue2 = Queen;

	Suits lActualSuit1 = Clubs;
	Cards lActualValue1 = King;
	Suits lActualSuit2 = Hearts;
	Cards lActualValue2 = Nine;

	cPlayer* tPlayer1 = new cPlayer("Jon", Aggressive, 200);

	cCard* lCard = new cCard(lSuit, lValue);
	cCard* lCard2 = new cCard(lSuit2, lValue2);
	cCard* lActualCard1 = new cCard(lActualSuit1, lActualValue1);
	cCard* lActualCard2 = new cCard(lActualSuit2, lActualValue2);

	tPlayer1->receiveCard(*lCard);
	tPlayer1->receiveCard(*lCard2);

	lActualCard1 = &tPlayer1->mCards->at(FlopCard1);
	lActualCard2 = &tPlayer1->mCards->at(FlopCard2);

	ASSERT_TRUE(lActualCard1->mSuit == lCard->mSuit &&
				lActualCard1->mValue == lCard->mValue);

	ASSERT_TRUE(lActualCard2->mSuit == lCard2->mSuit &&
				lActualCard2->mValue == lCard2->mValue);
}
