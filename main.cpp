/*
 * main.cpp
 *
 *  Created on: Nov 10, 2013
 *      Author: machsleep
 */
#include "src/Deck/Deck.hpp"
#include "src/Containers/LoopList.hpp"
#include "src/Player/Player.hpp"

int main(int nArgs, char** arguments) {

	try {
		Player p1("Amanda",0), p2("Justin",3), p3("zach",1), p4("greg",2);
		LoopList<Player> players;
		players.add(p1);
		players.add(p2);
		players.add(p3);
		players.add(p4);
		for (int i=0;i<5;i++)
			cout << players.popFront() << endl;;
		//players.remove(p2);
		cout << players;
		cout << flush;
	} catch (const char* msg) {
		cout << msg;
	}

	return 0;
}



