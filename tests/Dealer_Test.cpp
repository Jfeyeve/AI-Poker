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
#include "../src/SystemEnums.h"

class DealerTest : public ::testing::Test
{
	protected:
	virtual void SetUp()
	{

	}

	virtual void TearDown()
	{

	}

};

TEST_F(DealerTest, burnCard)
{
	cDealer* lDealer = new cDealer();

	cCard lCard(Spades, Two);
	cCard lCard2(Spades, Three);
	cDeck* lDeck = new cDeck();

	uint8_t lCardPointerBeforeBurn = 0;
	uint8_t lCardPointerAfterBurn = 0;

	std::vector<cCard> lDeckOfCards;

	lCard = lDealer->mDeck->getCurrentCard();
	lCardPointerBeforeBurn = lDealer->mDeck->getCurrentCardPointer();
	lDealer->BurnCard();
	lCardPointerAfterBurn = lDealer->mDeck->getCurrentCardPointer();
	lCard2 = lDealer->mDeck->getCurrentCard();

	ASSERT_TRUE(lCard2.mSuit == Spades &&
			lCard2.mValue == Two);
}

TEST_F(DealerTest, dealToPlayer)
{
	cDealer* lDealer = new cDealer();

	cCard lExpectedCard1(Spades, Ace);
	cCard lExpectedCard2(Spades, Two);
	cCard lExpectedCard3(Spades, Three);

	Suits lActualSuit1 = Clubs;
	Cards lActualValue1 = King;
	Suits lActualSuit2 = Hearts;
	Cards lActualValue2 = Nine;
	Suits lActualSuit3 = Hearts;
	Cards lActualValue3 = Jack;

	cPlayer* tPlayer1 = new cPlayer("Jon", Aggressive, 200);

	cCard* lActualCard1 = new cCard(lActualSuit1, lActualValue1);
	cCard* lActualCard2 = new cCard(lActualSuit2, lActualValue2);
	cCard* lActualCard3 = new cCard(lActualSuit3, lActualValue3);

	lDealer->DealToPlayer(tPlayer1);

	lActualCard1 = &tPlayer1->mCards->at(FlopCard1);
	lActualCard2 = &tPlayer1->mCards->at(FlopCard2);
	lActualCard3 = &tPlayer1->mCards->at(FlopCard3);

	ASSERT_TRUE(lActualCard1->mSuit == lExpectedCard1.mSuit &&
				lActualCard1->mValue == lExpectedCard1.mValue);

	ASSERT_TRUE(lActualCard2->mSuit == lExpectedCard2.mSuit &&
				lActualCard2->mValue == lExpectedCard2.mValue);

	ASSERT_TRUE(lActualCard3->mSuit == lExpectedCard3.mSuit &&
				lActualCard3->mValue == lExpectedCard3.mValue);
}

TEST_F(DealerTest, dealFlop)
{
	cDealer* lDealer = new cDealer();
	std::vector<cCard>* lTableCards;

	cCard lExpectedCard1(Spades, Two);
	cCard lExpectedCard2(Spades, Three);
	cCard lExpectedCard3(Spades, Four);

	Suits lActualSuit1 = Clubs;
	Cards lActualValue1 = King;
	Suits lActualSuit2 = Hearts;
	Cards lActualValue2 = Nine;
	Suits lActualSuit3 = Hearts;
	Cards lActualValue3 = Jack;

	cPlayer* tPlayer1 = new cPlayer("Jon", Aggressive, 200);

	cCard* lActualCard1 = new cCard(lActualSuit1, lActualValue1);
	cCard* lActualCard2 = new cCard(lActualSuit2, lActualValue2);
	cCard* lActualCard3 = new cCard(lActualSuit3, lActualValue3);

	lDealer->DealFlop();

	lTableCards = lDealer->GetTableCards();

	lActualCard1 = &lTableCards->at(FlopCard1);
	lActualCard2 = &lTableCards->at(FlopCard2);
	lActualCard3 = &lTableCards->at(FlopCard3);

	ASSERT_TRUE(lActualCard1->mSuit == lExpectedCard1.mSuit &&
				lActualCard1->mValue == lExpectedCard1.mValue);

	ASSERT_TRUE(lActualCard2->mSuit == lExpectedCard2.mSuit &&
				lActualCard2->mValue == lExpectedCard2.mValue);

	ASSERT_TRUE(lActualCard3->mSuit == lExpectedCard3.mSuit &&
				lActualCard3->mValue == lExpectedCard3.mValue);
}

