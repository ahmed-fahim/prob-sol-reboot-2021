#include <bits/stdc++.h>
using namespace std;

#define FAST_IO { \
    ios_base::sync_with_stdio(0);\
    cin.tie(0); cout.tie(0); cerr.tie(0);\
};

///***** Solution Start *****///
class Solution {
private:
    int findColumnIndexOfRowMaxima(vector<vector<int> >& mat, int rowIndex) {
        int index = -1;
        int maxElement = -1;
        vector<int>& row = mat[rowIndex];
        for(int i = 0; i < row.size(); i++) {
            if(row[i] > maxElement) {
                maxElement = row[i];
                index = i;
            }
        }
        return index;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int loRow = 0;
        int hiRow = (int) mat.size() - 1;
        vector<int> result = {0,0};
        while(loRow <= hiRow) {
            int midRow = loRow + (hiRow - loRow)/2;
            int columnIndexOfRowMaxima = findColumnIndexOfRowMaxima(mat, midRow);

            int midRowMaxima = mat[midRow][columnIndexOfRowMaxima];
            int upperRowElement = (midRow-1 >= loRow) ? mat[midRow-1][columnIndexOfRowMaxima] : -1;
            int lowerRowElement = (midRow+1 <= hiRow) ? mat[midRow+1][columnIndexOfRowMaxima] : -1;

            if(upperRowElement > midRowMaxima) {
                hiRow = midRow - 1;
            }
            else if(midRowMaxima < lowerRowElement) {
                loRow = midRow + 1;
            }
            else {
                result = {midRow, columnIndexOfRowMaxima};
                break;
            }
        }
        return result;
    }
};

///***** Solution Finish *****///

int main() {
    FAST_IO
    return 0;
}