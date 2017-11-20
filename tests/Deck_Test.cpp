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

	ASSERT_TRUE(lDeckOfCards.size() == lDeckSize);
}

TEST_F(DeckTest, getCurrentCard)
{
	cCard lCard(Spades, Ace);
	cDeck* lDeck = new cDeck();
	std::vector<cCard> lDeckOfCards;

	lDeck->CreateDeck(lDeck->mDeckOfCards);

	ASSERT_TRUE(lCard.mSuit == lDeck->getCurrentCard().mSuit);
}

TEST_F(DeckTest, drawCard)
{
	cCard lCard(Spades, Two);
	cDeck* lDeck = new cDeck();
	std::vector<cCard> lDeckOfCards;

	lDeck->CreateDeck(lDeck->mDeckOfCards);
	lDeck->DrawCard();

	ASSERT_TRUE(lCard.mSuit == lDeck->getCurrentCard().mSuit);
}


