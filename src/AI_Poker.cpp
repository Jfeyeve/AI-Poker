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

	int lRoundsToPlay = 1;
	int lManualPlayerWinCount = 0;
	int AIJackWinCount = 0;
	int RandomPlayerWinCount = 0;
	int TAGPlayerWinCount = 0;

	int lPlayer1Type = 0;
	int lPlayer2Type = 0;

	std::cout << "Select Player 1: Enter 1 = Manual, 2 = AIJack, 3 = Random, 4 = TAGPlayer"<< std::endl;
	std::cin >> lPlayer1Type;
	std::cout << "You selected "<< lPlayer1Type << " for Player 1"<< std::endl;
	std::cout << "Select Player 2: Enter 1 = Manual, 2 = AIJack, 3 = Random, 4 = TAGPlayer"<< std::endl;
	std::cin >> lPlayer2Type;
	std::cout << "You selected "<< lPlayer2Type << " for Player 2"<< std::endl;

//	if( (PlayerStyles)lPlayer1Type == Manual)
//	{
//		std::cout<< "We are Manual"<<std::endl;
//	}


	KuhnPoker* lKuhnGame = new 	KuhnPoker((PlayerStyles)lPlayer1Type, (PlayerStyles)lPlayer2Type);

	for( int i = 0; i < lRoundsToPlay; i++)
	{
		//Each Player Antes 1
		lKuhnGame->CollectAnte();

		//Each player is dealt one of the three cards, and the third is put aside unseen.
		lKuhnGame->DealToPlayer();

		//Player one can check or bet 1.
		Bets lPlayer1Decision = lKuhnGame->Player1BetPass();

		//If player one checks then player two can check or bet 1.
		Bets lPlayer2Decision = lKuhnGame->Player2BetPass();

		//If player two checks there is a showdown for the pot of 2 (i.e. the higher card wins 1 from the other player).
		if( lPlayer1Decision == Check && lPlayer2Decision == Check)
		{
			GameWinner lWinner = ManualPlayer;
			lWinner = lKuhnGame->Showdown();
			lKuhnGame->RecordResults();
		}
	}

	std::cout << "After "<< lRoundsToPlay << " rounds"<< std::endl;
	std::cout << "Player 1 won: "<< lKuhnGame->mPlayer1Wins << " rounds"<< std::endl;
	std::cout << "Player 2 won: "<< lKuhnGame->mPlayer2Wins << " rounds"<< std::endl;


	//If player two bets then player one can fold or call.
	//	if( lPlayer1Decision == Bet && lPlayer2Decision == Bet)
	//		{

	//			Showdown();
	//		}
	//If player one folds then player two takes the pot of 3 (i.e. winning 1 from player 1).

	//If player one calls there is a showdown for the pot of 4 (i.e. the higher card wins 2 from the other player).

	//If player one bets then player two can fold or call.

	//If player two folds then player one takes the pot of 3 (i.e. winning 1 from player 2).

	//If player two calls there is a showdown for the pot of 4 (i.e. the higher card wins 2 from the other player).



	return 0;
}
