/*
 * Table.h
 *
 *  Created on: Nov 17, 2013
 *      Author: machsleep
 */

#ifndef TABLE_H_
#define TABLE_H_

#include "../Containers/LoopList.hpp"
#include "../Player/Player.hpp"

class Game;

class Table {
	public:
		Table(Game& game);
		virtual ~Table();
		LoopList<Player>& getPlayers();
		Player* getDealer() const;
		unsigned int getNumberOfActivePlayers();
		void setDealer(unsigned int activePlayerIndex);
		const Player& getPlayerAtChair(int chairIdx) const;
		void addPlayer(Player& player);
		friend class Rules;

	private:
		Game *game;
		LoopList<Player> allPlayers;
		unsigned int numActivePlayers;
		Player* dealer;

};

#endif /* TABLE_H_ */
