/*
 * Card.cpp
 *
 *  Created on: Nov 11, 2013
 *      Author: machsleep
 */
#include "Card.hpp"

Card::Card() {
	this->rank = Rank::NONE;
	this->suit = Suit::NONE;
	this->isFaceup = false;
}

/**
 * Copy constructor. Simply make a copy of the src Card.
 */
Card::Card(const Card& src) {
	this->isFaceup = src.isFaceUp();
	this->rank = src.getRank();
	this->suit = src.getSuit();
}

/**
 * Constructs a new card with rank and suit. The card is initialized as face down.
 *
 * @param CardType::Rank& rank, the rank of the card
 * @param CardType::Suit& suit, the suit of the card
 */
Card::Card(const Rank::type & rank, const Suit::type & suit) {
	this->rank = rank;
	this->suit = suit;
	this->isFaceup = false;
}

/**
 * Copies rhs to this card.
 */
Card& Card::operator=(const Card& rhs) {
	if (this == &rhs) return (*this);
	this->isFaceup = rhs.isFaceUp();
	this->rank = rhs.getRank();
	this->suit = rhs.getSuit();
	return (*this);
}

Card::~Card() {

}

Suit::type Card::getSuit() const {
	return this->suit;
}

Rank::type Card::getRank() const {
	return this->rank;
}

bool Card::isFaceUp() const {
	return this->isFaceup;
}

void Card::turn() {
	this->isFaceup = !isFaceUp();
}

std::ostream& operator<<(std::ostream& os, const Card& card) {

	// Print rank
	switch (card.getRank()) {
			case Rank::NONE: os << "NoRank."; break;
			case Rank::ACE: os << "Ace."; break;
			case Rank::TWO: os << "2."; break;
			case Rank::THREE: os << "3."; break;
			case Rank::FOUR: os << "4."; break;
			case Rank::FIVE: os << "5."; break;
			case Rank::SIX: os << "6."; break;
			case Rank::SEVEN: os << "7."; break;
			case Rank::EIGHT: os << "8."; break;
			case Rank::NINE: os << "9."; break;
			case Rank::TEN: os << "10."; break;
			case Rank::JACK: os << "J."; break;
			case Rank::QUEEN: os << "Q."; break;
			case Rank::KING: os << "K."; break;
			default: os << " ERROR: No Rank explicitly defined.";
	}

	// Print suit
	switch (card.getSuit()) {
		case Suit::NONE: os << "NoSuit."; break;
		case Suit::SPADES: os << "Spades."; break;
		case Suit::HEARTS: os << "Hearts."; break;
		case Suit::CLUBS: os << "Clubs."; break;
		case Suit::DIAMONDS: os << "Diamonds."; break;
		default: os << " ERROR: No Suit explicitly defined.";
	}

	os << (card.isFaceUp() ? "Faceup." : "Facedown.");

	return os;
}

