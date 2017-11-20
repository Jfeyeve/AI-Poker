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
	cRNG randomNumber;
	uint8_t lrandom = randomNumber.getRandomNumber();

	ASSERT_TRUE( lrandom < 52);
}


