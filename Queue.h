#pragma once
#include <iostream>
#include "Stack.h"
using namespace std;

template <typename T>
struct qItem {
	qItem <T>* next;
	T data;
	qItem() {
		next = nullptr;
	}
};

template <typename T>
class Queue {
	qItem <T>* top;
	int Qsize;

public:
	Queue() {
		top = nullptr;
	}

	bool isEmpty() {
		return top == nullptr;
	}

	qItem <T>* getTop() const {
		return top;
	}

	T getTopData() const {
		return top->data;
	}

	//add item to queue
	void enqueue(T dataItem) {
		qItem<T>* newItem = new qItem<T>(dataItem);
		qItem<T>* currNode = top;
		qItem<T>* prevNode = nullptr;
		while (currNode != nullptr) {
			prevNode = currNode;
			currNode = currNode->next;
		}
		if (prevNode) {
			prevNode->next = newItem;
		}
		else {
			top = newItem;
		}
		Qsize++;
	}


	//delete item from queue
	T dequeue() {
		if (isEmpty()) {
			throw logic_error("Cannot dequeue an empty list.");
		}
		qItem<T>* toDelete = top;
		top = top->next;
		T temp = toDelete->data;
		delete toDelete;
		Qsize--;
		return temp;
	}

	void reverse() {
		Stack <T> tempStack;
		int tempsize = Qsize;
		for (int i = 0; i < tempsize; i++) {
			tempStack.push(this->dequeue());
		}
		for (int i = 0; i < tempsize; i++) {
			this->enqueue(tempStack.pop());
		}
	}


	void clear() {
		while (top != nullptr) {
			qItem<T>* toDelete = top;
			top = top->next;
			delete toDelete;
		}
		cout << "Queue cleared successfully." << endl;
		Qsize = 0;
	}

	int getLength() const {
		return Qsize;
	}

	void Display() {
		cout << "Displaying Queue..." << endl;
		qItem <T>* cursor = top;
		while (cursor) {
			cout << cursor->data << ", ";
			cursor = cursor->next;
		}
		cout << endl;
	}


};