#pragma comment(linker, "/STACK:16777216") ///Increases Stack size
#include <bits/stdc++.h>
#include "MathLibrary.h"

using namespace std;

extern vector<int> divisors[];
extern long long sumOfDivisors[];
extern bitset<MAX_ALLOCATION_RANGE> compositeStatus;
extern bitset<MAX_ALLOCATION_RANGE> segmentCompositeStatus;

#define FAST_IO { \
    ios_base::sync_with_stdio(0);\
    cin.tie(0); cout.tie(0); cerr.tie(0);\
}

class TimerUtility {
	clock_t start = clock();
	clock_t stop = 0;
	double elapsed = 0.0;
public:
	TimerUtility() = default;

	inline void logDurationElapsed() {
		stop = clock();
		elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
		cout << "\nTotal Execution Time :: " << fixed << setprecision(8) << elapsed << " seconds" << endl;
	}
};


void testDivisorSummatoryFunction() {
	int N = 10000;
	divisorSummatoryFunction(N);
	for(int i = 1; i <= N; i++) {
		cout << "Divisors of " << i << ": ";
		for(const auto& divisor:divisors[i]) {
			cout << divisor << " ";
		}
		cout << endl;
	}
}
int main() {
	FAST_IO
	TimerUtility timerUtility;
	timerUtility.logDurationElapsed();
	return 0;
}
