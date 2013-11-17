/*
 * Card.hpp
 *
 *  Created on: Nov 10, 2013
 *      Author: machsleep
 */

#ifndef CARD_HPP_
#define CARD_HPP_

#include "CardTypes.hpp"
#include <iostream>

class Card {
	public:
		Card();
		Card(const Card& src);
		Card(const Rank::type & rank, const Suit::type& suit);
		Card& operator=(const Card& rhs);
		virtual ~Card();
		virtual Rank::type getRank() const;
		virtual Suit::type getSuit() const;
		virtual bool isFaceUp() const;
		virtual void turn();
	    friend std::ostream& operator<<(std::ostream& os, const Card& card);
	private:
		Suit::type suit;
		Rank::type rank;
		bool isFaceup;
};

#endif /* CARD_HPP_ */
