/*
 * Deck.cpp
 *
 *  Created on: Nov 11, 2013
 *      Author: machsleep
 */

#include "Deck.hpp"
#include <boost/random.hpp>
#include <boost/generator_iterator.hpp>
#include <algorithm>
#include <ctime>
/*
 * Constructs a standard poker deck of 52 Cards.
 */
Deck::Deck() {
	for (int suit = 1; suit <= 4; suit++) {
		Suit::type st = static_cast<Suit::type>(suit);
		for (int rank = 1; rank <= 13 ; rank++) {
			Rank::type rnk = static_cast<Rank::type>(rank);
			cards.push_back(Card(rnk,st));
		}
	}
	currentCard=-1;
}

const Card& Deck::top() {
	if (cards.size() == currentCard) throw "Error: Cannot retrieve top card in Deck::top() when deck is empty.";
	currentCard+=1;
	return cards[currentCard];
}

/*
 * Outputs each card in deck
 */
std::ostream& operator<<(std::ostream& os, const Deck& deck) {
	os  << "This deck contains the following cards" << std::endl;
	for (unsigned int i=0; i<deck.cards.size(); i++) {
		os << deck.cards[i] << std::endl;
	}
	return os;
}

/**
 * Shuffles a deck using a Boost's internal randomization functions.
 */
void Deck::shuffle() {
	typedef boost::mt19937 RNGType;
	RNGType rng;
	unsigned int time_ui = static_cast<unsigned int>( time(NULL) );
	rng.seed(time_ui);
	boost::uniform_int<> card_picker;
	boost::variate_generator<RNGType, boost::uniform_int<> > cardchoice(rng, card_picker);
	std::random_shuffle(cards.begin(), cards.end(), cardchoice);
}

Deck::~Deck() {
}
