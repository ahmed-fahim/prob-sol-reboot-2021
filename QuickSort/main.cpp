#include <bits/stdc++.h>
using namespace std;

#define FAST_IO() {\
	ios_base::sync_with_stdio(false);\
	cin.tie(nullptr); cout.tie(nullptr); cerr.tie(nullptr);\
}

template<typename T>
void quickSort(vector<T>& arr);

int main() {
	FAST_IO();

	vector<int> arr;
	int num = rand() % 100 + 1;
	for(int i = 0; i < num; i++) {
		arr.push_back(rand() % 10000);
	}

	for(auto& v : arr) { cout << v << " ";} cout << endl;

	quickSort<int>(arr);

	for(auto& v : arr) { cout << v << " ";} cout << endl;
	return 0;
}



template<typename T>
int findPartition(vector<T>& arr, int leftIndex, int rightIndex) {
	int l = leftIndex, r = rightIndex;
	int midIndex = (leftIndex + rightIndex)/2;
	int pivotElement = arr[midIndex];

	cout << __FUNCTION__ <<endl;
	cout << "Pivot : " << pivotElement << endl;
	for(int i = leftIndex; i <= rightIndex; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	while(leftIndex <= rightIndex) {
		cout << arr[leftIndex] << " " << arr[rightIndex] << endl;
		while(arr[leftIndex] < pivotElement) {
			leftIndex++;
		}
		while(arr[rightIndex] > pivotElement){
			rightIndex--;
		}

		if(leftIndex <= rightIndex) {
			swap(arr[leftIndex], arr[rightIndex]);
			leftIndex++;
			rightIndex--;
		}
	}
	for(int i = l; i <= r; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Partitioned at " << arr[leftIndex] << endl << endl;
	return leftIndex;
}


template<typename T>
void quickSort(vector<T>& arr, int leftIndex, int rightIndex) {
	if(leftIndex >= rightIndex) return;

	int partitionIndex = findPartition<T>(arr, leftIndex, rightIndex);
	quickSort<T>(arr, leftIndex, partitionIndex-1);
	quickSort<T>(arr, partitionIndex, rightIndex);
}

template<typename T>
void quickSort(vector<T>& arr) {
	quickSort<T>(arr, 0, arr.size()-1);
}


