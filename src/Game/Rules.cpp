/*
 * Rules.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: machsleep
 */

#include "Rules.hpp"
#include "Game.hpp"

Rules::Rules(Game& game) {
	this->game = &game;
}

Rules::~Rules() {

}

void Rules::dealCards() {
	switch (game->bettingRound) {
		case 0:
			Player *player;
			for (int i=0;i<2;i++) {
				while ((player = game->table->activePlayers.next())) {
					addCardToPlayersHand(*player,game->topCardOfDeck());
				}
			}
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			break;

	}
}

void Rules::addCardToPlayersHand(Player& player, const Card& card) {
	player.hand.push_back(card);
}


