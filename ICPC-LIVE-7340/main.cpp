#include <bits/stdc++.h>

using namespace std;

#define FAST_IO { \
    ios_base::sync_with_stdio(0);\
    cin.tie(0); cout.tie(0); cerr.tie(0);\
}

struct TimerUtility{
	clock_t start, stop;
	double elapsed;
	void begin() {
		start = clock();
	}

	void end() {
		stop = clock();
		elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
		cout << "Clock :: " << fixed << setprecision(8) << elapsed << endl;
	}
} timerUtility;


///**** SOLUTION START ******///
#define MAX_SIZE (int)(2e7+10)
#define MAX_INPUT_VALUE (int)2e7
long long sumOfDivisors[MAX_SIZE] = {0};
long long cumulitiveSumOfDivisors[MAX_SIZE] = {0};
void divisorSummatoryFunction(int N) {
	int sq = sqrt(N);
	for(int divisor = 1; divisor <= sq; divisor++) {
		for(int multiple = divisor; multiple <= N; multiple+=divisor) {
			sumOfDivisors[multiple]+=divisor;

			int divisor2 = multiple/divisor;
			//collecting the divisors within range [sqrt(n), n]
			if(divisor2 > sq) {
				sumOfDivisors[multiple]+=divisor2;
			}
		}
	}
}

void preCalculate(int N) {
	divisorSummatoryFunction(N);
	cumulitiveSumOfDivisors[2] = sumOfDivisors[2];
	for(int i = 3; i <= N; i++) {
		cumulitiveSumOfDivisors[i] = sumOfDivisors[i] + cumulitiveSumOfDivisors[i - 1];
	}
}

void solve() {
	preCalculate(MAX_INPUT_VALUE);
	int n;
	while(cin >> n) {
		if(n==0) {
			break;
		}
		cout << cumulitiveSumOfDivisors[n] << endl;
	}
}

///**** SOLUTION FINISH ******///

int main() {
	FAST_IO
	solve();
	return 0;
}
