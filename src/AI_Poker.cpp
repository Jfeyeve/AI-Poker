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
	names.push_back("Ant");

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

	cGames* lNewPokerGame = new cGames(2, 2, 3, 50, 1, 2, &names);

	lNewPokerGame->DisplayGameParameters();

	cout<< "\nThese are the players: "<< endl;
	for(auto& i:names){
	cout<< "my name is "<<i<<endl;
	}

	return 0;
}
