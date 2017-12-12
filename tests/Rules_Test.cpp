/*
 * Counter_Tests.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: Jonathan
 */

#include "gtest/gtest.h"
#include "../src/Card.h"
#include "../src/Dealer.h"
#include "../src/Game.h"
#include "../src/Player.h"
#include "../src/Rules.h"
#include "../src/SystemEnums.h"

class RulesTest : public ::testing::Test
{
	protected:
	virtual void SetUp()
	{

	}

	virtual void TearDown()
	{

	}

};

TEST_F(RulesTest, IsRoyalFlush)
{
	std::vector<cCard*> lAHandOfCards;

	cCard lExpectedCard1(Spades, Ace);
	cCard lExpectedCard2(Spades, King);
	cCard lExpectedCard3(Spades, Queen);
	cCard lExpectedCard4(Spades, Jack);
	cCard lExpectedCard5(Spades, Ten);

	lAHandOfCards.push_back(&lExpectedCard1);
	lAHandOfCards.push_back(&lExpectedCard2);
	lAHandOfCards.push_back(&lExpectedCard3);
	lAHandOfCards.push_back(&lExpectedCard4);
	lAHandOfCards.push_back(&lExpectedCard5);

	cRules* lRules = new cRules();
	bool lExpectedValue = false;

	lExpectedValue = lRules->IsRoyalFlush(lAHandOfCards);
	ASSERT_TRUE(lExpectedValue);
}

TEST_F(RulesTest, IsRoyalFlushFail)
{
	std::vector<cCard*> lAHandOfCards;

	cCard lExpectedCard1(Spades, Ace);
	cCard lExpectedCard2(Spades, King);
	cCard lExpectedCard3(Spades, Queen);
	cCard lExpectedCard4(Spades, Jack);
	cCard lExpectedCard5(Spades, Four);

	lAHandOfCards.push_back(&lExpectedCard1);
	lAHandOfCards.push_back(&lExpectedCard3);
	lAHandOfCards.push_back(&lExpectedCard2);
	lAHandOfCards.push_back(&lExpectedCard4);
	lAHandOfCards.push_back(&lExpectedCard5);

	cRules* lRules = new cRules();
	bool lExpectedValue = false;

	lExpectedValue = lRules->IsRoyalFlush(lAHandOfCards);
	ASSERT_FALSE(lExpectedValue);
}

TEST_F(RulesTest, IsStraightFlush)
{
	std::vector<cCard*> lAHandOfCards;

	cCard lExpectedCard1(Spades, Two);
	cCard lExpectedCard2(Spades, Three);
	cCard lExpectedCard3(Spades, Four);
	cCard lExpectedCard4(Spades, Six);
	cCard lExpectedCard5(Spades, Five);

	lAHandOfCards.push_back(&lExpectedCard1);
	lAHandOfCards.push_back(&lExpectedCard2);
	lAHandOfCards.push_back(&lExpectedCard3);
	lAHandOfCards.push_back(&lExpectedCard4);
	lAHandOfCards.push_back(&lExpectedCard5);

	cRules* lRules = new cRules();
	bool lExpectedValue = false;

	lExpectedValue = lRules->IsStraightFlush(lAHandOfCards);
	ASSERT_TRUE(lExpectedValue);
}

TEST_F(RulesTest, IsStraightFlushFail)
{
	std::vector<cCard*> lAHandOfCards;

	cCard lExpectedCard1(Spades, Two);
	cCard lExpectedCard2(Spades, Three);
	cCard lExpectedCard3(Spades, Four);
	cCard lExpectedCard4(Spades, Six);
	cCard lExpectedCard5(Spades, Eight);

	lAHandOfCards.push_back(&lExpectedCard1);
	lAHandOfCards.push_back(&lExpectedCard2);
	lAHandOfCards.push_back(&lExpectedCard3);
	lAHandOfCards.push_back(&lExpectedCard4);
	lAHandOfCards.push_back(&lExpectedCard5);

	cRules* lRules = new cRules();
	bool lExpectedValue = false;

	lExpectedValue = lRules->IsStraightFlush(lAHandOfCards);
	ASSERT_FALSE(lExpectedValue);
}

