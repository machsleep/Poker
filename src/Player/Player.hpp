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
#include <ostream>

#include "../Card/Card.hpp"

class Player {
	public:
		/**
		 * Constructor for class.
		 * Clients can specify as many arguments as needed. The default values for a constructor are:
		 * name = "", chairIndex = 0, money = 0, folded, active, mucked = false.
		 * It's important to initialize a Player's state correctly for appropriate handling from other modules (e.g., Rules).
		 *
		 * <p>
		 * @param std::string name, the name of the player
		 * @param bool chair, the chair index the player is sitting at 0-9 for most games.
		 * @param bool folded, true if the player has folded, and false otherwise.
		 * @param bool active, true if the player is active at a table (not sitting out)
		 * @param bool mucked, true if a player mucks his/her cards.
		 */
		Player(std::string name="", unsigned int chair=0, double money=0, bool folded=false, bool active=false, bool mucked=false);
		Player(const Player& src);

		virtual ~Player();

		/**
		 * Returns the name of the poker player.
		 * <p>
		 * @return const std::string&, name
		 */
		virtual const std::string getName() const;

		/**
		 * Returns the money available to the poker player.
		 * <p>
		 * @return const double money, money in DOLLARS.CENTS (e.g., $14.23)
		 */
		virtual const double getMoney() const;

		/**
		 * Returns true if a player is playing in a game. A player is playing in a game
		 * if they have not folded and are active. In other words, the player can place a bet.
		 * <p>
		 * @return const bool
		 */
		virtual const bool isPlaying() const;

		/**
		 * Returns true if a player is sitting out, false otherwise. (e.g., not active)
		 * <p>
		 * @return const bool
		 */
		virtual const bool isActive() const;

		/**
		 * Returns true if a player mucked his cards
		 */
		virtual const bool doesMuck() const;
		virtual const bool isFolding() const;
		virtual const unsigned int getChairIndex() const;
		virtual const std::vector<Card> getHand() const;

		virtual bool placeBid(double bidAmount);
		virtual void addCardToHand(Card card);

		Player& operator=(const Player& src);

		friend const bool operator<(const Player& lhs, const Player& rhs);
		friend const bool operator>(const Player& lhs, const Player& rhs);
		friend const bool operator<=(const Player& lhs, const Player& rhs);
		friend const bool operator==(const Player& lhs, const Player& rhs);
		friend std::ostream& operator<<(std::ostream& os, const Player player);


	private:
		std::string name;
		std::vector<Card> hand;
		unsigned int chairIndex;
		double money;
		bool folded;
		bool active;
		bool mucked;
};

#endif /* PLAYER_HPP_ */
