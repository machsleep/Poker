/*
 * Game.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: machsleep
 */
#include "Game.hpp"

Game::Game() {
	bettingRound = 0;
	dealer = NULL;
}

const vector<Player*>& Game::getActivePlayers() {
	if (activePlayers.size() != 0 ) return activePlayers;
	for (unsigned int i=0;i<players.size();i++)
		if(players[i].isPlaying())
			activePlayers.push_back(&players[i]);
	return activePlayers;
}

const unsigned int& Game::getBettingRound() const {
	return bettingRound;
}

const Player* Game::getDealer() const {
	return dealer;
}

Player& Game::getPlayerAtChair(int i) {
	return players[i];
}

const Card Game::topCardOfDeck() {
	return cardDeck.top();
}

const vector<Player>& Game::getPlayers() const {
	return players;
}

const vector<Card>& Game::getBoard() const {
	return board;
}
