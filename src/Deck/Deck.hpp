/*
 * Deck.hpp
 *
 *  Created on: Nov 11, 2013
 *      Author: machsleep
 *      comments: This class defines a basic poker deck. The poker deck contains 52 cards. This deck does not include
 *      Joker type cards.
 */

#ifndef DECK_HPP_
#define DECK_HPP_

#include <vector>
#include "../Card/Card.hpp"

class Deck {
	public:
		Deck();
	    virtual ~Deck();
	    /**
	     * Returns the top of the deck, removes this card from the deck.
	     * If the deck's size == 0, this function will throw a message indicating as such.
	     */
	    virtual const Card& top();

	    friend std::ostream& operator<<(std::ostream& os, const Deck& card);
	private:
		std::vector<Card> cards;
		std::vector<Card> cardsDealt;
};

#endif /* DECK_HPP_ */
