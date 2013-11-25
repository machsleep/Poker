/*
 * Table.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: machsleep
 */

#include "Table.hpp"

Table::Table(Game& g) {
	dealer = NULL;
	game = &g;
	numActivePlayers = 0;
}

Table::~Table() {

}

LoopList<Player>& Table::getPlayers()  {
	return allPlayers;
}

const Player& Table::getPlayerAtChair(int i) const {
	return allPlayers[i];
}

const Player& Table::getDealer() const {
	return *dealer;
}

void Table::addPlayer(Player& player) {
	allPlayers.add(player);
}

void Table::setDealer(unsigned int activePlayerIndex) {
	Player *p;
	unsigned int tmp = -1;
	while ( (p=allPlayers.next()) ) {
		if (p->isActive()) tmp++;
		if (tmp == activePlayerIndex) {
			dealer = p;
			break;
		}
	}
}

unsigned int Table::getNumberOfActivePlayers() {
	if (allPlayers.getSize() == 0 || numActivePlayers > 0) return numActivePlayers;
	Player *p;
	while ((p=allPlayers.next())) {
		if (p==NULL) break;
		if (p->isActive()) numActivePlayers++;
	}
	return numActivePlayers;
}
