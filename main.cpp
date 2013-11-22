/*
 * main.cpp
 *
 *  Created on: Nov 10, 2013
 *      Author: machsleep
 */
#include "src/Deck/Deck.hpp"
#include "src/Containers/LoopList.hpp"
#include "src/Player/Player.hpp"
#include "src/Game/Game.hpp"


int main(int nArgs, char** arguments) {

	try {
		Game game;

		Player p1("Amanda",0), p2("Justin",3), p3("zach",1), p4("greg",2);

		game.addPlayerToTable(p1);
		game.addPlayerToTable(p2);
		game.listPlayers(cout);
		game.listActivePlayers(cout);

	} catch (const char* msg) {
		cout << msg;
	}

	return 0;
}



