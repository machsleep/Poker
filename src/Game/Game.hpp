/*
 * Game.hpp
 *
 *  Created on: Nov 15, 2013
 *      Author: machsleep
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include "../Deck/Deck.hpp"
#include "../Containers/LoopList.hpp"
#include "Table.hpp"

#include <vector>
#include <map>

using std::vector;
using std::map;
using std::ostream;

class Player;
class Rules;

/*! The base class for any card game */
class Game {
public:
	Game();
	virtual ~Game();
	/**
	 * Returns the cards on the board that all players can see.
	 */
	const vector<Card>* getBoard() const;
	const Player* getDealer() const;
	const Deck& getDeck() const;
	const LoopList<Player>* getPlayers() const;
	const LoopList<Player*>* getActivePlayers() const;
	const Player& getPlayerAtChair(int chair) const;
	const unsigned int& getBettingRound() const;

	void dealCards();
	void shuffleDeck();
	void addPlayerToTable(Player& player);

	/**
	 * Lists all players to the chosen output stream.
	 */
	void listPlayers(ostream& os) const;

	/**
	 * Lists all active players to the chosen output stream.
	 */
	void listActivePlayers(ostream& os) const;

	friend class Rules;

private:
	// Table of players (implemented as a loop list)
	Table *table;
	Rules *rules;
	unsigned int bettingRound;
	Deck cardDeck;
	vector<Card> board;
	vector<Card> discard;
};


#endif /* GAMEENGINE_HPP_ */
