/*
 * Counter_Tests.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: Jonathan
 */

#include "gtest/gtest.h"
#include "../src/Card.h"
#include "../src/cGame.h"
#include "../src/cPlayer.h"
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

	cPlayer* tPlayer1 = new cPlayer("Jon", Aggressive, 200);

	cCard* lCard = new cCard("Spades", 11);
	cCard* lCard2 = new cCard("Diamonds", 10);

	tPlayer1->receiveCard(*lCard);
	lActualValue = tPlayer1->receiveCard(*lCard2);

	ASSERT_TRUE(lActualValue == true);
}
