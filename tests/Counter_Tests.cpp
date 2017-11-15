/*
 * Counter_Tests.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: Jonathan
 */

#include "gtest/gtest.h"
#include "../src/cGames.h"

TEST(Games, StartGame) {
	std::vector<std::string> names;
	names.push_back("jonathan");

	cGames games(2, 2, 3, 50, 1, 2, &names);

	ASSERT_TRUE(games.StartTheGames());
}

int main(int argc, char **argv) {
      ::testing::InitGoogleTest(&argc, argv);
      return RUN_ALL_TESTS();
}


