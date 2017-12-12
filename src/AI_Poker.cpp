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
#include "RNG.h"

using namespace std;

int main() {
	uint8_t lRandomNumber = 52;

	cout<< "hello again"<<endl;
	cout<< "this is the MAX: "<< RAND_MAX;

	int lRandom;
	cRNG RNG;

	for(int i=0; i<2; i++)
	{
		lRandom = RNG.getRandomNumber(lRandomNumber);
		cout<< lRandom <<endl;
	}

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

	cRules* lRules = new cRules();
	bool lExpectedValue = false;
	sort(lAHandOfCards.begin(), lAHandOfCards.end(), lRules->compare);
	 for (std::vector<cCard*>::iterator it=lAHandOfCards.begin(); it!=lAHandOfCards.end(); ++it)
	    std::cout << ' ' << (*it)->mValue;
	  std::cout << '\n';

	cout<< "After"<<endl;

	cAITrainer* lAgent = new cAITrainer(2, Kuhn);



	return 0;
}
