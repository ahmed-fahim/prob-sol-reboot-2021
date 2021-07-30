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
        long long n;
        cin >> n;

        long long r = n % 3;
        long long q = n/3;
        long long c1 = q, c2 = q;
        if(r == 1) {
            c1++;
        }
        else if(r == 2){
            c2++;
        }
        cout << c1 << " " << c2 << endl;
    }
    return 0;
}