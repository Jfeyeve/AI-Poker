//============================================================================
// Name        : AI.cpp
// Author      : Jonathan Velez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

#include "cGames.h"

using namespace std;

int main() {

	/*
	 * This is a vector exercise
	 */
	std::vector<std::string> names;

	names.push_back("jonathan");
	names.push_back("Dealer");
	names.push_back("AI");
	names.push_back("Sam");

	//Printing from vector using iterator and auto
/*	for(auto& i:names){
	cout<< "my name is "<<i<<endl;
	}*/

	//printing with for loop
	//create the iterator
	vector<string>::iterator it;

	//loop from beginning to end
/*	for(it = names.begin(); it != names.end(); it++)
	{
		cout<< "my name is "<<(*it)<<endl;
	}*/


	/*
	 * Test Class starts here
	 */

	cGames* lNewPokerGame = new cGames(2, 2, 3, 10, 1, 2, &names);

	cout<< "Total Games: "<< lNewPokerGame->mNumberOfGames<<endl;
	cout<< "Total Rounds: "<< lNewPokerGame->mRoundsPerGame<<endl;
	cout<< "Total Players: "<< lNewPokerGame->mTotalPlayers<<endl;
	cout<< "Total Chips per player: "<< lNewPokerGame->mChipsPerPlayer<<endl;
	cout<< "Total Small Blind: "<< lNewPokerGame->mSmallBlind<<endl;
	cout<< "Total Big Blind: "<< lNewPokerGame->mBigBlind<<endl;

	cout<< "\nThese are the players: "<< endl;
	for(auto& i:names){
	cout<< "my name is "<<i<<endl;
	}

	return 0;
}
