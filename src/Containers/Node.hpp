/*
 * Node.hpp
 *
 *  Created on: Nov 17, 2013
 *      Author: machsleep
 */

#ifndef NODE_HPP_
#define NODE_HPP_


template <typename T>
struct Node {
	T data;
	Node<T> *nextNode;
};



#endif /* NODE_HPP_ */
