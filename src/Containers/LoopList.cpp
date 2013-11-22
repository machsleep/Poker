#ifndef LOOPLIST_CPP_
#define LOOPLIST_CPP_

#include <ostream>
#include <iostream>
#include "LoopList.hpp"

using std::ostream;
using std::cout;

template <typename T>
LoopList<T>::LoopList() {
	head = NULL;
	tail = NULL;
	nextElement = NULL;
	size = 0;
}

template <typename T>
LoopList<T>::LoopList(const LoopList<T>& src) {
	if (src.getSize() == 0) {
		head = tail = nextElement = NULL;
		size = 0;
		return;
	}
	// Otherwise elements to copy
	Node<T> *newNode = new Node<T>;
	const Node<T> *ptrToCpyHead = src.getHead();
	head = newNode;
	newNode->data = ptrToCpyHead->data;
	newNode->nextNode = ptrToCpyHead->nextNode;
	Node<T> *cur;
	for (cur = ptrToCpyHead->nextNode; cur != head; cur = cur->nextNode) {
		Node<T> *newNode = new Node<T>;
		newNode->data = cur->data;
		newNode->nextNode = cur->nextNode;
	}
	tail = cur;
	size = src.getSize();
	next = head;
}

template <typename T>
const Node<T>* LoopList<T>::getHead() {
	return head;
}

template <typename T>
LoopList<T>::~LoopList(){
	Node<T> *tmp;
	for (unsigned int i=0;i<size;i++) {
		tmp = head->nextNode;
		delete head;
		head = tmp;
	}
	tail = NULL;
	head = NULL;
	size = 0;
}

template <typename T>
T LoopList<T>::popFront() {
	if (size == 0) throw "Can't popFront an element from an empty LoopList.";
	Node<T>* tmp = head;
	head = tmp->nextNode;
	tail->nextNode = head;
	nextElement = head;
	size--;
	T data = tmp->data;
	delete tmp;
	return data;
}

template <typename T>
bool LoopList<T>::remove(T& element) {
	if (size == 0) throw "Can't remove an element from an empty LoopList.";
	if (head->data > element || tail->data < element) throw "Element not found.";
	Node<T> *cur = head;
	if (head->data == element) {
		popFront();
		return true;
	} else {
		for (unsigned int i=1; i <size; i++) {
			if (cur->nextNode->data == element) {
				Node<T> *tmp  = cur->nextNode;
				cur->nextNode = tmp->nextNode;
				delete tmp;
				size--;
				return true;
			}
			cur = cur->nextNode;
		}
	}
	return false;
}


template <typename T>
unsigned int LoopList<T>::getSize() const {
	return size;
}

template <typename T>
ostream& operator<<(ostream& os, const LoopList<T>& ll) {
	Node<T> *hdcpy = ll.head;
	for (unsigned int i=0; i<ll.getSize(); i++) {
		os << hdcpy->data << " ";
		hdcpy = hdcpy->nextNode;
	}
	return os;
}

template <typename T>
T* LoopList<T>::next() {
	if (size == 0) throw "Can't call next for a zero size LoopList.";
	T *dat;
	if (nextElement && nextElement->nextNode != head) {
		dat = &nextElement->data;
		nextElement = nextElement->nextNode;
		return dat;
	} else if(nextElement) {
		T* dat = &nextElement->data;
		nextElement = NULL;
		return dat;
	} else {
		nextElement = head;
		return NULL;
	}
}

template <typename T>
void LoopList<T>::add(T data) {
	Node<T> *node = new Node<T>();
	node->data = data;
	Node<T> *cur = head;
	if (head == NULL) {
		head = node;
		head->nextNode = head;
	} else if (head->nextNode == head) {
		head->nextNode = node;
		node->nextNode = head;
		head = (head->data < data) ? head : node;
	} else {
		while (true) {
			if (cur->data <= data && data <= cur->nextNode->data) {
				node->nextNode = cur->nextNode;
				cur->nextNode = node;
				break;
			} else if (cur->nextNode == head) {
				node->nextNode = head;
				cur->nextNode = node;
				if (data < head->data) {
					head = node;
				}
				break;
			}
			cur = cur->nextNode;
		}
	}
	updateTail();
	nextElement = head;
	size++;
}

template <typename T>
void LoopList<T>::updateTail() {
	Node<T> *cur = head;
	while (cur->nextNode != head) cur = cur->nextNode;
	tail = cur;
}

template <typename T>
const T& LoopList<T>::operator[](unsigned int i) const {
	if (size <= i) throw "Accessed element out of index";
	Node<T> *cur=head;
	for (unsigned int k=0;k<i;k++)
		cur=cur->nextNode;
	return cur->data;
}

#endif
