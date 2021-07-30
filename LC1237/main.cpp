#include <bits/stdc++.h>
using namespace std;

#define FAST_IO { \
    ios_base::sync_with_stdio(0);\
    cin.tie(0); cout.tie(0); cerr.tie(0);\
};

class CustomFunction {
public:
    int f(int x, int y) {
        return x + y;
    }
};

///**** Solution Start ****////
#define MAX_VALUE 1000
#define MIN_VALUE 1

class Solution {
private:
    static void addResultToSolutions(vector<vector<int> > &solutions, int x, int y) {
        solutions.push_back({x,y});
    }

    void binarySearchOn(CustomFunction &customfunction, vector<vector<int> > &solutions, int x, int key) {
        int lo = MIN_VALUE;
        int hi = MAX_VALUE;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int result = customfunction.f(x, mid);
            if (result == key) {
                addResultToSolutions(solutions, x, mid);
                break;
            }

            if (result < key) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }

public:
    vector<vector<int>> findSolution(CustomFunction &customfunction, int key) {
        vector<vector<int>> solutions;
        for (int x = MIN_VALUE; x <= MAX_VALUE; x++) {
            binarySearchOn(customfunction, solutions, x, key);
        }
        return solutions;
    }
};

///**** Solution Finish ****////

int main() {
    FAST_IO
    Solution sol;
    CustomFunction customFunction;
    vector<vector<int>> soluition = sol.findSolution(customFunction, 5);

    for(auto& pairs : soluition) {
        for(auto& x : pairs) {
            cout << x << " ";
        }
        cout << endl;
    }
}