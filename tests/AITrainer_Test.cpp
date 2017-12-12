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
#include "../src/AITrainer.h"

class AITrainerTest : public ::testing::Test
{
	protected:
	virtual void SetUp()
	{

	}

	virtual void TearDown()
	{

	}

};

TEST_F(AITrainerTest, trainAI)
{
	uint8_t lRandomNumber = 52;
	cRNG randomNumber;
	uint8_t lrandom = randomNumber.getRandomNumber(lRandomNumber);

	cAITrainer* lAgent = new cAITrainer(2, Kuhn);

	ASSERT_TRUE(false);
}

TEST_F(AITrainerTest, cfrAlgorithm)
{
	uint8_t lRandomNumber = 3;
	cRNG randomNumber;
	uint8_t lrandom = randomNumber.getRandomNumber(lRandomNumber);

	ASSERT_TRUE(false);
}


