/*
 * Rules.hpp
 *
 *  Created on: Nov 16, 2013
 *      Author: machsleep
 */

#ifndef RULES_HPP_
#define RULES_HPP_

#include "../Player/Player.hpp"

class Game;

/** Deals cards, ends game, validates bidding amounts, determines winners, and distributes winnings */
class Rules {
	public:
		Rules(Game& game);
		virtual ~Rules();
		//virtual const bool isBidValid(double bid) const;
		/**
		 * The default dealCards function  uses a Texas-hold'em
		 * method. This method should be called each time a bidding round ends.
		 * 1) The first call deals 2 cards to each active player (starting with first player left of dealer)
		 * 2) The second call discards 1 card and puts 3 cards on the board (flop).
		 * 3) The third call discards 1 card and puts 1 card on the board (turn).
		 * 4) The fourth call discards 1 card an puts 1 card on the board (river).
		 *
		 * Any call to this function after the 4th call will do nothing.
		 *
		 * Note: If you would like to create another game, derive a new Game class and override this default
		 * behavior.
		 */
		virtual void dealCards();
		//virtual Player& getWinner() const;
		//virtual void payOffPlayers();
	private:
		Game *game;
};


#endif /* RULES_HPP_ */
