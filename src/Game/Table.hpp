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

class Table {
	public:
		Table();
		virtual ~Table();
		const LoopList<Player>* getActivePlayers() const;
		const LoopList<Player>* getPlayers() const;
		const Player* getDealer() const;
		const Player* getPlayerAtChair(int chairIdx) const;

	private:
		LoopList<Player> allPlayers;
		LoopList<Player> activePlayers;
		Player* dealer;

};

#endif /* TABLE_H_ */
