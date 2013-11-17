/*
 * Deck.cpp
 *
 *  Created on: Nov 11, 2013
 *      Author: machsleep
 */

#include "Deck.hpp"

/**
 * Constructs a standard poker deck of 52 Cards.
 */
Deck::Deck() {
	for (int suit = 1; suit <= 4; suit++) {
		Suit::type st = static_cast<Suit::type>(suit);
		for (int rank = 1; rank <= 13 ; rank++) {
			Rank::type rnk = static_cast<Rank::type>(rank);
			Card card(rnk, st);
			cards.push_back(card);
		}
	}
}

Card Deck::top() {
	Card c;
	if (cards.size() == 0) throw "Error: Cannot retrieve top card in Deck::top() when deck is empty.";
	c = cards[cards.size()-1];
	cards.pop_back();
	return c;
}

std::ostream& operator<<(std::ostream& os, const Deck& deck) {
	os  << "This deck contains the following cards" << std::endl;
	for (unsigned int i=0; i<deck.cards.size(); i++) {
		os << deck.cards[i] << std::endl;
	}
	return os;
}

Deck::~Deck() {
}
