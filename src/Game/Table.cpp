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

 LoopList<Player*>* Table::getActivePlayers() {
	return &activePlayers;
}

 LoopList<Player>* Table::getPlayers()  {
	return &allPlayers;
}

const Player* Table::getPlayerAtChair(int i) const {
	return &(allPlayers[i]);
}

const Player* Table::getDealer() const {
	return NULL;
}

void Table::addPlayer(Player& player) {
	allPlayers.add(player);
	Player *p = allPlayers.getLast();
	if (player.isActive())
		activePlayers.add(p);
}
