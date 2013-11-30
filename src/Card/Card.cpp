/*
 * Card.cpp
 *
 *  Created on: Nov 11, 2013
 *      Author: machsleep
 */
#include "Card.hpp"

Card::Card() {
	card = 0;
	faceUp = false;
}

Card::Card(int card) {
	this->card = card;
	faceUp = false;
}

/**
 * Copy constructor. Simply make a copy of the src Card.
 */
Card::Card(const Card& src) {
	this->card = src.getNumRepresentation();
	this->faceUp = src.isFaceUp();
}

/**
 * Copies rhs to this card.
 */
Card& Card::operator=(const Card& rhs) {
	if (this == &rhs) return (*this);
	this->faceUp = rhs.isFaceUp();
	this->card = rhs.getNumRepresentation();
	return (*this);
}

Card::~Card() {
}

int Card::getSuit() const {
	return SUIT(card);
}

int Card::getRank() const {
	return RANK(card);
}

bool Card::isFaceUp() const {
	return this->faceUp;
}

void Card::turn() {
	this->faceUp = !isFaceUp();
}

int Card::getNumRepresentation() const {
	return card; 
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
	if (card.getNumRepresentation() == -1) {
		os << "Card Not Defined";
		return os;
	}

	// Print rank
	switch (card.getRank()) {
			//os << card.getRank() << " ";
			case Ace: os << "Ace."; break;
			case Deuce: os << "2."; break;
			case Trey: os << "3."; break;
			case Four: os << "4."; break;
			case Five: os << "5."; break;
			case Six: os << "6."; break;
			case Seven: os << "7."; break;
			case Eight: os << "8."; break;
			case Nine: os << "9."; break;
			case Ten: os << "10."; break;
			case Jack: os << "J."; break;
			case Queen: os << "Q."; break;
			case King: os << "K."; break;
			default: os << "No rank defined.";
	}

	// Print suit
	switch (card.getSuit()) {
		case SPADE: os << "Spades."; break;
		case HEART: os << "Hearts."; break;
		case CLUB: os << "Clubs."; break;
		case DIAMOND: os << "Diamonds."; break;
		default: os << "No Suit defined.";
	}
	
	os << (card.isFaceUp() ? "Faceup." : "Facedown.");
	return os;
}

