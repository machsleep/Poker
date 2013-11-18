/*
 * Game.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: machsleep
 */
#include "Game.hpp"

Game::Game() {
	bettingRound = 0;
}

const LoopList<Player>* Game::getActivePlayers() const {
	return table.getActivePlayers();
}

const unsigned int& Game::getBettingRound() const {
	return bettingRound;
}

const Player* Game::getDealer() const {
	return table.getDealer();
}

const Player* Game::getPlayerAtChair(int i) const {
	return table.getPlayerAtChair(i);
}

const Card Game::topCardOfDeck() {
	return cardDeck.top();
}

const LoopList<Player>* Game::getPlayers() const {
	return table.getPlayers();
}

const vector<Card>* Game::getBoard() const {
	return &board;
}
