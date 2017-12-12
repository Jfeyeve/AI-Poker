/*
 * AITrainer.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: Jonathan
 */

#include <iostream>

#include "AITrainer.h"
#include "SystemEnums.h"

cAITrainer::cAITrainer(int32_t aIterations, PokerGameName aGameType) {

	TrainAgent(aIterations, aGameType);

}

cAITrainer::~cAITrainer() {
	// TODO Auto-generated destructor stub
}

void cAITrainer::TrainAgent(int32_t aIterations, PokerGameName aGameType)
{
	switch(aGameType){
	case Kuhn:
		KuhnTrainAgent(aIterations);
		break;
	default:
		break;
	}
}

double cAITrainer::CounterFactualRegret(std::vector<int> aCardsOfPlayersToCompare, std::string aHistory, double aPlayer0, double aPlayer1)
{
	//Get the length of the total rounds played
	int32_t lPlays = aHistory.length();
	//Assign Player 1 such that Player has the next turn if the plays are even
	int32_t lPlayer = lPlays % 2;
	//Assign Player 2 such that the Opponent is first if the plays are odd
	int32_t lOpponent = 1 - lPlayer;

	//If there is more than one play in the game history
	if(lPlays > 1)
	{
		std::cout<< "game loop"<<std::endl;
		//The round has ended, now we need to compare cards, or reward player 1
		bool lTerminalPass = aHistory.at(lPlays - 1) == 'p';

		//Game ended with two bets, the winner is the player with the highest card
		std::string lTempString = aHistory.substr(lPlays-2, 2);

		bool lDoubleBet = lTempString.compare("bb")!= 0 ? false: true;

		//Compare player cards to see who has the higher card
		bool lIsPlayerCardHigher = aCardsOfPlayersToCompare.at(lPlayer) > aCardsOfPlayersToCompare.at(lOpponent);

		//Cover all the cases of game play
		//case1: we end the round in a Pass, "p"
		if(lTerminalPass)
		{
			//Both players pass, the player with the higher card wins
			bool lCompareHistory = aHistory.compare("pp") != 0 ? false:true;

			if(lCompareHistory){
				return lIsPlayerCardHigher ? 1:-1;
			}
			else{
				//Player 2 passes, so Player 1 wins
				return 1;
			}
		}
		//case2: we end with double Bet, "bb"
		else if(lDoubleBet)
		{
			//Both players bet, the player with the higher card wins
			return lIsPlayerCardHigher ? 2: -2;
		}
	}

	//Create a key for the information set
	std::string lInformationSet = std::to_string(aCardsOfPlayersToCompare.at(lPlayer)) + aHistory;

	//Check to make sure the information doesn't exist
	auto lInformationSetExists = mInformationSet.find(lInformationSet);
	//get the current node
	std::unordered_multimap<std::string, cInformationNode>::iterator lNodeIterator;

	//Check if the map is empty, if it is empty create a node for the information set
	if(lInformationSetExists == mInformationSet.end()){

		//Create a new node for the information set, and save it in the map
		cInformationNode* lNodeForMap = new cInformationNode();
		//save the information set key
		lNodeForMap->mInformationSetKey = lInformationSet;
		//add the node to the map
		mInformationSet.insert(std::make_pair(lInformationSet, *lNodeForMap));
	}
	else
	{
		//get the current node
		lNodeIterator = mInformationSet.find(lInformationSet);
	}

	//Save the strategy of the current player, whoever's turn it is
	std::vector<double> lStrategy;
	std::cout<< "after loop199"<<std::endl;
	lStrategy = lNodeIterator->second.GetStrategy(lPlayer == 0 ? aPlayer0 : aPlayer1);
//	std::cout << std::to_string((lNodeIterator->second.GetStrategy(lPlayer == 0 ? aPlayer0 : aPlayer1)).at(0));
	std::cout<< "after loop2"<<std::endl;

	//Variables for Node information
	std::vector<double> lUtility;
	double lUtilityOfNode = 0;

	for(int i = 0; i < KuhnTotalActions; i++)
	{
		std::string lNextHistory = aHistory + ( i == 0 ? "p" : "b");

		lUtility.push_back(lPlayer == 0 ? - CounterFactualRegret(aCardsOfPlayersToCompare, lNextHistory, aPlayer0 * lStrategy.at(i), aPlayer1)
				: - CounterFactualRegret(aCardsOfPlayersToCompare, lNextHistory, aPlayer0, aPlayer1 * lStrategy.at(i)));

		lUtilityOfNode += lStrategy.at(i) * lUtility.at(i);
	}

	double lRegret = 0;

	for(int j = 0; j < KuhnTotalActions; j++)
	{
		lRegret = lUtility.at(j) - lUtilityOfNode;
		lNodeIterator->second.mRegretSum[j] += (lPlayer == 0 ? aPlayer0:aPlayer1) * lRegret;
	}

	return lUtilityOfNode;
}

void cAITrainer::KuhnTrainAgent(int32_t aIterations)
{
	std::vector<int> gameCards = {1,2,3};
	double lUtility = 0;

	//repeat the training for required iterations
	for(int i = 0; i< aIterations; i++)
	{
		//shuffle the deck of cards
		for(int card1 = gameCards.size()-1; card1>0; card1--)
		{
			int card2 = mRandom->getRandomNumber(card1 +1);

			int lTemporaryCard = gameCards.at(card1);
			gameCards.at(card1) = gameCards.at(card2);
			gameCards.at(card2) = lTemporaryCard;
		}

		//Learn using CFR, the players are both 1
		lUtility += CounterFactualRegret(gameCards, "", 1,1);
	}

	std::cout<< "Average game value: " + std::to_string((lUtility/aIterations)) <<std::endl;

	// Iterate over an unordered_map using range based for loop
	for (std::pair<std::string, cInformationNode>  element : mInformationSet)
	{
		for(int i =0; i < element.second.mRegretSum.size(); i++)
		{
			std::cout << element.first << " :: Regret Sum ::" << element.second.mRegretSum.at(i) << std::endl;
		}
	}
}
