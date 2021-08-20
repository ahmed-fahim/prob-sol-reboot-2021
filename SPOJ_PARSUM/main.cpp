#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
private:
	vector<int> tree;
	vector<int> lazy;
	int rootNode = 1;
	int rootNodeLeftRange;
	int rootNodeRightRange;

public:
	explicit SegmentTree(vector<int>& arr) {
		int n = arr.size();
		rootNodeLeftRange = 1;
		rootNodeRightRange = n-1;

		n++;
		tree.resize(4*n);
		lazy.resize(4*n);
		build(rootNode, rootNodeLeftRange, rootNodeRightRange, arr);
	}

	void update(int uL, int uR, int val) {
		update(rootNode, rootNodeLeftRange, rootNodeRightRange, uL, uR, val);
	}

	int query(int qL, int qR) {
		return query(rootNode, rootNodeLeftRange, rootNodeRightRange, qL, qR);
	}

private:
	static inline int getLeft(int node) { return 2* node;}
	static inline int getRight(int node) {return getLeft(node) + 1;}
	static inline int midOfRange(int l, int r) { return (l+r)/2;}

	void handleLazy(int node, int l, int r) {
		if(lazy[node] != 0) {
			tree[node] += lazy[node];

			if(l != r) {
				lazy[getLeft(node)] += lazy[node];
				lazy[getRight(node)] += lazy[node];
			}
			lazy[node] = 0;
		}
	}

	void build(int node, int l, int r, vector<int>& arr){
		if(l == r) {
			tree[node] = arr[l];
			lazy[node] = 0;
			return;
		}
		int mid = midOfRange(l,r);
		int leftNode = getLeft(node);
		int rightNode = getRight(node);

		build(leftNode, l, mid, arr);
		build(rightNode, mid+1, r, arr);
		tree[node] = min(tree[leftNode], tree[rightNode]);
	}

	inline void update(int node, int l, int r, int qL, int qR, int val) {
		handleLazy(node, l, r);
		if(qR < l || r < qL) return;
		if(qL <= l && r <= qR) {
			lazy[node] += val;
			handleLazy(node, l, r);
			return;
		}
		int mid = midOfRange(l,r);
		int leftNode = getLeft(node);
		int rightNode = getRight(node);

		update(leftNode, l, mid, qL, qR, val);
		update(rightNode, mid+1, r, qL, qR, val);
		tree[node] = min(tree[leftNode], tree[rightNode]);
	}

	inline int query(int node, int l, int r, int uL, int uR) {
		handleLazy(node, l, r);
		if(uR < l || r < uL) return INT_MAX;
		if(uL <= l && r <= uR) {
			return tree[node];
		}
		int mid = midOfRange(l,r);
		int leftNode = getLeft(node);
		int rightNode = getRight(node);

		int leftTreeResult = query(leftNode, l, mid, uL, uR);
		int rightTreeResult = query(rightNode, mid+1, r, uL, uR);
		return min(leftTreeResult, rightTreeResult);
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr); cerr.tie(nullptr);

	int n;
	while(cin >> n) {
		if(n == 0) {
			break;
		}

		vector<int> cumulativeSum(2*n + 1, 0);
		for(int i=1; i <= n; i++) {
			cin >> cumulativeSum[i];
			if(i != 1) {
				cumulativeSum[i] += cumulativeSum[i-1];
			}
		}

		for(int i = n+1; i <= 2*n; i++) {
			cumulativeSum[i] = cumulativeSum[n];
		}

		int sum = 0;

		SegmentTree segmentTree(cumulativeSum);

		for(int startIndex = 1; startIndex <= n; startIndex++) {
			int endIndex = startIndex + n - 1;

			int minimumCumilitiveSumInRange = segmentTree.query(startIndex, endIndex);
			if(minimumCumilitiveSumInRange >= 0) {
				sum++;
			}

			int cumSumDifferenceWithPrevElement = cumulativeSum[startIndex] - cumulativeSum[startIndex - 1];

			//shift the whole range by the difference
			segmentTree.update(startIndex, endIndex, -cumSumDifferenceWithPrevElement);
		}

		cout << sum << endl;
	}
}