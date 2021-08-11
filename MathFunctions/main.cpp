#pragma comment(linker, "/STACK:16777216") ///Increases Stack size

#include <bits/stdc++.h>
#include "MathLibrary"

using namespace std;

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

void testDivisorSummatoryFunction();

void testExtendedGcd();

void testModularDivision();

void testPowerMod();

void testSeriesSum();

int main() {
	FAST_IO
	TimerUtility timerUtility;
	timerUtility.logDurationElapsed();
	return 0;
}

void testDivisorSummatoryFunction() {
	int N = 10000;
	divisorSummatoryFunction(N);
	for (int i = 1; i <= N; i++) {
		cout << "Divisors of " << i << ": ";
		for (const auto &divisor:divisors[i]) {
			cout << divisor << " ";
		}
		cout << endl;
	}
}

void testExtendedGcd() {
	int a = 15;
	int b = 25;
	int x;
	int y;
	int gcdVal = extendedGcd<int>(a, b, x, y);
	cout << a << "*" << x << " + " << b << "*" << y << " = " << gcdVal << endl;
}

void testModularDivision() {
	int numerator = 30;
	int denominator = 3;
	int mod = 7;
	//result should be equal to (30/3) % 7 = 10 % 7 = 3
	cout << modularDivision(numerator, denominator, mod) << endl;
}

void testPowerMod() {
	int value = 5;
	int power = 3;
	int mod = 7;
	//result should be equal to (pow(5,3) % 7) = 125 % 7 = 6
	cout << powerMod<int>(value, power, mod) << endl;
}

void testSeriesSum() {
	vector<int> arithmeticProgression = {1, 4, 7, 10};  //sum = 22
	vector<int> geometricProgression = {1, 3, 9, 27};   //sum = 40
	vector<int> geometricProgression2 = {27, 9, 3, 1};  //sum = 40

	cout << seriesSum<int>(arithmeticProgression) << " "
	     << seriesSum<int>(geometricProgression) << " "
	     << seriesSum<int>(geometricProgression2) << endl;
}
