#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 10

#define UNDEFINED -1e7

struct CircularQueue {
	int writePointer = 0;
	int readPointer = 0;
	int allocationSize = MAX_SIZE;
	int currentSize = 0;
	int arr[MAX_SIZE];

	void push(int val) {
		if (currentSize + 1 > allocationSize) {
			return;
		}
		arr[writePointer] = val;
		currentSize++;
		writePointer = (writePointer + 1) % allocationSize;
	}

	int front() {
		if (currentSize == 0) {
			return UNDEFINED;
		}
		return arr[readPointer];
	}

	int popFront() {
		if (currentSize == 0) {
			return UNDEFINED;
		}
		int result = arr[readPointer];
		readPointer = (readPointer + 1) % allocationSize;
		currentSize--;
		return result;
	}

	bool isEmpty() {
		return currentSize == 0;
	}

	int length() {
		return currentSize;
	}

	void showQueue() {
		for (int i = 1, index = readPointer; i <= currentSize; i++) {
			cout << arr[index] << " ";
			index = (index + 1) % allocationSize;
		}
		cout << endl;
	}

};

int main() {
	std::cout << "Hello, World!" << std::endl;

	CircularQueue circularQueue;

	for(int i=0; i < 20; i++) {
		circularQueue.push(i);
		circularQueue.showQueue();
	}

	int currentSize = circularQueue.length();

	while(circularQueue.length() > currentSize/2) {
		cout << "Removing " << circularQueue.popFront() << endl;
		circularQueue.showQueue();
	}

	for(int i=0; i < 20; i++) {
		circularQueue.push(i);
		circularQueue.showQueue();
	}

	return 0;
}
