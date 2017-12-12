/*
 * InformationNode.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: Jonathan
 */

#include <iostream>
#include "InformationNode.h"

std::vector<double> cInformationNode::mRegretSum;
std::vector<double> cInformationNode::mStrategy;
std::vector<double> cInformationNode::mStrategySum;

cInformationNode::cInformationNode() {
	mRegretSum = {0.0, 0.0};
	mStrategy = {0.0, 0.0};
	mStrategySum= {0.0, 0.0};
}

cInformationNode::~cInformationNode() {
	// TODO Auto-generated destructor stub
}

std::vector<double> cInformationNode::GetAverageStrategy()
{
	std::vector<double> lAverageStrategy;
	double lNormalizingSum = 0;

	for(int i = 0; i < KuhnTotalActions; i++)
	{
		lNormalizingSum += mStrategySum.at(i);
	}

	for(int j = 0; j < KuhnTotalActions; j++)
	{
		if(lNormalizingSum >0)
		{
			lAverageStrategy.push_back(mStrategySum.at(j)/lNormalizingSum);
		}
		else
		{
			lAverageStrategy.at(j) = 1.0/KuhnTotalActions;
		}
	}

	return lAverageStrategy;
}

std::vector<double> cInformationNode::GetStrategy(double aRealizationWeight)

{
	double lRegretSum = 0;
	double lNormalizingSum = 0;

	for(int i = 0; i < KuhnTotalActions; i++)
	{
		lRegretSum = mRegretSum.at(i) > 0.0 ? mRegretSum.at(i) : 0.0;
		mStrategy.push_back(lRegretSum);
		lNormalizingSum += mStrategy.at(i);
	}

	for( int j = 0; j < KuhnTotalActions; j++)
	{
		if(lNormalizingSum>0){
			mStrategy.at(j) /= lNormalizingSum;
		}
		else
		{
			mStrategy.at(j) = 1.0/KuhnTotalActions;
			mStrategySum.at(j) += aRealizationWeight * mStrategy.at(j);
		}
	}

	return mStrategy;
}