TEST_F(DealerTest, dealTurn)
{
	cDealer* lDealer = new cDealer();
	std::vector<cCard>* lTableCards;

	cCard lExpectedCard1(Spades, Two);
	cCard lExpectedCard2(Spades, Three);
	cCard lExpectedCard3(Spades, Four);
	cCard lExpectedCard4(Spades, Six);

	Suits lActualSuit1 = Clubs;
	Cards lActualValue1 = King;
	Suits lActualSuit2 = Hearts;
	Cards lActualValue2 = Nine;
	Suits lActualSuit3 = Hearts;
	Cards lActualValue3 = Jack;
	Suits lActualSuit4 = Hearts;
	Cards lActualValue4 = Jack;

	cPlayer* tPlayer1 = new cPlayer("Jon", Aggressive, 200);

	cCard* lActualCard1 = new cCard(lActualSuit1, lActualValue1);
	cCard* lActualCard2 = new cCard(lActualSuit2, lActualValue2);
	cCard* lActualCard3 = new cCard(lActualSuit3, lActualValue3);
	cCard* lActualCard4 = new cCard(lActualSuit4, lActualValue4);

	lDealer->DealFlop();
	lDealer->DealTurn();

	lTableCards = lDealer->GetTableCards();

	lActualCard1 = &lTableCards->at(FlopCard1);
	lActualCard2 = &lTableCards->at(FlopCard2);
	lActualCard3 = &lTableCards->at(FlopCard3);
	lActualCard4 = &lTableCards->at(TurnCard4);

	ASSERT_TRUE(lActualCard1->mSuit == lExpectedCard1.mSuit &&
				lActualCard1->mValue == lExpectedCard1.mValue);

	ASSERT_TRUE(lActualCard2->mSuit == lExpectedCard2.mSuit &&
				lActualCard2->mValue == lExpectedCard2.mValue);

	ASSERT_TRUE(lActualCard3->mSuit == lExpectedCard3.mSuit &&
				lActualCard3->mValue == lExpectedCard3.mValue);

	ASSERT_TRUE(lActualCard4->mSuit == lExpectedCard4.mSuit &&
				lActualCard4->mValue == lExpectedCard4.mValue);
}

TEST_F(DealerTest, dealRiver)
{
	cDealer* lDealer = new cDealer();
	std::vector<cCard>* lTableCards;

	cCard lExpectedCard1(Spades, Two);
	cCard lExpectedCard2(Spades, Three);
	cCard lExpectedCard3(Spades, Four);
	cCard lExpectedCard4(Spades, Six);
	cCard lExpectedCard5(Spades, Eight);

	Suits lActualSuit1 = Clubs;
	Cards lActualValue1 = King;
	Suits lActualSuit2 = Hearts;
	Cards lActualValue2 = Nine;
	Suits lActualSuit3 = Hearts;
	Cards lActualValue3 = Jack;
	Suits lActualSuit4 = Hearts;
	Cards lActualValue4 = Jack;
	Suits lActualSuit5 = Hearts;
	Cards lActualValue5 = Jack;

	cPlayer* tPlayer1 = new cPlayer("Jon", Aggressive, 200);

	cCard* lActualCard1 = new cCard(lActualSuit1, lActualValue1);
	cCard* lActualCard2 = new cCard(lActualSuit2, lActualValue2);
	cCard* lActualCard3 = new cCard(lActualSuit3, lActualValue3);
	cCard* lActualCard4 = new cCard(lActualSuit4, lActualValue4);
	cCard* lActualCard5 = new cCard(lActualSuit5, lActualValue5);

	lDealer->DealFlop();
	lDealer->DealTurn();
	lDealer->DealRiver();

	lTableCards = lDealer->GetTableCards();

	lActualCard1 = &lTableCards->at(FlopCard1);
	lActualCard2 = &lTableCards->at(FlopCard2);
	lActualCard3 = &lTableCards->at(FlopCard3);
	lActualCard4 = &lTableCards->at(TurnCard4);
	lActualCard5 = &lTableCards->at(RiverCard5);

	ASSERT_TRUE(lActualCard1->mSuit == lExpectedCard1.mSuit &&
				lActualCard1->mValue == lExpectedCard1.mValue);

	ASSERT_TRUE(lActualCard2->mSuit == lExpectedCard2.mSuit &&
				lActualCard2->mValue == lExpectedCard2.mValue);

	ASSERT_TRUE(lActualCard3->mSuit == lExpectedCard3.mSuit &&
				lActualCard3->mValue == lExpectedCard3.mValue);

	ASSERT_TRUE(lActualCard4->mSuit == lExpectedCard4.mSuit &&
				lActualCard4->mValue == lExpectedCard4.mValue);

	ASSERT_TRUE(lActualCard5->mSuit == lExpectedCard5.mSuit &&
				lActualCard5->mValue == lExpectedCard5.mValue);
}
