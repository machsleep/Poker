/*
 * Rules.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: machsleep
 */

#include "Rules.hpp"
#include "Game.hpp"
#include <boost/random.hpp>
#include <boost/generator_iterator.hpp>

Rules::Rules(Game& game) {
	this->game = &game;
}

Rules::~Rules() {

}

void Rules::dealCards() {
	if (game->table->getDealer() == NULL) throw "Need to initialize a dealer before you can deal cards.";
	switch (game->bettingRound) {
		case 0:
			// This is the dealer
			Player *player;
			player = &game->table->allPlayers.getCurElement();
			for (int i=0;i<2;i++) {
				while (true) {
					if (player->isActive())
						player->hand.push_back( &game->cardDeck.top() );
					player = game->table->allPlayers.nextCurElement();
					if (player == game->table->getDealer()) break;
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

// Randomly choose an active player, pass this int to the Table to set dealer
void Rules::initializeDealer() {
	unsigned int numActivePlayers = game->table->getNumberOfActivePlayers();
	typedef boost::mt19937 RNGType;
	RNGType rng;
	unsigned int time_ui = static_cast<unsigned int>( time(NULL) );
	rng.seed(time_ui);
	boost::uniform_int<> card_picker(0,numActivePlayers);
	boost::variate_generator<RNGType, boost::uniform_int<> > cardchoice(rng, card_picker);
	int dealer = cardchoice();
	game->table->setDealer(dealer);
}



