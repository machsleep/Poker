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
		const vector<Card>& getBoard() const;
		const vector<Player>& getPlayers() const;
		const Player* getDealer() const;
		const unsigned int& getBettingRound() const;
		const Deck& getDeck() const;
		const vector<Player*>& getActivePlayers();

		const Card topCardOfDeck();
		Player& getPlayerAtChair(int chair);

	private:

		Player* dealer;
		unsigned int bettingRound;
		Deck cardDeck;
		vector<Card> board;
		vector<Card> discard;
		vector<Player> players;
		vector<Player*> activePlayers;
};


#endif /* GAMEENGINE_HPP_ */
