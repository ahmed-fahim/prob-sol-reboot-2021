//
// Created by fahim.admin on 10/8/21.
//

#include "MathLibrary.h"
using namespace std;

#define pi acos(-1.00)
#define MOD 10000007
#define eps 1e-9

vector<int> divisors[MAX_ALLOCATION_RANGE];
long long sumOfDivisors[MAX_ALLOCATION_RANGE];

bitset<MAX_ALLOCATION_RANGE> compositeStatus(0x00);
bitset<MAX_ALLOCATION_RANGE> segmentCompositeStatus(0x00);

template<typename T>
T gcd(T a, T b) {
	while (b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

template<typename T>
T lcm(T a, T b) {
	return a * (b / gcd(a, b));
}

template<typename T>
pair <T, T> getOriginator(T gcdVal, T lcmVal) {
	return (lcmVal % gcdVal == 0) ? make_pair(lcmVal, gcdVal) : make_pair(-1, -1);
}

template<typename T>
bool isPrime(T n) {
	int sq = sqrt(n);
	for (int dividend = 2; dividend <= sq; dividend++) {
		if (n % div == 0) {
			return false;
		}
	}
	return true;
}

vector<int> &sieve(const int &N, vector<int> &primes) {
	primes.clear();

	compositeStatus.set(0);
	compositeStatus.set(1);
	primes.emplace_back(2);

	for (int value = 4; value <= N; value += 2) compositeStatus.set(value);

	int sq = sqrt(N);
	for (int value = 3; value <= sq; value += 2) {
		if (!compositeStatus.test(value)) {
			primes.emplace_back(value);

			for (int multiple = value * value; multiple <= N; multiple += 2 * value) {
				compositeStatus.set(multiple);
			}
		}
	}

	//we iterate only on the odds that are > sq(N)
	if (sq % 2 == 1) sq++;

	for (int value = sq + 1; value <= N; value += 2) {
		if (!compositeStatus.test(value)) {
			primes.emplace_back(value);
		}
	}
	return primes;
}

long long leastCompositeMultipleInSegment(long long prime, long long segmentStart) {
	long long q = segmentStart / prime;
	long long multiple = q * prime;
	if (multiple < segmentStart) multiple += prime;
	return (multiple == prime) ? multiple + prime : multiple;
}


#define indexInSegment(value, segmentStart) (value-segmentStart)

vector<long long> &segmentedSieve(long long segmentStart,
                                  long long segmentEnd,
                                  vector<long long> &segmentedPrimes) {
	segmentedPrimes.clear();
	if (segmentStart <= 1) segmentStart = 2;

	int sq = sqrt(segmentEnd); //divisorOf N <= sqrt(N)

	vector<int> primes;
	primes = sieve(sq, primes);

	for (auto &prime : primes) {
		auto multiple = leastCompositeMultipleInSegment(prime, segmentStart);
		while (multiple <= segmentEnd) {
			segmentCompositeStatus.set(indexInSegment(multiple, segmentStart));
			multiple += prime;
		}
	}

	for (long long value = segmentStart; value <= segmentEnd; value++) {
		if (!segmentCompositeStatus.test(indexInSegment(value, segmentStart))) {
			segmentedPrimes.emplace_back(value);
		}
	}

	return segmentedPrimes;
}

void divisorSummatoryFunction(int N) {

	int sq = sqrt(N);
	for (int divisor = 1; divisor <= sq; divisor++) {
		for (int multiple = divisor; multiple <= N; multiple += divisor) {
			if (divisors[multiple].empty()) {
				sumOfDivisors[multiple] = divisor;
			} else {
				sumOfDivisors[multiple] += divisor;
			}

			divisors[multiple].emplace_back(divisor);

			int divisor2 = multiple / divisor;
			//collecting the divisors within range [sqrt(n), n]
			if (divisor2 > sq) {
				divisors[multiple].emplace_back(divisor2);
				sumOfDivisors[multiple] += divisor2;
			}
		}
	}
}