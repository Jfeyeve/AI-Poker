/*
 * KuhnPoker.cpp
 *
 *  Created on: Dec 12, 2017
 *      Author: Jonathan
 */

#include <iostream>

#include "KuhnPoker.h"
#include "KuhnPlayer.h"
#include "Player.h"

KuhnPoker::KuhnPoker(PlayerStyles aPlayer1, PlayerStyles aPlayer2)
{

	mPlayer1 = new KuhnPlayer("Jon", aPlayer1, 100);
	mPlayer2 = new KuhnPlayer("Sam", aPlayer2, 100);

	mTotalPot = 0;

	mHistoryOfGame = new std::vector<std::string>;
	mGameCards = new std::vector<int>({1,2,3});

	mPlayer1Wins = 0;
	mPlayer2Wins = 0;

	mManualPlayerWinCount = 0;
	mAIJackWinCount = 0;
	mRandomPlayerWinCount = 0;
	mTAGPlayerWinCount = 0;
}

KuhnPoker::~KuhnPoker() {

}

void KuhnPoker::CollectAnte()
{
	mPlayer1->mChips = mPlayer1->mChips - 1;
	mPlayer2->mChips = mPlayer1->mChips - 1;

	mTotalPot += 2;
}

void KuhnPoker::DealToPlayer()
{
	int lTotalCards = 3;
	//Clear past hands
	mPlayer1->mHand->clear();
	mPlayer2->mHand->clear();

	//shuffle the deck of cards
	for(int card1 = mGameCards->size()-1; card1>0; card1--)
	{
		int card2 = mRandom->getRandomNumber(card1 +1);

		int lTemporaryCard = mGameCards->at(card1);
		mGameCards->at(card1) = mGameCards->at(card2);
		mGameCards->at(card2) = lTemporaryCard;
	}

	mPlayer1->mHand->push_back(mGameCards->at(0));
	mPlayer2->mHand->push_back(mGameCards->at(1));
}

Bets KuhnPoker::Player1BetPass()
{
	int lPlayerChoice = 0;
	std::cout<< "this is MY CARD: "<< mPlayer1->mHand->at(0)<<std::endl;
	std::cout<< "\nTo BET enter 3, to Pass enter 5 "<<std::endl;

	std::cin>>lPlayerChoice;

	return (Bets)lPlayerChoice;
}

Bets KuhnPoker::Player2BetPass()
{
	int lPlayerChoice = 0;
	std::cout<< "this is MY CARD: "<< mPlayer2->mHand->at(0)<<std::endl;
	std::cout<< "\nTo BET enter 3, to Pass enter 5 "<<std::endl;

	std::cin>>lPlayerChoice;

	return (Bets)lPlayerChoice;
}

void KuhnPoker::Showdown()
{
	if( mPlayer1->mHand->at(0)>mPlayer2->mHand->at(0))
	{
		mPlayer1Wins += 1;
		std::cout<< "The WINNER is "<< "Player 1\n"<<std::endl;
		std::cout<< "With "<< mPlayer1Wins<<" total wins!\n"<<std::endl;
		std::cout << "\nAnd wins a total Pot of "<< mTotalPot << std::endl;
	}
	else
	{
		mPlayer2Wins += 1;
		std::cout<< "The WINNER is "<< "Player 2\n"<<std::endl;
		std::cout<< "With "<< mPlayer2Wins<<" total wins!\n"<<std::endl;
		std::cout << "\nAnd wins a total Pot of "<< mTotalPot << std::endl;
	}

	mTotalPot = 0;
}


Bets KuhnPoker::Player1FoldCall()
{
	int lPlayerChoice = 0;
	std::cout<< "this is MY CARD: "<< mPlayer1->mHand->at(0)<<std::endl;
	std::cout<< "\nTo FOLD enter 0, to CALL enter 2 "<<std::endl;

	std::cin>>lPlayerChoice;

	return (Bets)lPlayerChoice;
}

Bets KuhnPoker::Player2FoldCall()
{
	int lPlayerChoice = 0;
	std::cout<< "this is MY CARD: "<< mPlayer2->mHand->at(0)<<std::endl;
	std::cout<< "\nTo FOLD enter 0, to CALL enter 2 "<<std::endl;

	std::cin>>lPlayerChoice;

	return (Bets)lPlayerChoice;
}

void KuhnPoker::MakeWinner(int aPlayer)
{
	aPlayer == 1 ? mPlayer1Wins +=1: mPlayer2Wins +=1;

	if(aPlayer == 1)
	{
		std::cout<< "The WINNER is "<< "Player 1\n"<<std::endl;
		std::cout<< "With "<< mPlayer1Wins<<" total wins!\n"<<std::endl;
		std::cout << "\nAnd wins a total Pot of "<< mTotalPot << std::endl;
	}
	else
	{
		mPlayer2Wins += 1;
		std::cout<< "The WINNER is "<< "Player 2\n"<<std::endl;
		std::cout<< "With "<< mPlayer2Wins<<" total wins!\n"<<std::endl;
		std::cout << "\nAnd wins a total Pot of "<< mTotalPot << std::endl;
	}

	mTotalPot = 0;
}

void KuhnPoker::RecordResults()
{

}
