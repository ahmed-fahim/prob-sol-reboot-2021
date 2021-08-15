#include <bits/stdc++.h>
using namespace std;


int powerOf2In(int value) {
	int n = value;
	int power = 0;
	while(n >= 2) {
		power++;
		n >>= 1;
	}
	n = 1 << power;
	if(n < value){
		power++;
	}
	return power;
}

#define OFFSET (int)1e4
#define LEAF_NODES (2*OFFSET + 1)
#define TOTAL_NODES 65536 /* 2^(ceil(log2(LEAF_NODES))+1) */
#define ITEMS LEAF_NODES

class SegmentTree{
private:
	int tree[TOTAL_NODES];
	int lazy[TOTAL_NODES];
	const static int rootNode = 1;
	const static int rootNodeRangeStart = 0;
	const static int rootNodeRangeEnd = ITEMS-1;

	static inline int getLeftChild(int node) { return 2 * node; }
	static inline int getRightChild(int node) {return 2 * node + 1;}
	static inline int midOfRange(int rangeStart, int rangeEnd) {return (rangeStart + rangeEnd) / 2;}
	inline void handleLazyPropagationOf(int node, int rangeStart, int rangeEnd) {
		if(lazy[node] != 0){
			tree[node] += (rangeEnd - rangeStart + 1) * lazy[node];
			if(rangeStart != rangeEnd) {
				lazy[getLeftChild(node)]+=lazy[node];
				lazy[getRightChild(node)]+=lazy[node];
			}
			lazy[node] = 0;
		}
	}
	static inline bool isNodeRangeOutOfOperatingRange(int nodeRangeStart, int nodeRangeEnd, int operationRangeStart, int operationRangeEnd) {
		return (operationRangeEnd < nodeRangeStart || nodeRangeEnd < operationRangeStart);
	}
	static inline bool isNodeRangeFullyInOperatingRange(int nodeRangeStart, int nodeRangeEnd, int operationRangeStart, int operationRangeEnd) {
		return (operationRangeStart <= nodeRangeStart && nodeRangeEnd <= operationRangeEnd);
	}

	inline int query(int node, int nodeRangeStart, int nodeRangeEnd, const int& leftIndex, const int& rightIndex) {
		handleLazyPropagationOf(node, nodeRangeStart, nodeRangeEnd);
		if(isNodeRangeOutOfOperatingRange(nodeRangeStart, nodeRangeEnd, leftIndex, rightIndex)) {
			return 0;
		}
		else if(isNodeRangeFullyInOperatingRange(nodeRangeStart, nodeRangeEnd, leftIndex, rightIndex)) {
			return tree[node];
		}
		int leftChild = getLeftChild(node);
		int rightChild = getRightChild(node);
		int nodeRangeMid = midOfRange(nodeRangeStart, nodeRangeEnd);
		int queryResultLeftChild = this->query(leftChild, nodeRangeStart, nodeRangeMid, leftIndex, rightIndex);
		int queryResultRightChild = this->query(rightChild, nodeRangeMid + 1, nodeRangeEnd, leftIndex, rightIndex);
		return queryResultLeftChild + queryResultRightChild;
	}

	inline void update(int node, int nodeRangeStart, int nodeRangeEnd, const int& leftIndex, const int& rightIndex, int value) {
		if(isNodeRangeOutOfOperatingRange(nodeRangeStart, nodeRangeEnd, leftIndex, rightIndex)) {
			return;
		}
		else if(isNodeRangeFullyInOperatingRange(nodeRangeStart, nodeRangeEnd, leftIndex, rightIndex)) {
			lazy[node]+=value;
			handleLazyPropagationOf(node, nodeRangeStart, nodeRangeEnd);
			return;
		}
		handleLazyPropagationOf(node, nodeRangeStart, nodeRangeEnd);
		int leftChild = getLeftChild(node);
		int rightChild = getRightChild(node);
		int nodeRangeMid = midOfRange(nodeRangeStart, nodeRangeEnd);
		this->update(leftChild, nodeRangeStart, nodeRangeMid, leftIndex, rightIndex, value);
		this->update(rightChild, nodeRangeMid + 1, nodeRangeEnd, leftIndex, rightIndex, value);
		tree[node] = tree[leftChild] + tree[rightChild];
	}


public:
	SegmentTree() {
		memset(tree, 0, sizeof(tree));
		memset(lazy, 0, sizeof(lazy));
	}

	inline void update(int leftIndex, int rightIndex, int value) {
		update(rootNode, rootNodeRangeStart, rootNodeRangeEnd, leftIndex, rightIndex, value);
	}

	inline int query(int leftIndex, int rightIndex) {
		return query(rootNode, rootNodeRangeStart, rootNodeRangeEnd, leftIndex, rightIndex);
	}
};

class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		SegmentTree segmentTree;
		int len = nums.size();
		vector<int> smallerCount;
		for(int i = len - 1; i >= 0; i--) {
			int valueAfterOffset = nums[i]+OFFSET;
			smallerCount.emplace_back(segmentTree.query(0, valueAfterOffset - 1));
			segmentTree.update(valueAfterOffset, valueAfterOffset, 1);
		}
		reverse(smallerCount.begin(), smallerCount.end());
		return smallerCount;
	}
};

int main() {
	Solution solution;
	vector<int> vector1({5,2,6,1});
	vector<int> results = solution.countSmaller(vector1);
	for(const auto& count : results) {
		cout << count << endl;
	}
}
