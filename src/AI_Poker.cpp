//============================================================================
// Name        : AI.cpp
// Author      : Jonathan Velez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <iostream>
#include <vector>

#include "AITrainer.h"
#include "Dealer.h"
#include "Game.h"
#include "KuhnPoker.h"
#include "RNG.h"
#include "SystemEnums.h"

using namespace std;

int main() {

	cAITrainer* lAgent = new cAITrainer(2, Kuhn);

	int lRoundsToPlay = 3;

	int lPlayer1Type = 0;
	int lPlayer2Type = 0;

	std::cout << "Select Player 1: Enter 1 = Manual, 2 = AIJack, 3 = Random, 4 = TAGPlayer\n"<< std::endl;
	std::cin >> lPlayer1Type;
	std::cout << "You selected "<< lPlayer1Type << " for Player 1\n"<< std::endl;
	std::cout << "Select Player 2: Enter 1 = Manual, 2 = AIJack, 3 = Random, 4 = TAGPlayer\n"<< std::endl;
	std::cin >> lPlayer2Type;
	std::cout << "You selected "<< lPlayer2Type << " for Player 2\n"<< std::endl;

//	if( (PlayerStyles)lPlayer1Type == Manual)
//	{
//		std::cout<< "We are Manual"<<std::endl;
//	}


	KuhnPoker* lKuhnGame = new 	KuhnPoker((PlayerStyles)lPlayer1Type, (PlayerStyles)lPlayer2Type);

	for( int i = 0; i < lRoundsToPlay; i++)
	{
		//Each Player Antes 1
		lKuhnGame->CollectAnte();
//		std::cout << "Player has "<< lKuhnGame->mPlayer1->mChips << std::endl;
//		std::cout << "The Pot is  "<< lKuhnGame->mTotalPot << std::endl;

		//Each player is dealt one of the three cards, and the third is put aside unseen.
		lKuhnGame->DealToPlayer();

		//Player one can check or bet 1.
		Bets lPlayer1DecisionRound1 = lKuhnGame->Player1BetPass();

		//If player one checks then player two can check or bet 1.
		Bets lPlayer2DecisionRound1 = lKuhnGame->Player2BetPass();

		//If player two checks there is a showdown for the pot of 2 (i.e. the higher card wins 1 from the other player).
		if( lPlayer1DecisionRound1 == Pass && lPlayer2DecisionRound1 == Pass)
		{
			std::cout << "IN THE SHOWDOWN"<< std::endl;

			lKuhnGame->Showdown();
		}

		Bets lPlayer1DecisionRound2 = Pass;

		//If player two bets then player one can fold or call.
		if( lPlayer1DecisionRound1 == Pass && lPlayer2DecisionRound1 == Bet)
		{
			std::cout << "PLAYER ONE, FOLD OR CALL"<< std::endl;
			lPlayer1DecisionRound2 = lKuhnGame->Player1FoldCall();
		}

		//If player one folds then player two takes the pot of 3 (i.e. winning 1 from player 1).
		if( lPlayer1DecisionRound2 == Fold)
		{
			std::cout << "PLAYER ONE FOLDS!!!!"<< std::endl;
			lKuhnGame->MakeWinner(2);
		}

		//If player one calls there is a showdown for the pot of 4 (i.e. the higher card wins 2 from the other player).
		if( lPlayer1DecisionRound2 == Call)
		{
			std::cout << "IN THE SHOWDOWN"<< std::endl;

			lKuhnGame->Showdown();
		}

		Bets lPlayer2DecisionRound2 = Pass;

		//If player one bets then player two can fold or call.
		if( lPlayer1DecisionRound2 == Bet)
		{
			std::cout << "PLAYER TWO, FOLD OR CALL"<< std::endl;
			lPlayer2DecisionRound2 = lKuhnGame->Player2FoldCall();
		}

		//If player two folds then player one takes the pot of 3 (i.e. winning 1 from player 2).
		if( lPlayer2DecisionRound2 == Fold)
		{
			std::cout << "PLAYER TWO FOLDS!!!!"<< std::endl;
			lKuhnGame->MakeWinner(1);
		}

		//If player two calls there is a showdown for the pot of 4 (i.e. the higher card wins 2 from the other player).
		if( lPlayer2DecisionRound2 == Call)
		{
			std::cout << "IN THE SHOWDOWN"<< std::endl;

			lKuhnGame->Showdown();
		}
	}

	std::cout << "After "<< lRoundsToPlay << " rounds"<< std::endl;
	std::cout << "Player 1 won: "<< lKuhnGame->mPlayer1Wins << " rounds"<< std::endl;
	std::cout << "Player 2 won: "<< lKuhnGame->mPlayer2Wins << " rounds"<< std::endl;

	return 0;
}
