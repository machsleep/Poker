/*
 * CardTypes.hpp
 *
 *  Created on: Nov 10, 2013
 *      Author: machsleep
 *     Comment: This header defines some useful enumerations for cards.
 *
 */

#ifndef CARDTYPES_HPP_
#define CARDTYPES_HPP_

/*
 * Do not change the order of these enums. Other classes depend on this ordering.
 */
namespace Suit {  enum type {NONE, SPADES, HEARTS, CLUBS, DIAMONDS }; }
namespace Rank {  enum type {NONE, ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING }; }

#endif /* CARDTYPES_HPP_ */
