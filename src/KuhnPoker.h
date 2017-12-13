/*
 * KuhnPoker.h
 *
 *  Created on: Dec 12, 2017
 *      Author: Jonathan
 */

#ifndef KUHNPOKER_H_
#define KUHNPOKER_H_

#include "Player.h"
#include "RNG.h"
#include "SystemEnums.h"

class KuhnPoker {
public:
	KuhnPoker(PlayerStyles aPlayer1, PlayerStyles aPlayer2);
	virtual ~KuhnPoker();

	int mPlayer1Wins;
	int mPlayer2Wins;

	//Each Player Antes 1
	void CollectAnte();

	//Each player is dealt one of the three cards, and the third is put aside unseen.
	void DealToPlayer();

	//Player one can check or bet 1.
	Bets Player1BetPass();
	//If player one checks then player two can check or bet 1.
	Bets Player2BetPass();
	//If player two checks there is a showdown for the pot of 2 (i.e. the higher card wins 1 from the other player).
	void Showdown();
	//If player two bets then player one can fold or call.
	Bets Player1FoldCall();
	//If player one bets then player two can fold or call.
	Bets Player2FoldCall();

	void MakeWinner(int aPlayer);

	void RecordResults();

	cPlayer* mPlayer1;
	cPlayer* mPlayer2;

	int mTotalPot;
	std::vector<std::string>* mHistoryOfGame;

	cRNG* mRandom = new cRNG();
	std::vector<int>* mGameCards;
	std::vector<int>* mBetOrPass;
	std::vector<int>* mFoldOrCall;

	int mManualPlayerWinCount;
	int mAIJackWinCount;
	int mRandomPlayerWinCount;
	int mTAGPlayerWinCount;
};

#endif /* KUHNPOKER_H_ */
