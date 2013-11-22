/*
 * Player.cpp
 *
 *  Created on: Nov 15, 2013
 *      Author: machsleep
 */
#include "Player.hpp"

Player::~Player() {

}

Player::Player(std::string name, unsigned int chair, double money, bool folded, bool active, bool mucked)
{
	this->name = name;
	this->chairIndex = chair;
	this->money = money;
	this->folded = folded;
	this->active = active;
	this->mucked = mucked;
}

Player::Player(const Player& src) {
	this->name = src.getName();
	this->chairIndex = src.getChairIndex();
	this->money = src.getMoney();
	this->folded = src.isFolding();
	this->active = src.isActive();
	this->mucked = src.doesMuck();
}

const double Player::getMoney() const {
	return money;
}

const bool Player::isPlaying() const {
	return active && !folded;
}

const bool Player::isActive() const {
	return !active;
}

const bool Player::isFolding() const {
	return folded;
}

const bool Player::doesMuck() const {
	return mucked;
}

bool Player::placeBid(double bid) {
	if (money - bid < 0) return false;
	money-=bid;
	return true;
}

const std::string Player::getName() const {
	return name;
}

const unsigned int Player::getChairIndex() const {
	return chairIndex;
}

const std::vector<Card> Player::getHand() const {
	return hand;
}

Player& Player::operator=(const Player& src) {
	if (this == &src) return *this;
	this->name = src.getName();
	this->chairIndex = src.getChairIndex();
	this->money = src.getMoney();
	this->folded = src.isFolding();
	this->active = src.isActive();
	this->mucked = src.doesMuck();
	return *this;
}


/*
 * Compares two players by directly comparing their chair indexes.
 */
const bool operator<(const Player& lhs, const Player& rhs) {
	return lhs.chairIndex < rhs.chairIndex;
}

const bool operator>(const Player& lhs, const Player& rhs) {
	return lhs.chairIndex > rhs.chairIndex;
}

/*
 * Compares two players by directly comparing their chair indexes.
 */
const bool operator<=(const Player& lhs, const Player& rhs) {
	return lhs.chairIndex <= rhs.chairIndex;
}

const bool operator==(const Player& lhs, const Player& rhs) {
	return lhs.name == rhs.name;
}

std::ostream& operator<<(std::ostream& os, const Player player) {
	os << player.name;
	return os;
}





