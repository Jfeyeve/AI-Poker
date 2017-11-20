//============================================================================
// Name        : AI.cpp
// Author      : Jonathan Velez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

#include "Game.h"
#include "RNG.h"

using namespace std;

int main() {

	cout<< "hello again"<<endl;
	cout<< "this is the MAX: "<< RAND_MAX;

	int lRandom;
	cRNG RNG;

	for(int i=0; i<20; i++)
	{
		lRandom = RNG.getRandomNumber();
		cout<< lRandom <<endl;
	}

	return 0;
}
