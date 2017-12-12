/*
 * AITrainer.h
 *
 *  Created on: Dec 11, 2017
 *      Author: Jonathan
 */

#ifndef AITRAINER_H_
#define AITRAINER_H_

#include <unordered_map>
#include <string>
#include <vector>
#include <stdint.h>

#include "InformationNode.h"
#include "Card.h"
#include "RNG.h"

class cAITrainer {
public:
	cAITrainer(int32_t aIterations, PokerGameName aGameType);
	virtual ~cAITrainer();

	cRNG* mRandom = new cRNG();

	std::unordered_multimap<std::string, cInformationNode> mInformationSet;

	void TrainAgent(int32_t aIterations, PokerGameName aGameType);
	double CounterFactualRegret(std::vector<int> aCardsOfPlayersToCompare, std::string aHistory, double aPlayer0, double aPlayer1);

private:
	void KuhnTrainAgent(int32_t aIterations);

};

#endif /* AITRAINER_H_ */
