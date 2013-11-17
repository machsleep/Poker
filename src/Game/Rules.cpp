/*
 * Rules.cpp
 *
 *  Created on: Nov 16, 2013
 *      Author: machsleep
 */

#include "Rules.hpp"

void Rules::dealCards() {

	unsigned int dealer = game.getDealer()->getChairIndex();
	unsigned int nActivePlayers = game.getActivePlayers().size();
	switch (game.getBettingRound()) {
		case 0:
			// Need to deal 2 cards
			for (unsigned int k= 0; k<2 ;k++) {
				// Give each player a card
				for (unsigned int i=dealer+1;i<nActivePlayers; i++) {
					game.getPlayerAtChair(i).addCardToHand(game.topCardOfDeck());
				}
				// Give other players a card
				for (unsigned int i=0; i <= dealer; i++) {
					game.getPlayerAtChair(i).addCardToHand(game.topCardOfDeck());
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


