/*
 * main.cpp
 *
 *  Created on: Nov 10, 2013
 *      Author: machsleep
 */
#include "../Deck/Deck.hpp"
#include "../Containers/LoopList.hpp"
#include "../Player/Player.hpp"
#include "../Game/Game.hpp"


int main(int nArgs, char** arguments) {

	try {
		Game game;
		Player p1("Amanda",0,10.0,false,true,true),
		       p2("Justin",1,20.0,false,true,true),
		       p3("zach",1),
		       p4("greg",2);

		game.addPlayerToTable(p1);
		game.addPlayerToTable(p2);
		game.initialize();
		game.shuffleDeck();
		game.dealCards();
		game.listPlayers(cout);
		cout << game.getDeck();
		cout << endl;


	} catch (const char* msg) {
		cout << msg;
	}

	return 0;
}



