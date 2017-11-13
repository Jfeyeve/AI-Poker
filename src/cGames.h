/*
 * cGames.h
 *
 *  Created on: Nov 13, 2017
 *      Author: Jonathan
 */

#ifndef CGAMES_H_
#define CGAMES_H_

class cGames {
public:
	int mNumberOfGames;
	int mRoundsPerGame;
	int mTotalPlayers;
	int mChipsPerPlayer;
	int mSmallBlind, mBigBlind;

	cGames(int aNumberOfGames, int aRoundsPerGame, int aTotalPlayers,
			    	int aChipsPerPlayer, int aSmallBlind, int aBigBlind,
					std::vector<std::string>* aPlayerNames);
	virtual ~cGames();
};

#endif /* CGAMES_H_ */