TEST_F(RulesTest, IsFourOfAKind)
{
	cDealer* lDealer = new cDealer();
	std::vector<cCard*> lAHandOfCards;

	cCard lExpectedCard1(Spades, Ace);
	cCard lExpectedCard2(Spades, King);
	cCard lExpectedCard3(Spades, Queen);
	cCard lExpectedCard4(Spades, Jack);
	cCard lExpectedCard5(Spades, Ten);

	lAHandOfCards.push_back(&lExpectedCard1);
	lAHandOfCards.push_back(&lExpectedCard2);
	lAHandOfCards.push_back(&lExpectedCard3);
	lAHandOfCards.push_back(&lExpectedCard4);
	lAHandOfCards.push_back(&lExpectedCard5);

//	cCard lExpectedCard1(Spades, Two);
//	cCard lExpectedCard2(Spades, Three);
//	cCard lExpectedCard3(Spades, Four);
//	cCard lExpectedCard4(Spades, Six);
//	cCard lExpectedCard5(Spades, Eight);
//
//	cCard lExpectedCard1(Spades, Two);
//	cCard lExpectedCard2(Spades, Three);
//	cCard lExpectedCard3(Spades, Four);
//	cCard lExpectedCard4(Spades, Six);
//	cCard lExpectedCard5(Spades, Eight);

	cRules* lRules = new cRules();
	bool lExpectedValue = false;

//	lExpectedValue = lRules->IsRoyalFlush(lAHandOfCards);
	ASSERT_TRUE(lExpectedValue);
}

TEST_F(RulesTest, IsFullHouse)
{
	cDealer* lDealer = new cDealer();
	std::vector<cCard*> lAHandOfCards;

	cCard lExpectedCard1(Spades, Ace);
	cCard lExpectedCard2(Spades, King);
	cCard lExpectedCard3(Spades, Queen);
	cCard lExpectedCard4(Spades, Jack);
	cCard lExpectedCard5(Spades, Ten);

	lAHandOfCards.push_back(&lExpectedCard1);
	lAHandOfCards.push_back(&lExpectedCard2);
	lAHandOfCards.push_back(&lExpectedCard3);
	lAHandOfCards.push_back(&lExpectedCard4);
	lAHandOfCards.push_back(&lExpectedCard5);

//	cCard lExpectedCard1(Spades, Two);
//	cCard lExpectedCard2(Spades, Three);
//	cCard lExpectedCard3(Spades, Four);
//	cCard lExpectedCard4(Spades, Six);
//	cCard lExpectedCard5(Spades, Eight);
//
//	cCard lExpectedCard1(Spades, Two);
//	cCard lExpectedCard2(Spades, Three);
//	cCard lExpectedCard3(Spades, Four);
//	cCard lExpectedCard4(Spades, Six);
//	cCard lExpectedCard5(Spades, Eight);

	cRules* lRules = new cRules();
	bool lExpectedValue = false;

//	lExpectedValue = lRules->IsRoyalFlush(lAHandOfCards);
	ASSERT_TRUE(lExpectedValue);
}

TEST_F(RulesTest, IsFlush)
{
	cDealer* lDealer = new cDealer();
	std::vector<cCard*> lAHandOfCards;

	cCard lExpectedCard1(Spades, Ace);
	cCard lExpectedCard2(Spades, King);
	cCard lExpectedCard3(Spades, Queen);
	cCard lExpectedCard4(Spades, Jack);
	cCard lExpectedCard5(Spades, Ten);

	lAHandOfCards.push_back(&lExpectedCard1);
	lAHandOfCards.push_back(&lExpectedCard2);
	lAHandOfCards.push_back(&lExpectedCard3);
	lAHandOfCards.push_back(&lExpectedCard4);
	lAHandOfCards.push_back(&lExpectedCard5);

//	cCard lExpectedCard1(Spades, Two);
//	cCard lExpectedCard2(Spades, Three);
//	cCard lExpectedCard3(Spades, Four);
//	cCard lExpectedCard4(Spades, Six);
//	cCard lExpectedCard5(Spades, Eight);
//
//	cCard lExpectedCard1(Spades, Two);
//	cCard lExpectedCard2(Spades, Three);
//	cCard lExpectedCard3(Spades, Four);
//	cCard lExpectedCard4(Spades, Six);
//	cCard lExpectedCard5(Spades, Eight);

	cRules* lRules = new cRules();
	bool lExpectedValue = false;

//	lExpectedValue = lRules->IsRoyalFlush(lAHandOfCards);
	ASSERT_TRUE(lExpectedValue);
}

