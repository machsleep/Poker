/*
 * Game.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: machsleep
 */
#include "Game.hpp"
#include "../Table/Table.hpp"
#include "../Rules/Rules.hpp"

Game::Game() {
	table = new Table(*this);
	rules = new Rules(*this);
	bettingRound = 0;
}

Game::~Game() {
	delete table;
	delete rules;
}

void Game::dealCards() {
	rules->dealCards();
}

void Game::initialize() {
	rules->initializeDealer();
}

void Game::addPlayerToTable(Player& player) {
	table->addPlayer(player);
}

const unsigned int& Game::getBettingRound() const {
	return bettingRound;
}

Player& Game::getDealer() const {
	return *table->getDealer();
}

const Player& Game::getPlayerAtChair(int i) const {
	return table->getPlayerAtChair(i);
}

const LoopList<Player>& Game::getPlayers() const {
	return table->getPlayers();
}

const vector<Card>* Game::getBoard() const {
	return &board;
}

void Game::listPlayers(ostream& os) const {
	os << table->getPlayers();
}

const Deck& Game::getDeck() const {
	return cardDeck;
}

void Game::listActivePlayers(ostream& os) const {

}

void Game::shuffleDeck() {
	cardDeck.shuffle();
}
