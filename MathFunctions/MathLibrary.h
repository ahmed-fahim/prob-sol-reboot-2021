//
// Created by fahim.admin on 10/8/21.
//

#ifndef MATHFUNCTIONS_MATHLIBRARY_H
#define MATHFUNCTIONS_MATHLIBRARY_H
#include <bits/stdc++.h>
#define MAX_ALLOCATION_RANGE 100005

template<typename T>
T gcd(T a, T b);
template<typename T>
T lcm(T a, T b);
template<typename T>
pair<T, T> getOriginator(T gcdVal, T lcmVal);
template<typename T>
bool isPrime(T n);

vector<int> &sieve(const int &N, vector<int> &primes);

vector<long long> &segmentedSieve(long long segmentStart,
                                  long long segmentEnd,
                                  vector<long long> &segmentedPrimes);

void divisorSummatoryFunction(int N);
#endif //MATHFUNCTIONS_MATHLIBRARY_H
