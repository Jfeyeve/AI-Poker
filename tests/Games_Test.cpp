/*
 * Counter_Tests.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: Jonathan
 */

#include "gtest/gtest.h"
#include "../src/Game.h"
#include "../src/SystemEnums.h"

class GamesTest : public ::testing::Test
{
	protected:
	virtual void SetUp()
	{

	}

	virtual void TearDown()
	{

	}

};

TEST_F(GamesTest, StartGame)
{
	std::map<std::string, PlayerStyles> lPlayers;
	lPlayers["Jon"]= Passive;
	lPlayers["Sam"]= PassiveAggressive;

	cGame* game = new cGame(2, 2, 2, 50, 1, 2, &lPlayers);
	bool lActualValue = game->StartTheGame();

	ASSERT_TRUE(lActualValue == true);
}

TEST_F(GamesTest, getGamePlayers)
{
	std::map<std::string, PlayerStyles> lPlayers;
	lPlayers["Jon"]= Passive;
	lPlayers["Sam"]= PassiveAggressive;

	cGame* game = new cGame(2, 2, 2, 50, 1, 2, &lPlayers);
	bool lActualValue = game->StartTheGame();

	std::vector<cPlayer*> lActivePlayers = game->getGamePlayers();

	std::map<std::string, PlayerStyles>::iterator it = lPlayers.begin();

	ASSERT_TRUE(lActivePlayers[0]->mName == it->first);
	it++;
	ASSERT_TRUE(lActivePlayers[1]->mName == it->first);
}
