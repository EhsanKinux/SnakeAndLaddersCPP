#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Item {
	Item <T>* prevNode;
	T data;
	Item() {
		prevNode = nullptr;
	}
};

template <typename T>
class Stack {
	Item <T>* top;

public:
	Stack() {
		top = nullptr;
	}

	void push(T dataItem) {
		Item<T>* newItem = new Item<T>(dataItem);
		newItem->prevNode = top;
		top = newItem;
	}

	T getTop() {
		return top->data;
	}

	bool isEmpty() {
		return top == nullptr;
	}

	T pop() {
	//Throw an error in isEmpty().
		if (isEmpty()) {
			throw std::invalid_argument("ERROR: Stack is empty.");
		}
		T data = top->data;
		Item<T>* toDelete = top;
		top = top->prevNode;
		delete toDelete;
		return data;
	}

	void clearStack() {
		while (top != nullptr) {
			Item<T>* toDelete = top;
			top = top->prevNode;
			delete toDelete;
		}
		cout << "Stack cleared successfully." << endl;
	}

	void Display() {
		cout << "Displaying Stack..." << endl << endl;
		Item <T>* cursor = top;
		while (cursor) {
			cout << cursor->data << ", " << endl;
			cursor = cursor->prevNode;
		}
		cout << endl << endl;
		cout << "That's it." << endl;
	}

};
