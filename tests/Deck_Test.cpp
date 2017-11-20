/*
 * Card_Test.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: Jonathan
 */

#include "gtest/gtest.h"
#include "../src/Card.h"
#include "../src/Deck.h"
#include "../src/Game.h"
#include "../src/Player.h"
#include "../src/SystemEnums.h"

class DeckTest : public ::testing::Test
{
	protected:
	virtual void SetUp()
	{

	}

	virtual void TearDown()
	{

	}

};

TEST_F(DeckTest, createDesk)
{
	uint8_t lDeckSize = 52;
	cDeck* lDeck = new cDeck();
	std::vector<cCard> lDeckOfCards;

	lDeck->CreateDeck(&lDeckOfCards);

	//bool lActualValue = game->StartTheGame();

	ASSERT_TRUE(lDeckOfCards.size() == lDeckSize);
}