TEST_F(RulesTest, IsStraight)
{
	cDealer* lDealer = new cDealer();
	std::vector<cCard*> lAHandOfCards;

	cCard lExpectedCard1(Spades, Ace);
	cCard lExpectedCard2(Spades, King);
	cCard lExpectedCard3(Spades, Queen);
	cCard lExpectedCard4(Spades, Jack);
	cCard lExpectedCard5(Spades, Ten);

	lAHandOfCards.push_back(&lExpectedCard1);
	lAHandOfCards.push_back(&lExpectedCard2);
	lAHandOfCards.push_back(&lExpectedCard3);
	lAHandOfCards.push_back(&lExpectedCard4);
	lAHandOfCards.push_back(&lExpectedCard5);

//	cCard lExpectedCard1(Spades, Two);
//	cCard lExpectedCard2(Spades, Three);
//	cCard lExpectedCard3(Spades, Four);
//	cCard lExpectedCard4(Spades, Six);
//	cCard lExpectedCard5(Spades, Eight);
//
//	cCard lExpectedCard1(Spades, Two);
//	cCard lExpectedCard2(Spades, Three);
//	cCard lExpectedCard3(Spades, Four);
//	cCard lExpectedCard4(Spades, Six);
//	cCard lExpectedCard5(Spades, Eight);

	cRules* lRules = new cRules();
	bool lExpectedValue = false;

//	lExpectedValue = lRules->IsRoyalFlush(lAHandOfCards);
	ASSERT_TRUE(lExpectedValue);
}

TEST_F(RulesTest, IsThreeOfAKind)
{
	cDealer* lDealer = new cDealer();
	std::vector<cCard*> lAHandOfCards;

	cCard lExpectedCard1(Spades, Ace);
	cCard lExpectedCard2(Spades, King);
	cCard lExpectedCard3(Spades, Queen);
	cCard lExpectedCard4(Spades, Jack);
	cCard lExpectedCard5(Spades, Ten);

	lAHandOfCards.push_back(&lExpectedCard1);
	lAHandOfCards.push_back(&lExpectedCard2);
	lAHandOfCards.push_back(&lExpectedCard3);
	lAHandOfCards.push_back(&lExpectedCard4);
	lAHandOfCards.push_back(&lExpectedCard5);

//	cCard lExpectedCard1(Spades, Two);
//	cCard lExpectedCard2(Spades, Three);
//	cCard lExpectedCard3(Spades, Four);
//	cCard lExpectedCard4(Spades, Six);
//	cCard lExpectedCard5(Spades, Eight);
//
//	cCard lExpectedCard1(Spades, Two);
//	cCard lExpectedCard2(Spades, Three);
//	cCard lExpectedCard3(Spades, Four);
//	cCard lExpectedCard4(Spades, Six);
//	cCard lExpectedCard5(Spades, Eight);

	cRules* lRules = new cRules();
	bool lExpectedValue = false;

//	lExpectedValue = lRules->IsRoyalFlush(lAHandOfCards);
	ASSERT_TRUE(lExpectedValue);
}

