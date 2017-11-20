/*
 * RNG.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: Jonathan
 */

#include <ctime>
#include <cstdlib>

#include "RNG.h"

cRNG::cRNG() {
	srand(time(NULL));
	mRandomNumber = 0;
}

cRNG::~cRNG() {
	// TODO Auto-generated destructor stub
}

uint8_t cRNG::getRandomNumber()
{
	uint8_t high = 52;

	return (uint8_t)((rand()% high));
}
