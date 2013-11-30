/*
 * Card.hpp
 *
 *  Created on: Nov 10, 2013
 *      Author: machsleep
 */

#ifndef CARD_HPP_
#define CARD_HPP_

#include <iostream>
#include "../Evaluator/Evaluator.hpp"

using namespace std;

class Card {
	public:
		Card();
		Card(const Card& src);
		Card(int card);
		Card& operator=(const Card& rhs);
		
		virtual ~Card();
		int getRank() const;
		int getSuit() const;
		int getNumRepresentation() const;
	
		bool isFaceUp() const;
		void turn();
	    friend ostream& operator<<(ostream& os, const Card& card);
	private:
		/**		
			An integer is made up of four bytes.  The high-order
			bytes are used to hold the rank bit pattern, whereas
			the low-order bytes hold the suit/rank/prime value
			of the card.
	
			+--------+--------+--------+--------+
			|xxxbbbbb|bbbbbbbb|cdhsrrrr|xxpppppp|
			+--------+--------+--------+--------+
	
			p = prime number of rank (deuce=2,trey=3,four=5,five=7,...,ace=41)
			r = rank of card (deuce=0,trey=1,four=2,five=3,...,ace=12)
			cdhs = suit of card
			b = bit turned on depending on rank of card
		 */
		int card; 
		bool faceUp;
};
#endif /* CARD_HPP_ */