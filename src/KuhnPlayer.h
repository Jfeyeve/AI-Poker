/*
 * KuhnPlayer.h
 *
 *  Created on: Dec 12, 2017
 *      Author: Jonathan
 */

#ifndef KUHNPLAYER_H_
#define KUHNPLAYER_H_

#include <vector>
#include "Player.h"

class KuhnPlayer : public cPlayer
{
public:
	KuhnPlayer(std::string aName, PlayerStyles aPlayerStyle, uint32_t aChips);
	virtual ~KuhnPlayer();
};

#endif /* KUHNPLAYER_H_ */
