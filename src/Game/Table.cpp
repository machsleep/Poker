/*
 * Table.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: machsleep
 */

#include "Table.hpp"

Table::Table(Game& game) {
	dealer = NULL;
	this->game = &game;
}

Table::~Table() {

}

const LoopList<Player>* Table::getActivePlayers() const {
	return &activePlayers;
}

const LoopList<Player>* Table::getPlayers() const {
	return &allPlayers;
}

const Player* Table::getPlayerAtChair(int i) const {
	return &(allPlayers[i]);
}

const Player* Table::getDealer() const {
	return NULL;
}

void Table::addPlayer(Player& player) {
	Player pl = player;
	this->allPlayers.add(player);
}
