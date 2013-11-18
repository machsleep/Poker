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

		void add(T data);
		T popFront();
		bool remove(T& element);

		size_t getSize() const;

		template <typename R>
		friend ostream& operator<<(ostream& os, const LoopList<R>& ll);

		const T& operator[](unsigned int i) const;

	private:
		void updateTail();
		Node<T> *head;
		Node<T> *tail;
		size_t size;
};

#include "LoopList.cpp"


#endif
