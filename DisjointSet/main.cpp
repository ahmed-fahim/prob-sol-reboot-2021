#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
private:
	int *parent;
	int totalElements;
public:
	explicit DisjointSet(int n) {
		totalElements = n;
		parent = new int[totalElements+1];
		for(int i = 0; i <= totalElements; i++) {
			parent[i] = i;
		}
	}

	int findParent(int n) {
		if(parent[n] == n) return n;
		return parent[n] = findParent(parent[n]);
	}

	void unionSets(int m, int n) {
		int parentOfM = findParent(m);
		int parentOfN = findParent(n);
		if(parentOfM != parentOfN){
			int minOfParents = min(parentOfN, parentOfM);
			parent[parentOfM] = minOfParents;
			parent[parentOfN] = minOfParents;
		}
	}

	friend ostream& operator << (ostream& coutStream, DisjointSet& disjointSet) {
		for(int i = 0 ; i <= disjointSet.totalElements; i++) {
			coutStream << i << ": " << disjointSet.findParent(i) << endl;
		}
		coutStream << endl;
		return coutStream;
	}

};

int main() {
	DisjointSet disjointSet(10);
	cout << disjointSet << endl;

	disjointSet.unionSets(1, 5);
	disjointSet.unionSets(2, 7);
	disjointSet.unionSets(1,7);

	cout << disjointSet << endl;
}
