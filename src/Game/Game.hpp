/*
 * Game.hpp
 *
 *  Created on: Nov 15, 2013
 *      Author: machsleep
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include "../Deck/Deck.hpp"
#include "../Player/Player.hpp"
#include "Table.hpp"

#include <vector>
#include <map>

using std::vector;
using std::map;


/*! The base class for any card game */
class Game {
public:
	Game();
	/**
	 * Returns the cards on the board that all players can see.
	 */
	const vector<Card>* getBoard() const;
	const Player* getDealer() const;
	const Deck* getDeck() const;
	const LoopList<Player>* getPlayers() const;
	const LoopList<Player>* getActivePlayers() const;
	const Player* getPlayerAtChair(int chair) const;
	const unsigned int& getBettingRound() const;


	const Card topCardOfDeck();

private:
	// Table of players (implemented as a loop list)
	Table table;
	unsigned int bettingRound;
	Deck cardDeck;
	vector<Card> board;
	vector<Card> discard;
};


#endif /* GAMEENGINE_HPP_ */
