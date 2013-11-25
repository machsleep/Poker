#ifndef LOOPLIST_H_
#define LOOPLIST_H_
#include <cstddef>
#include <iostream>

#include "Node.hpp"

using namespace std;

template <typename T>
class LoopList {
	public:
		LoopList();
		LoopList(const LoopList<T>& cpy);
		virtual ~LoopList();

		const Node<T>* getHead();

		void add(T& data);
		/**
		 * Resets the curElement to head
		 */
		void reset();
		/**
		 * Removes an element from the loop list by address
		 */
		bool remove(T& element);
		/**
		 * Pops an element off the from of the list, adjusts size, and fixes pointers.
		 */
		T popFront();
		/**
		 * Returns the number of elements currently in the looplist.
		 */
		unsigned int getSize() const;
		T* getLast() const;
		T* next();
		T& getCurElement();

		/**
		 * Moves the curElement pointer by one, and returns the data at destination.
		 */
		T* nextCurElement();
		void setCurElement(T& data);

		template <typename R>
		friend ostream& operator<<(ostream& os, const LoopList<R>& ll);
		const T& operator[](unsigned int i) const;




	private:
		void updateTail();
		Node<T> *head;
		Node<T> *tail;
		Node<T> *curElement;
		T *lastAdded;
		unsigned int size;
};

#include "LoopList.cpp"


#endif
