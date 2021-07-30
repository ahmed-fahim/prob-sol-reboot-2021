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

    while (t--) {
        int n, c;
        cin >> n >> c;

        map<int, int> counter;
        map<int, vector<int> > indices;
        set<int> mixColorableNumSet;
        vector<int> result(n);

        int element;
        for (int i = 0; i < n; i++) {
            cin >> element;
            counter[element]++;
            indices[element].push_back(i);
            result[i] = 0;
        }

        int numberOfIndividuals = 0;
        for (auto pair : counter) {
            int num = pair.first;
            int count = pair.second;
            if (count > c) {
                for (int i = 0; i < c; i++) {
                    result[indices[num][i]] = i + 1;
                }
            } else {
                mixColorableNumSet.insert(num);
                numberOfIndividuals += count;
            }
        }

        int individualColorable = (numberOfIndividuals / c) * c;
        int individualColor = 0;
        while (individualColorable) {
            for (auto num : mixColorableNumSet) {
                for (int i = 0; i < indices[num].size() && individualColorable; i++, individualColorable--) {
                    result[indices[num][i]] = individualColor + 1;
                    individualColor = ((individualColor + 1) % c);
                }
            }
        }
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << (i + 1 == result.size() ? "\n" : " ");
        }
    }
    return 0;
}