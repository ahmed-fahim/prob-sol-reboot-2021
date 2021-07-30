#include <bits/stdc++.h>

using namespace std;

#define FAST_IO { \
    ios_base::sync_with_stdio(0);\
    cin.tie(0); cout.tie(0); cerr.tie(0);\
};

///**** SOLUTION START ******///
class Solution {
private:
    const static long long int NEGATIVE_INFINITY = (-1LL * (1LL << 31)) - 1LL;
public:
    int findPeakElement(vector<int> &nums) {
        int lo = 0;
        int hi = (int) nums.size() - 1;
        int result = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            long long midIndexVal = nums[mid];
            long long leftIndexVal = (mid - 1 >= lo) ? nums[mid - 1] : NEGATIVE_INFINITY;
            long long rightIndexVal = (mid + 1 <= hi) ? nums[mid + 1] : NEGATIVE_INFINITY;

            //If midIndex has an increasing subArray from mid->left
            if (leftIndexVal > midIndexVal) {
                hi = mid - 1;
            }
                //If midIndex has an increasing subArray from mid->right
            else if (midIndexVal < rightIndexVal) {
                lo = mid + 1;
            }
                //else midIndex itself is a peak
            else {
                result = mid;
                break;
            }
        }
        return result;
    }
};
///**** SOLUTION FINISH *****///

int main() {
    FAST_IO

    vector<int> nums = {1, 3, 5, 7, 2};
    Solution solution;
    cout << solution.findPeakElement(nums) << endl;
    return 0;
}