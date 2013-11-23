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
		bool remove(T& element);
		T popFront();
		unsigned int getSize() const;
		T* getLast() const;
		T* next();

		template <typename R>
		friend ostream& operator<<(ostream& os, const LoopList<R>& ll);

		const T& operator[](unsigned int i) const;

	private:
		void updateTail();
		Node<T> *head;
		Node<T> *tail;
		Node<T> *nextElement;
		T *lastAdded;
		unsigned int size;
};

#include "LoopList.cpp"


#endif
