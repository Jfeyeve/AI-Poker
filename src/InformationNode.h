/*
 * InformationNode.h
 *
 *  Created on: Dec 11, 2017
 *      Author: Jonathan
 */

#ifndef INFORMATIONNODE_H_
#define INFORMATIONNODE_H_

#include <string>
#include <vector>

#include "SystemEnums.h"

class cInformationNode {
public:
	cInformationNode();
	virtual ~cInformationNode();

	std::string mInformationSetKey;

	static std::vector<double> mRegretSum;
	static std::vector<double> mStrategy;
	static std::vector<double> mStrategySum;

	std::vector<double> GetAverageStrategy();

	std::vector<double> GetStrategy(double realizationWeight);

};



#endif /* INFORMATIONNODE_H_ */
