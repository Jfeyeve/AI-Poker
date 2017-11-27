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

	ASSERT_TRUE(lCard.mSuit == lDeck->getCurrentCard().mSuit);
}

TEST_F(DeckTest, drawCard)
{
	cCard lCard(Spades, Two);
	cDeck* lDeck = new cDeck();
	std::vector<cCard> lDeckOfCards;

	lDeck->DrawCard();

	ASSERT_TRUE(lCard.mSuit == lDeck->getCurrentCard().mSuit ||
			lCard.mValue == lDeck->getCurrentCard().mValue);
}

TEST_F(DeckTest, shuffle)
{
	bool lSuccess = false;

	cCard lCard(Spades, Two);
	cDeck* lDeck = new cDeck();

	std::vector<cCard> lDeckOfCards;

	lSuccess = lDeck->Shuffle();

	ASSERT_TRUE(lSuccess == true);
}

TEST_F(DeckTest, shuffleResetCurrentCardPointer)
{
	uint8_t lExpectedCardPointerValue = 0;

	cCard lCard(Spades, Two);
	cDeck* lDeck = new cDeck();

	lDeck->Shuffle();

	ASSERT_TRUE(lExpectedCardPointerValue == lDeck->getCurrentCardPointer());
}
