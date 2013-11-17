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

const double  Player::getMoney() const {
	return money;
}

const bool Player::isPlaying() const {
	return active && !folded;
}

const bool Player::isSittingOut() const {
	return !active;
}

const bool Player::isFolding() const {
	return folded;
}

const bool Player::doesMuck() const {
	return mucked;
}

void Player::addCardToHand(Card card) {
	hand.push_back(card);
}

bool Player::placeBid(double bid) {
	if (money - bid < 0) return false;
	money-=bid;
	return true;
}

const std::string& Player::getName() const {
	return name;
}

const unsigned int& Player::getChairIndex() const {
	return chairIndex;
}




