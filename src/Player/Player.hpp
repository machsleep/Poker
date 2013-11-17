/*
 * Player.hpp
 *
 *  Created on: Nov 11, 2013
 *      Author: machsleep
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <string>
#include <vector>

#include "../Card/Card.hpp"

class Player {
	public:
		Player(std::string name="", unsigned int chair=0, double money=0, bool folded=false, bool active=false, bool mucked=false);
		virtual ~Player();
		virtual const std::string& getName() const;
		virtual const double getMoney() const;
		virtual const bool isPlaying() const;
		virtual const bool isSittingOut() const;
		virtual const bool doesMuck() const;
		virtual const bool isFolding() const;
		virtual void addCardToHand(Card card);
		virtual const unsigned int& getChairIndex() const;
		virtual bool placeBid(double bidAmount);
	private:
		std::string name;
		std::vector<Card> hand;
		unsigned int chairIndex;
		// US dollar.cents
		double money;
		bool folded;
		bool active;
		bool mucked;
};

#endif /* PLAYER_HPP_ */
