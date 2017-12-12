/*
 * SystemEnums.h
 *
 *  Created on: Nov 16, 2017
 *      Author: Jonathan
 */

#ifndef SYSTEMENUMS_H_
#define SYSTEMENUMS_H_

	typedef enum GamePhase
	{
		PreFlop,
		Flop,
		Turn,
		River
	}GamePhases;

	typedef enum PlayerPosition
	{
		Dealer = 0,
		SmallBlind,
		BigBlind,
		Third,
		Fourth,
		Fifth,
		Sixth,
		Seventh,
		Eigth,
		Nineth,
		NotAssigned
		}PlayerPositions;

	typedef enum PlayerStyle
	{
		//TODO:These styles are placeholders and need to updated to real styles
		Passive,
		Aggressive,
		PassiveAggressive = 4,
		AI = 2,
		Random = 3,
		Manual = 1,
	}PlayerStyles;

	typedef enum PlayerName
	{
		Sam,
		Anthony,
		Jon,
		Ben,
		Tom,
		Yani,
		Zion,
		Omar
	}PlayerNames;

	typedef enum Bet
	{
		Fold,
		Check,
		Call,
		Bet,
		AllIn,
		Pass,
		NoBetSelected
	}Bets;

	typedef enum Card
	{
		Ace,
		One,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King
	}Cards;

	typedef enum Suit
	{
		Hearts,
		Diamonds,
		Clubs,
		Spades
	}Suits;

	typedef enum NumberOfCardsToDeal
	{
		TotalPlayerCards = 2,
		TotalFlopCards = 3,
		EveryPhaseAfter = 1,
		TotalCardsInAHand = 5
	}TotalCardsToDeal;

	typedef enum PlayerHand
	{
		FlopCard1=0,
		FlopCard2,
		FlopCard3,
		TurnCard4,
		RiverCard5
	}PlayerHandCardNumber;

	typedef enum Actions
	{
		KuhnPass = 0,
		KuhnBet = 1,
		KuhnTotalActions = 2
	}KuhnActions;

	typedef enum PokerGameName{
		Kuhn,
		RhodeIsland,
		HoldemLimit
	}PokerGameType;

	typedef enum Winner{
		ManualPlayer,
		AIJack,
		RandomPlayer,
		TAGPlayer
	}GameWinner;

#endif /* SYSTEMENUMS_H_ */
