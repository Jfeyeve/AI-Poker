/*
 * RNG_Test.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: Jonathan
 */

#include "gtest/gtest.h"
#include "../src/Card.h"
#include "../src/Deck.h"
#include "../src/Game.h"
#include "../src/Player.h"
#include "../src/RNG.h"
#include "../src/SystemEnums.h"

class RNGTest : public ::testing::Test
{
	protected:
	virtual void SetUp()
	{

	}

	virtual void TearDown()
	{

	}

};

TEST_F(RNGTest, getRandom)
{
	uint8_t lRandomNumber = 52;
	cRNG randomNumber;
	uint8_t lrandom = randomNumber.getRandomNumber(lRandomNumber);

	ASSERT_TRUE( lrandom < 52);
}

TEST_F(RNGTest, testHighConstraint)
{
	uint8_t lRandomNumber = 3;
	cRNG randomNumber;
	uint8_t lrandom = randomNumber.getRandomNumber(lRandomNumber);

	ASSERT_TRUE( lrandom < 3);
}


