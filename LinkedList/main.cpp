#include <bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node *next;
	Node *prev;

	Node() {
		value = 0;
		next = nullptr;
		prev = nullptr;
	}

	explicit Node(int valueArg) : Node() {
		value = valueArg;
	}

	bool operator<(const Node &another) const {
		return this->value < another.value;
	}
};

struct LinkedList {
	Node *head;
	Node *tail;
	int length;

	LinkedList() {
		length = 0;
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;
	}

	inline void push_front(int val) {
		Node *insertionNode = new Node(val);
		Node *nextOfHead = head->next;
		head->next = insertionNode;
		insertionNode->next = nextOfHead;
		nextOfHead->prev = insertionNode;
		insertionNode->prev = head;
		length++;
	}

	inline void push_back(int val) {
		Node *insertionNode = new Node(val);
		Node *prevOfTail = tail->prev;
		tail->prev = insertionNode;
		insertionNode->prev = prevOfTail;
		prevOfTail->next = insertionNode;
		insertionNode->next = tail;
		length++;
	}

	inline void checkIfEmpty() {
		if (length == 0) {
			throw out_of_range("List is Empty");
		}
	}

	inline int pop_front() {
		checkIfEmpty();
		Node *toBeRemoved = head->next;
		int returnValue = toBeRemoved->value;
		removeNode(toBeRemoved);
		return returnValue;
	}

	inline int pop_back() {
		checkIfEmpty();
		Node *toBeRemoved = tail->prev;
		int returnValue = toBeRemoved->value;
		removeNode(toBeRemoved);
		return returnValue;
	}

	inline Node *exists(int val) {
		try {
			checkIfEmpty();
		}
		catch (exception &exc) {
			cout << exc.what() << endl;
			return nullptr;
		}
		Node *iter = head->next;
		while (iter != tail) {
			if (iter->value == val) {
				return iter;
			}
			iter = iter->next;
		}
		return nullptr;
	}

	inline void removeNode(Node *removalNode) {
		Node *prevNode = removalNode->prev;
		Node *nextNode = removalNode->next;
		prevNode->next = nextNode;
		nextNode->prev = prevNode;
		delete (removalNode);
		length--;
	}

	inline void remove(int val) {
		Node *iter = head->next;
		while (iter != tail) {
			if (iter->value == val) {
				removeNode(iter);
				break;
			}
			iter = iter->next;
		}
	}

	inline int getLength() {
		return length;
	}

	inline void print() {
		Node *iter = head->next;
		while (iter != tail) {
			if (iter != head->next) {
				cout << "->";
			}
			cout << iter->value;
			iter = iter->next;
		}
		cout << endl;
	}

	inline void reverse() {
		Node *iter = head;
		while(iter != nullptr) {
			Node* nextToIter = iter->next;
			Node* prevToIter = iter->prev;
			iter->prev = nextToIter;
			iter->next = prevToIter;
			iter = nextToIter;
		}
		iter = head;
		head = tail;
		tail = iter;
	}

	inline bool isPalindrome() {
		try {
			checkIfEmpty();
		}
		catch (exception &exc) {
			cout << exc.what() << endl;
			return false;
		}
		LinkedList stack;
		Node *iter = head->next;
		while(iter != tail) {
			stack.push_back(iter->value);
			iter = iter->next;
		}

		iter = head->next;
		while(iter != tail) {
			int stackTop = stack.pop_back();
			if(stackTop != iter->value) {
				return false;
			}
			iter = iter->next;
		}

		return stack.getLength() == 0;
	}

};

int main() {
	LinkedList linkedList;
	for(int i = 0; i < 10; i++) {
		linkedList.push_back(i);
	}
	linkedList.print();
	cout << linkedList.exists(8)->next->value << endl;
	linkedList.reverse();
	linkedList.print();
	cout << linkedList.isPalindrome() << endl;

	LinkedList linkedList2;
	linkedList2.push_back(1);
	linkedList2.print();
	cout << "isPalindrome: " << linkedList2.isPalindrome() << endl;
	linkedList2.push_back(2);
	linkedList2.print();
	cout << "isPalindrome: " << linkedList2.isPalindrome() << endl;
	linkedList2.push_back(1);
	linkedList2.print();
	cout << "isPalindrome: " << linkedList2.isPalindrome() << endl;
	return 0;
}
