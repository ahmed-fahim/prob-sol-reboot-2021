#include <bits/stdc++.h>

using namespace std;

#define FAST_IO { \
    ios_base::sync_with_stdio(0);\
    cin.tie(0); cout.tie(0); cerr.tie(0);\
};


int main() {
    FAST_IO

    string letters = "abcde";
    function<int(char)> charIndex = [](char c) {
        return (int) (c - 'a');
    };
    auto descendingComparator = [](const auto &first, const auto &second) {
        return first > second;
    };

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > deltaOfCharFromWords(5);

        for (int i = 0; i < n; i++) {
            fflush(stdin);
            string word;
            cin >> word;
            vector<int> charCounter(5, 0);

            for (char &c : word) {
                charCounter[charIndex(c)]++;
            }

            for (char &c : letters) {
                auto thisCharInWord = charCounter[charIndex(c)];
                auto otherCharsInWord = word.length() - thisCharInWord;
                auto deltaOfThisCharInWord = thisCharInWord - otherCharsInWord;
                deltaOfCharFromWords[charIndex(c)].emplace_back(deltaOfThisCharInWord);
            }
        }

        int maximumWordCombination = -1;
        for (char &targetChar : letters) {
            auto targetCharIndex = charIndex(targetChar);
            sort(deltaOfCharFromWords[targetCharIndex].begin(), deltaOfCharFromWords[targetCharIndex].end(), descendingComparator);

            auto wordCombinationCount = 0;
            auto deltaOfThisCharInCombinedStr = 0;

            for (auto &deltaOfThisCharFromIthWord : deltaOfCharFromWords[targetCharIndex]) {
                auto probableDeltaOfThisChar = deltaOfThisCharInCombinedStr + deltaOfThisCharFromIthWord;
                if (probableDeltaOfThisChar > 0) {
                    deltaOfThisCharInCombinedStr = probableDeltaOfThisChar;
                    wordCombinationCount++;
                }
                else {
                    break;
                }
            }
            maximumWordCombination = max(maximumWordCombination, wordCombinationCount);
        }
        cout << maximumWordCombination << endl;
    }
    return 0;
}