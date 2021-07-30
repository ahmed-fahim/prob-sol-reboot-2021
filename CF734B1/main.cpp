#include <bits/stdc++.h>
using namespace std;

#define FAST_IO { \
    ios_base::sync_with_stdio(0);\
    cin.tie(0); cout.tie(0); cerr.tie(0);\
};

int main() {
    FAST_IO
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        map<char, int> counter;

        for(char c : s) {
            counter[c]++;
        }

        int numberOfIndividuals = 0;
        int numberOfMultiples = 0;
        for (auto pair : counter) {
            if(pair.second > 1) {
                numberOfMultiples++;
            }
            else{
                numberOfIndividuals++;
            }
        }

        cout << (numberOfIndividuals/2) + numberOfMultiples <<endl;
    }
    return 0;
}