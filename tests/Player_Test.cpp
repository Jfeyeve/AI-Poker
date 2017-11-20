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

	cPlayer* tPlayer1 = new cPlayer("Jon", Aggressive, 200);

	cCard* lCard = new cCard(lSuit, lValue);
	cCard* lCard2 = new cCard(lSuit2, lValue2);

	tPlayer1->receiveCard(*lCard);
	lActualValue = tPlayer1->receiveCard(*lCard2);

	ASSERT_TRUE(lActualValue == true);
}
