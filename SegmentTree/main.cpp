#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
	int items;
	int nodes;
	int *tree;
	int *lazy;
	const static int rootNode = 1;
	const static int rootNodeRangeStart = 0;
	int rootNodeRangeEnd;

	static inline int getLeftChild(int node) { return 2 * node; }

	static inline int getRightChild(int node) { return 2 * node + 1; }

	static inline int midOfRange(int rangeStart, int rangeEnd) { return (rangeStart + rangeEnd) / 2; }

	inline void handleLazyPropagationOf(int node, int rangeStart, int rangeEnd) {
		if (lazy[node] != 0) {
			tree[node] += (rangeEnd - rangeStart + 1) * lazy[node];
			if (rangeStart != rangeEnd) {
				lazy[getLeftChild(node)] += lazy[node];
				lazy[getRightChild(node)] += lazy[node];
			}
			lazy[node] = 0;
		}
	}

	static inline bool isNodeRangeOutOfOperatingRange(int nodeRangeStart, int nodeRangeEnd, int operationRangeStart,
	                                                  int operationRangeEnd) {
		return (operationRangeEnd < nodeRangeStart || nodeRangeEnd < operationRangeStart);
	}

	static inline bool isNodeRangeFullyInOperatingRange(int nodeRangeStart, int nodeRangeEnd, int operationRangeStart,
	                                                    int operationRangeEnd) {
		return (operationRangeStart <= nodeRangeStart && nodeRangeEnd <= operationRangeEnd);
	}

	static inline int calculateTotalNodes(int numberOfItems) {
		int numOfLeafNodes = numberOfItems;
		int power = 0;
		while (numOfLeafNodes >= 2) {
			power++;
			numOfLeafNodes >>= 1;
		}
		numOfLeafNodes = 1 << power;
		if (numOfLeafNodes < numberOfItems) {
			numOfLeafNodes << 1;
		}
		int numOfTotalNdoes = 2 * numOfLeafNodes;
		return numOfTotalNdoes;
	}

	inline void build(int node, int nodeRangeStart, int nodeRangeEnd, const vector<int> &arr) {
		if (nodeRangeStart == nodeRangeEnd) {
			tree[node] = arr[nodeRangeStart];
			lazy[node] = 0;
			return;
		}
		int leftChild = getLeftChild(node);
		int rightChild = getRightChild(node);
		int nodeRangeMid = midOfRange(nodeRangeStart, nodeRangeEnd);
		build(leftChild, nodeRangeStart, nodeRangeMid, arr);
		build(rightChild, nodeRangeMid + 1, nodeRangeEnd, arr);
		tree[node] = tree[leftChild] + tree[rightChild];
	}

	inline int query(int node, int nodeRangeStart, int nodeRangeEnd, int leftIndex, int rightIndex) {
		handleLazyPropagationOf(node, nodeRangeStart, nodeRangeEnd);
		if (isNodeRangeOutOfOperatingRange(nodeRangeStart, nodeRangeEnd, leftIndex, rightIndex)) {
			return 0;
		} else if (isNodeRangeFullyInOperatingRange(nodeRangeStart, nodeRangeEnd, leftIndex, rightIndex)) {
			return tree[node];
		}
		int leftChild = getLeftChild(node);
		int rightChild = getRightChild(node);
		int nodeRangeMid = midOfRange(nodeRangeStart, nodeRangeEnd);
		int queryResultLeftChild = query(leftChild, nodeRangeStart, nodeRangeMid, leftIndex, rightIndex);
		int queryResultRightChild = query(rightChild, nodeRangeMid + 1, nodeRangeEnd, leftIndex, rightIndex);
		return queryResultLeftChild + queryResultRightChild;
	}

	inline void update(int node, int nodeRangeStart, int nodeRangeEnd, int leftIndex, int rightIndex, int value) {
		handleLazyPropagationOf(node, nodeRangeStart, nodeRangeEnd);
		if (isNodeRangeOutOfOperatingRange(nodeRangeStart, nodeRangeEnd, leftIndex, rightIndex)) {
			return;
		} else if (isNodeRangeFullyInOperatingRange(nodeRangeStart, nodeRangeEnd, leftIndex, rightIndex)) {
			lazy[node] += value;
			handleLazyPropagationOf(node, nodeRangeStart, nodeRangeEnd);
			return;
		}
		int leftChild = getLeftChild(node);
		int rightChild = getRightChild(node);
		int nodeRangeMid = midOfRange(nodeRangeStart, nodeRangeEnd);
		update(leftChild, nodeRangeStart, nodeRangeMid, leftIndex, rightIndex, value);
		update(rightChild, nodeRangeMid + 1, nodeRangeEnd, leftIndex, rightIndex, value);
		tree[node] = tree[leftChild] + tree[rightChild];
	}

public:
	explicit SegmentTree(const vector<int> &arr) {
		items = arr.size();
		nodes = calculateTotalNodes(items);
		rootNodeRangeEnd = items - 1;
		tree = new int[nodes];
		lazy = new int[nodes];
		build(rootNode, rootNodeRangeStart, rootNodeRangeEnd, arr);
	}

	inline void update(int leftIndex, int rightIndex, int value) {
		update(rootNode, rootNodeRangeStart, rootNodeRangeEnd, leftIndex, rightIndex, value);
	}

	inline int query(int leftIndex, int rightIndex) {
		return query(rootNode, rootNodeRangeStart, rootNodeRangeEnd, leftIndex, rightIndex);
	}
};

int main() {
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
	SegmentTree segmentTree(arr);
	cout << segmentTree.query(2, 3) << endl;
	cout << segmentTree.query(2, 5) << endl;
	segmentTree.update(2, 5, 100);
	cout << segmentTree.query(2, 3) << endl;
	cout << segmentTree.query(2, 5) << endl;
}