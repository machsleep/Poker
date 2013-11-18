/*
 * Table.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: machsleep
 */

#include "Table.hpp"

Table::Table() {
	dealer = NULL;
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

Table::~Table() {
	// TODO Auto-generated destructor stub
}

