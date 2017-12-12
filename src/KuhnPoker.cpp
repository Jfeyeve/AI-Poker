/*
 * KuhnPoker.cpp
 *
 *  Created on: Dec 12, 2017
 *      Author: Jonathan
 */

#include <iostream>

#include "KuhnPoker.h"
#include "Player.h"

KuhnPoker::KuhnPoker(PlayerStyles aPlayer1, PlayerStyles aPlayer2) {

	std::cout << "Player style "<< aPlayer1 << " for Player 1"<< std::endl;
	std::cout << "Player style "<< aPlayer2 << " for Player 2"<< std::endl;
	mPlayer1 = new cPlayer("Jon", aPlayer1, 100);
	mPlayer2 = new cPlayer("Sam", aPlayer2, 100);

	mTotalPot = 0;

	mHistoryOfGame = new std::vector<std::string>;
}

KuhnPoker::~KuhnPoker() {
	// TODO Auto-generated destructor stub
}

void KuhnPoker::CollectAnte()
{
	mPlayer1->mChips = mPlayer1->mChips - 1;
	mPlayer2->mChips = mPlayer1->mChips - 1;

	mTotalPot += 2;
}

void KuhnPoker::DealToPlayer()
{

}

Bets KuhnPoker::Player1BetPass()
{
	Bets lLocal = Fold;
	return lLocal;
}

Bets KuhnPoker::Player2BetPass()
{
	Bets lLocal = Fold;
	return lLocal;
}

GameWinner KuhnPoker::Showdown()
{
	GameWinner lLocal = ManualPlayer;

	return lLocal;
}


Bets KuhnPoker::Player1FoldCall()
{
	Bets lLocal = Fold;
	return lLocal;
}

Bets KuhnPoker::Player2FoldCall()
{
	Bets lLocal = Fold;
	return lLocal;
}

void KuhnPoker::RecordResults()
{

}
