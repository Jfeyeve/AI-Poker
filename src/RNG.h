/*
 * RNG.h
 *
 *  Created on: Nov 19, 2017
 *      Author: Jonathan
 */

#ifndef RNG_H_
#define RNG_H_

#include <cstdlib>
#include <stdint.h>

class cRNG {
public:
	cRNG();
	virtual ~cRNG();

	uint8_t getRandomNumber(uint8_t aHigh);
private:
	uint8_t mRandomNumber;
};

#endif /* RNG_H_ */