TEST_F(RulesTest, IsTwoPair)
{
	cDealer* lDealer = new cDealer();
	std::vector<cCard*> lAHandOfCards;

	cCard lExpectedCard1(Spades, Ace);
	cCard lExpectedCard2(Spades, King);
	cCard lExpectedCard3(Spades, Queen);
	cCard lExpectedCard4(Spades, Jack);
	cCard lExpectedCard5(Spades, Ten);

	lAHandOfCards.push_back(&lExpectedCard1);
	lAHandOfCards.push_back(&lExpectedCard2);
	lAHandOfCards.push_back(&lExpectedCard3);
	lAHandOfCards.push_back(&lExpectedCard4);
	lAHandOfCards.push_back(&lExpectedCard5);

//	cCard lExpectedCard1(Spades, Two);
//	cCard lExpectedCard2(Spades, Three);
//	cCard lExpectedCard3(Spades, Four);
//	cCard lExpectedCard4(Spades, Six);
//	cCard lExpectedCard5(Spades, Eight);
//
//	cCard lExpectedCard1(Spades, Two);
//	cCard lExpectedCard2(Spades, Three);
//	cCard lExpectedCard3(Spades, Four);
//	cCard lExpectedCard4(Spades, Six);
//	cCard lExpectedCard5(Spades, Eight);

	cRules* lRules = new cRules();
	bool lExpectedValue = false;

//	lExpectedValue = lRules->IsRoyalFlush(lAHandOfCards);
	ASSERT_TRUE(lExpectedValue);
}

TEST_F(RulesTest, IsPair)
{
	cDealer* lDealer = new cDealer();
	std::vector<cCard*> lAHandOfCards;

	cCard lExpectedCard1(Spades, Ace);
	cCard lExpectedCard2(Spades, King);
	cCard lExpectedCard3(Spades, Queen);
	cCard lExpectedCard4(Spades, Jack);
	cCard lExpectedCard5(Spades, Ten);

	lAHandOfCards.push_back(&lExpectedCard1);
	lAHandOfCards.push_back(&lExpectedCard2);
	lAHandOfCards.push_back(&lExpectedCard3);
	lAHandOfCards.push_back(&lExpectedCard4);
	lAHandOfCards.push_back(&lExpectedCard5);

//	cCard lExpectedCard1(Spades, Two);
//	cCard lExpectedCard2(Spades, Three);
//	cCard lExpectedCard3(Spades, Four);
//	cCard lExpectedCard4(Spades, Six);
//	cCard lExpectedCard5(Spades, Eight);
//
//	cCard lExpectedCard1(Spades, Two);
//	cCard lExpectedCard2(Spades, Three);
//	cCard lExpectedCard3(Spades, Four);
//	cCard lExpectedCard4(Spades, Six);
//	cCard lExpectedCard5(Spades, Eight);

	cRules* lRules = new cRules();
	bool lExpectedValue = false;

//	lExpectedValue = lRules->IsRoyalFlush(lAHandOfCards);
	ASSERT_TRUE(lExpectedValue);
}

TEST_F(RulesTest, IsHighCard)
{
	cDealer* lDealer = new cDealer();
	std::vector<cCard*> lAHandOfCards;

	cCard lExpectedCard1(Spades, Ace);
	cCard lExpectedCard2(Spades, King);
	cCard lExpectedCard3(Spades, Queen);
	cCard lExpectedCard4(Spades, Jack);
	cCard lExpectedCard5(Spades, Ten);

	lAHandOfCards.push_back(&lExpectedCard1);
	lAHandOfCards.push_back(&lExpectedCard2);
	lAHandOfCards.push_back(&lExpectedCard3);
	lAHandOfCards.push_back(&lExpectedCard4);
	lAHandOfCards.push_back(&lExpectedCard5);

//	cCard lExpectedCard1(Spades, Two);
//	cCard lExpectedCard2(Spades, Three);
//	cCard lExpectedCard3(Spades, Four);
//	cCard lExpectedCard4(Spades, Six);
//	cCard lExpectedCard5(Spades, Eight);
//
//	cCard lExpectedCard1(Spades, Two);
//	cCard lExpectedCard2(Spades, Three);
//	cCard lExpectedCard3(Spades, Four);
//	cCard lExpectedCard4(Spades, Six);
//	cCard lExpectedCard5(Spades, Eight);

	cRules* lRules = new cRules();
	bool lExpectedValue = false;

//	lExpectedValue = lRules->IsRoyalFlush(lAHandOfCards);
	ASSERT_TRUE(lExpectedValue);
}
