///Fahim Ahmed :: Dhaka Residential Model College
#pragma comment(linker, "/STACK:16777216") ///Increases Stack size
#include <bits/stdtr1c++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//
//using namespace __gnu_pbds;
///// A red-black tree table storing ints and their order
///// statistics. Note that since the tree uses
///// tree_order_statistics_node_update as its update policy, then it
///// includes its methods by_order and order_of_key.
//typedef
//tree<
//  int,
//  null_type,
//  less<int>,
//  rb_tree_tag,
//  // This policy updates nodes' metadata for order statistics.
//  tree_order_statistics_node_update>
//set_t; ///works like set but keeps order
///*
//    extra methods:
//    set_t.find_by_order(order);
//    set_t.order_of_key(key);
//*/
#define li long long int
#define ui unsigned long long int
///I/O functions BEGIN
#define rfile(a) freopen(a, "r", stdin)
#define wfile(a) freopen(a, "w", stdout)
/*
#String input method with cin
1. To input a string with space
    char buff[MAX_BUFFER_SIZE];
    cin.getline(buff, sizeof(buff));
    string compositeStatus(buff);

2. To input a string without space
    char buff[MAX_BUFFER_SIZE];
    cin>>buff;
    string compositeStatus(buff);

3. To input a string terminated by comma only
    char buff[MAX_BUFFER_SIZE];
    cin.getline(bugg,sizeof(buff), ',');
    string compositeStatus(buff);
*/

/*
Floating point precision with cout.

to get a precision of 6 point decimals,
cout<<setprecision(6)<<fixed<<variable<<endl;

equivalent to => printf("%.6lf\n",variable)

*/
#define pi acos(-1.00)
#define pb push_back
#define mp make_pair
#define Pr printf
#define For(i,a,b) for(int i = a; i < b; i++)
#define MOD 1000003
#define eps 1e-9
#define pii pair<int,int>


typedef long long int ll;

///Index of contents:
/*
01. GCD,LCM,Bitwise operation
02. SIMPLE ITERATIVE GCD
03. Super Efficient GCD
04. GCD of 2 numbers where one of them is bigint
05. Siv Prime Generator to generate primes between 1 to 10^7
06. ALL DIVISORS, NOD of a range, SOD of a range:
07. SUM of SOD from i to j; O(sqrt(n) * log2(n))
08. SUM_of_sum_of_proper_divisors of a range 2 to n (PROPER DIVISORS)
09. SUM_OF_sum_of_all_divisors of a range of 2 to n
10. Prime factorization of a single integer, O((sqrt(n)/(logn))+(logn))
11. NUMBER OF DIVISOR OF A SINGLE INTEGER:/// (NOD)
12. SUM OF DIVISOR OF A SINGLE INTEGER: ///SOD
13. Highly Composite Numbers (HCN)
14. Extended Euclidean Algorithm
15. Linear Diophantine Solution
16. Dual_positive_diophantince_soln
17. Power mod
18. BigMOD algorithm of (a^p) % mod
19. BIGMOD version 2
20. BigInt Remainder
21. Last Digit of n^k
22. Inverse Modulus
23. Generic Modulus; deals with negative cases
24. Digits of factorial, Digits of Factorial Division
25. Leading Digit of a factorial : RANGE
26. Leading Digit of a factorial : factorial(n) : Single Number
27. Maximum value of a point decimal number s after doing at most t round-ups
28. Fast Fibonacci
29. PRIME FACTORIAZATION OF n! , factorial(n)
30. EULER SIEVE PHI/ RANGED COPRIME COUNTER:
31. EULER PHI/SINGLE INPUT COPRIME COUNTER
32. Function to count prime factors of all numbers from 1 to n
33. SUM OF DIVISOR OF A SINGLE INTEGER N
34. N digit number that is divisible by d
35. Pair of integers whose gcd is G and LCM is L
36. Given N integers, and you are told to output a value closest to M;
    where M is divisible by each N integers
37. number of integer (m)'s, where 1<=m<=n and gcd(m,n) != 1 && gcd(m,n) != m
38. Sorting numbers of a range 1 to N on the basis of each individual's total prime factor (prime factor shonkha er upore vitti kore)
39. CHINESE REMAINDER THEOREM BLOCK
40. Huge MOD... (2^(2^n)+1) % K algorithm; You have to calculate the function F(n, k) = (2^(2^n) + 1)%K
41. Zellers algorithm begin :: Weakday of a date algorithm
42. Check if N= (even*odd) is possible
43. In between 1 to N how many square free numbers are there [who are not divisible by any k^2 where k>=2]
44. Mobius Function
45. Extreme GCD (Given N<=10^4 numbers, how many ways can you select 4 numbers such that their gcd is 1)
46. NO GCD (Given N<=10^4 numbers, who are all squarefree, and who don't have primefactor > 50 find the number of pairs for whom gcd = 1 or a prime)
47. LuckySIV() :: lucky number - a number with at least 3 distinct prime factors. 60 = 2*2*3*5 is a lucky number because it has 2,3,5 = 3 distinct primes
48. isprime(long long n):: checks whether a value n is prime or not in sqrt(n) complexity
*/

template <typename t1> t1 gcd(t1 a, t1 b) {while(b != 0 ){a=a%b;a = a^b;b = b^a;a = a^b;}return a;}
template <typename t1> t1 lcm(t1 a, t1 b) { return a * (b / gcd(a, b)); }
template <typename t1> bool check (t1 i, t1 k){return i&((t1)1<<k);}
template <typename t1> t1 On(t1 i, t1 k) { return i|((t1)1 << k);}
template <typename t1> t1 Off(t1 i, t1 k) {return (i-((check(i,k))<<k) );}

///SIMPLE ITERATIVE GCD///
/*
template <typename t1> t1 iter_gcd ( t1 a, t1 b ) {
    while ( b != 0 ) {
        a = a % b;
        a = a^b;b = b^a;a = a^b;
    }
    return a;
}
*/



///Super Efficient GCD///
////Function to implement Stein's Algorithm
//int gcd(int a, int b)
//{
//    /* GCD(0, b) == b; GCD(a,0) == a, GCD(0,0) == 0 */
//    if (a == 0)
//        return b;
//    if (b == 0)
//        return a;
//
//    /*Finding K, where K is the greatest power of 2
//      that divides both a and b. */
//    int k;
//    for (k = 0; ((a | b) & 1) == 0; ++k)
//    {
//        a >>= 1;
//        b >>= 1;
//    }
//
//    /* Dividing a by 2 until a becomes odd */
//    while ((a & 1) == 0)
//        a >>= 1;
//
//    /* From here on, 'a' is always odd. */
//    do
//    {
//        /* If b is even, remove all factor of 2 in b */
//        while ((b & 1) == 0)
//            b >>= 1;
//
//        /* Now a and b are both odd. Swap if necessary
//           so a <= b, then set b = b - a (which is even).*/
//        if (a > b)
//            swap(a, b);   // Swap u and v.
//
//        b = (b - a);
//    }   while (b != 0);
//
//    /* restore common factors of 2 */
//    return a << k;
//}
/// ***********************************************************///


///GCD of 2 numbers where one of them is bigint
// Here 'a' is integer and 'b' is string.
// The idea is to make the second number (represented
// as b) less than and equal to first number by
// calculating its mod with first integer number
// using basic mathematics
//#define BigInteger string
//template <typename t1> t1 BigInteger_remainder(BigInteger x, t1 m){
//    t1 remainder=0;
//    for(t1 i = 0; i < x.length();i++)
//    {
//        /getting the digit in integer format from character format
//        t1 digit = x[i]-'0';
//        remainder = (remainder*(t1)10+digit)%m;
//    }
//    return remainder;
//}
//template <typename t1> t1 bigGCD(BigInteger number1, t1 number2)
//{
//    t1 number = number2;
//    t1 remainder=BigInteger_remainder(number1,number2);
//    while(remainder != 0)
//    {
//        number = number % remainder;
//        swap(number,remainder);
//    }
//    /this is the GCD
//    return number;
//}

/// ***********************************************************///

///Siv Prime Generator to generate primes between 1 to 10^7
///Prime Number Theorem: upper bound of primes in between n = N/ln(N)
//int primes[10000000];
//int pr_ctr = 0;
//bitset<10000010> compositeStatus(0);
//void siv(int n=10000000)
//{
//    compositeStatus.set(0, 1);
//    compositeStatus.set(1, 1);
//    primes[pr_ctr++] = 2;
//    for(int i = 4; i <= n; i+=2)
//    {
//        compositeStatus.set(i, 1);
//    }
//    int sqn = sqrt(n);
//    for(int i = 3; i <= sqn ; i+=2)
//    {
//        if(compositeStatus.test(i) == 0)
//        {
//            for(int j = i*i; j <= n; j+=2*i)
//            {
//                compositeStatus.set(j, 1);
//            }
//        }
//    }
//    for(int i = 3; i <= n; i+=2)
//    {
//        if(compositeStatus.test(i) == 0)primes[pr_ctr++]=i;
//    }
//}
//
//bitset<10000000+10> segmentCompositeStatus(0x00);
//vector<long long> segmentedPrimes;
//void segmentedSiv(long long a, long long b) {
//	int sq = sqrt(b);
//	siv(sq);
//
//	auto ensureValInRange = [a](long long val) {
//		long long mult = (a/val) * val;
//		if(mult < a) mult += val;
//		if(mult == val) mult += val;
//		return mult;
//	};
//	auto indexFromValue = [a](long long val){return val-a;};
//
//	if(a <= 1) segmentCompositeStatus.set(indexFromValue(1));
//
//	int pr_index = 0;
//	while(pr_index < pr_ctr) {
//		long long val = ensureValInRange(primes[pr_index]);
//		cout << primes[pr_index] << " " << val << endl;
//		while(val <= b) {
//			segmentCompositeStatus.set(indexFromValue(val));
//			val += primes[pr_index];
//		}
//		pr_index++;
//	}
//
//	segmentedPrimes.clear();
//	for(long long val = a; val <= b; val++) {
//		if(!segmentCompositeStatus.test(indexFromValue(val))){
//			segmentedPrimes.push_back(val);
//		}
//	}
//}
/// ***********************************************************///

///ALL DIVISORS, NOD of a range, SOD of a range:
//int mark[100002];
//vector<int> divisors[20000002];
//int Number_of_divisors[20000002] = {0}; ///NOD
//int Sum_of_divisors[20000002] = {0}; ///SOD
//void all_divisors(int n)
//{
//    int i,j,k;
//    int sq = sqrt(n);
//    for(i = 1; i <= sq; i++)
//    {
//        for(j = i; j <= n; j+=i)
//        {
//            divisors[j].push_back(i);
//            Number_of_divisors[j]++;
//            Sum_of_divisors[j]+=i;
//
//            k = j/i;
//            if(k > sq)
//            {
//                divisors[j].push_back(k);
//                Number_of_divisors[j]++;
//                Sum_of_divisors[j]+=k;
//            }
//        }
//    }
//}
/// ***********************************************************///


///SUM of SOD from i to j; O(sqrt(n) * log2(n))
///SUM OF MAX_LCM = SUM_OF_SOD
///This is suitable if  10^4 <= testcase <= 10^5 and timelimit >= 3 seconds
//li cumulitive_sum[20000001];
//void SUM_of_SOD(int start, int fin)
//{
//    all_divisors(fin);
//    cumulitive_sum[start] = Sum_of_divisors[start];
//    for(int i = start+1; i <= fin; i++)
//    {
//       {cumulitive_sum[i] = cumulitive_sum[i-1] + Sum_of_divisors[i];}
//    }
//}
/// ***********************************************************///


///SUM_of_sum_of_proper_divisors of a range 2 to n (PROPER DIVISORS)
///Caution: This doesn't calcualte the SSOPD of subproblems
/// O(sqrt(n))
//li sum_of_SOPD(li n)
//{
//    li ans=0;
//    for(li i=2;i*i<=n;i++)
//    {
//        li j=n/i;
//        ans+=(i+j)*(j-i+1)/2;
//        ans+=i*(j-i);
//    }
//    return ans;
//}
/// ***********************************************************///


///SUM_OF_sum_of_all_divisors of a range of 2 to n
///Suitable when O(testcase*sqrt(n)) <= 10^6
//li sum_of_SOD(li n)
//{
//    //sum of all proper divisors between [2,n]
//    li SSOPD = sum_of_SOPD(n);
//
//    //adding 1 for all [2,n] numbers. since 1 is not a proper divisor
//    //careful to notice we're adding for only 2 to n, hence we're adding (n-1)
//    li SSOD = SSOPD + (n-1);
//
//    //adding all i 's for (2<=i<=n);
//    //as i was not a proper divisor of the number i itself
//    ///which means adding (2 + 3 + .... +n)
//    ///                 = (1 + 2 + 3+ .... + n) - 1
//    ///                 = [(n*(n+1))/2)] - 1
//    SSOD+=((n*(n+1))/2)-1;
//    return SSOD;
//}
/// ***********************************************************///



///Prime factorization of a single integer, O((sqrt(n)/(logn))+(logn))
//vector<int> factors;
//void factorize( int n )
//{
//	int sqrtn = sqrt ( n ) ;
//	for ( int i = 0; i < pr_ctr && primes[i] <= sqrtn; i++ )
//	{
//		if ( n % primes[i] == 0 )
//		{
//			while ( n % primes[i] == 0 )
//			{
//				n /= primes[i] ;
//				factors.push_back(primes[i]) ;
//			}
//			sqrtn = sqrt ( n ) ;
//		}
//	}
//	if ( n != 1 )
//	{
//		factors. push_back(n) ;
//	}
//}
//
////factors would contain the prime factorization of the integer n
////in practical case the complexity can be counted as O(sqrt(n)+logn)
/*
Additional Info on this:
1. to factorize n, you need integers only upto floor(sqrt(n))
*/

/// ***********************************************************///


///NUMBER OF DIVISOR OF A SINGLE INTEGER:/// (NOD)
///UPPER BOUND FOR NOD(n) = [2 x n^(1/3)]
//
//int NOD ( int n )
//{
//    int sqrtn = sqrt ( n );
//    int res = 1;
//    for ( int i = 0; i < pr_ctr && primes[i] <= sqrtn; i++ ) {
//        if ( n % primes[i] == 0 ) {
//            int p = 0; /*Counter for power of prime*/
//            while ( n % primes[i] == 0 ) {
//                n /= primes[i];
//                p++;
//            }
//            sqrtn = sqrt ( n );
//            p++;/*Increase it by one at end*/
//            res *= p; /*Multiply with answer*/
//        }
//    }
//    if ( n != 1 ) {
//        res *= 2; /*Remaining prime has power p^1. So multiply with 2*/
//    }
//    return res;
//}
/// ***********************************************************///

///SUM OF DIVISOR OF A SINGLE INTEGER: ///SOD
///if N = p1^a1 * p2^a2;
///then SOD(N) = (p1^0 + p1^1 + p1^2 + ... + p1^a1) x (p2^0 + p2^1 + p2^2 + .... + p2^a2)
//int SOD( int n )
//{
//	int sum_of_divisors = 0;
//	int sqrtn = sqrt (n) ;
//	for ( int i = 0; i < pr_ctr && primes[i] <= sqrtn; i++ )
//	{
//		if ( n % primes[i] == 0 )
//		{
//			int primesum = 1;
//			int p_mul=1; //serves as pi^0, pi^1,...,pi^ai
//			while ( n % primes[i] == 0 )
//			{
//				n /= prime[i] ;
//				p_mul*=prime[i];
//				primesum+=p_mul;
//			}
//			sqrtn = sqrt ( n ) ;
//			sum_of_divisors*= primesum;
//		}
//	}
//	if ( n != 1 )
//	{
//		int primesum = 1 + n;
//		sum_of_divisors*=primesum;
//	}
//	return sum_of_divisors;
//}
/// ***********************************************************///

///Highly Composite Numbers (HCN)
/*
HCN numbers have got some properties.
Firstly, shob HCN er prime factorization e consecutive primes paowa jabe.
Secondly, Prime gular power non decreasing order e thakbe.
mane 2*3*7 emon kono HCN thakbe na kokhono... jehetu prime 5 missing.
ar 2*3^2 eita o HCN hobe na, karon eikhane prime er power increasing order e
but 2^2*3 eita HCN, cause, consecutive primes and prime er power non increasing order

#Primorials = factorials of primes. primorial(3) = 2 * 3 * 5.
//factorial of first 3 primes
HCN are simply factors of Primorials, where it is a must that
HCN = primorial(a)*primorial(b) hoile a >= b

primorial(10)
= factors of first 10 primes
= 2 *3 * 5 * 7 * 11 * 13 * 17 * 19 * 23 * 29
= 6469693230
= 6.46.. x 10^9.
hence any HCN <= 10^9 would contain only the first 9 primes.
all the HCN's in between 10^9 would be compositions of different primorials
where only availabe primorials are:
primorial(1) = 2,
primorial(2) = 2*3
primorial(3) = 2*3*5
primorial(4) = 2*3*5*7
primorial(5) = 2*3*5*7*11
primorial(6) = 2*3*5*7*11*13
primorial(7) = 2*3*5*7*11*13*17
primorial(8) = 2*3*5*7*11*13*17*19
primorial(9) = 2*3*5*7*11*13*17*19*23
*/

////prime[] is a list of prime.
//int prime_for_HCN[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
//int HCN_resNum, HCN_resDiv, n_limit_HCN;
//map<int,int> HCN;
//void HCN_recursion ( int pos, int limit, long long num, int div )
//{
//    if ( div > HCN_resDiv ) { //Get the number with highest NOD
//        HCN_resNum = num;
//        HCN_resDiv = div;
//    }
//    else if ( div == HCN_resDiv && num < HCN_resNum ) //In case of tie, take smaller number
//    {
//        HCN_resNum = num;
//    }
//    if(!HCN[div])
//    {
//        HCN[div] = num;
//    }
//    else{
//        HCN[div] = min((int)num, HCN[div]);
//    }
//    if ( pos == 9 ) return; //End of prime list
//
//    long long p = prime_for_HCN[pos];
//
//    for ( int i = 1; i <= limit; i++ )
//    {
//        if ( num * p > n_limit_HCN ) break;
//
//        HCN_recursion ( pos + 1, i, num * p, div * ( i + 1 ) );
//        //running a HCN_recursionsion to product the next prime with num*p,
//        //where limit of the next primes would be i at most;
//
//        p *= prime_for_HCN[pos];
//        //2 would become 2^2, 3 would become 3^2 ;
//        //if num was equal to 2^3, then now it will have the chance to become 2^3 * 3^2
//    }
//}
//void HCN_generator(int n)
//{
//    n_limit_HCN = n;
//    HCN_resNum = 0;
//    HCN_resDiv = 0;
//    HCN_recursion ( 0, 30, 1, 1 );
//    //0th prime that can have a max power of 30.
//
////    printf ( "%d %d\n", HCN_resNum, HCN_resDiv );
//
//    map<int,int> :: iterator it,itfin,it2;
//    itfin = HCN.end();
//    itfin--;
//    for(it = HCN.begin(); it != itfin;it++)
//    {
//        it2 = it;
//        it2++;
//        for(;it2 != HCN.end();it2++)
//        {
//            if(it->second> it2->second)
//            {
//                it2 = it;
//                it--;
//                HCN.erase(it2);
//                break;
//            }
//        }
//    }
////    for(it = HCN.begin(); it != HCN.end(); it++)
////    {
////        cout<<it->second<< " "<< it->first<<endl;
////    }
//}
/// ***********************************************************///

///Extended Euclidean Algorithm
///it finds the solution (x,y) for Ax + By = gcd(A,B); returns gcd(A,B)
///remember if A = 4 and B = -2 it will find solution for 4x -2y = -2
///if you want to find it the solution for 4x - 2y = 2, use the custom_mod function
///if you want to find the soln for Ax + By = N; then use Linear Diophantine Soln
///The first set of solutions will be output of ext_gcd();
///for next set of solutions use the for next set of solutions()
//template <typename t1> t1 ext_gcd ( t1 A, t1 B, t1 *X, t1 *Y )
//{
//    t1 x2, y2, x1, y1, x, y, r2, r1, q, r;
//    x2 = 1; y2 = 0;
//    x1 = 0; y1 = 1;
//    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
//        q = r2 / r1;
//        r = r2 % r1;
//        x = x2 - (q * x1);
//        y = y2 - (q * y1);
//    }
//    *X = x2; *Y = y2;
//    return r2;
//}
//template <typename t1> void next_kth_egcd_soln(t1 goshagu, t1 A, t1 B,t1 *X, t1 *Y, double k)
//{
//    *X+=k*(B/goshagu);
//    *Y-=k*(A/goshagu);
//}

///Linear Diophantine Solution
///For an equation of Ax + By = C; if any possible solution exists for (x,y)
///it would return them, regardless of their sign
//template <typename t1> t1 linearDiophantine ( t1 A, t1 B, t1 C, t1 *x, t1 *y )
//{
//    t1 g = gcd ( A, B );
//    if ( C % g != 0 ) return -1; //No Solution
//
//    t1 a = A / g, b = B / g, c = C / g;
//    g=ext_gcd( a, b, x, y ); //Solve ax + by = 1
//    if ( g < 0 ) { //Make Sure gcd(a,b) = 1
//        a *= -1; b *= -1; c *= -1;
//    }
//
//    *x *= c; *y *= c; //ax + by = c
//    return g; //Solution Exists
//}
/// ***********************************************************///

///Dual_positive_diophantince_soln
///if you only want possible solution (x,y)where
///Ax + By <= C such that Ax + By is the maximum possible value within C
///then use the following dual_positive_diophantince_solution()
//template <typename t1> void dual_positive_diophantince_soln(t1 A, t1 B, t1 C, t1 *X, t1 *Y)
//{
//    t1 g = gcd(A,B);
//    A/=g;
//    B/=g;
//    C/=g;
//    bool swapped=0;
//    if(A < B)
//    {
//        A = A ^ B;
//        B = A ^ B;
//        A = A ^ B;
//        swapped=1;
//    }
//    //We’re searching linearly upto sqrt(n) at most [when a=b]
//    //For every value from i = 0 to sqrt(n); we’ll assign x = i,
//    //Then we’ll find the y corresponding to that x… and we’ll see
//    //the value of (c’ = ax + by) for those value of x and y
//    //the max value of c’ will always be less or equal to c because
//    //we found y using the equation
//    //if z = by then, ax + z = c
//    //so z = c-ax
//    //so y = floor(z/b)
//    //hence y*b <= z
//    //hence ax + by <= c
//    t1 lim = min(C/A,B);
//    t1 max_found = -1;
//    t1 x,y;
//    for(x = 0; x <= lim; x++)
//    {
//        y=(C-A*x)/B;
//        //if z = BY then, AX + z = C
//        //so z = C-AX
//        //so Y = floor(z/B) = floor((C-AX)/B)
//        //hence BY <= z
//        //hence AX + BY <= C
//        t1 C_prime = A*x + B*y;
////        cout<<*x<<" "<<*y<<" "<<C_prime<<endl;
//        if(C_prime > max_found)
//        {
//            max_found=C_prime;
//            *X=x;
//            *Y=y;
//        }
//    }
//    if(swapped)
//    {
//        *X = *X ^ *Y;
//        *Y = *X ^ *Y;
//        *X = *X ^ *Y;
//    }
//}
/// ***********************************************************///

///In case of more variables, linear diophantine eqn:
///Find all positive integer solutions to 43x + 7y + 17z = 400
/*
//To solve this type of problem, we simply choose, one at a time, all
//the possible values for one of the unknowns; for each of those values
//we get a diophantine equation with two unknowns, which we then solve
//using standard methods for diophantine equations.
//
//I will help get you started on this process, in case you are not
//familiar with those standard techniques.
//
//Because the coefficient on x is the largest of the three coefficients,
//the number of possible values for x is less than for the other
//unknowns. Because of this, we will have fewer cases to consider if we
//start our solution by considering the different possible values of x.
//43*9 is less than 400 and 43*10 is greater than 400, so the range of
//values we need to consider for x is from 1 to 9.
//
//I will just pick one of these 9 cases; each one is solved in a manner
//similar to what I will show for that one case.
//
//The case I will work through is the case where x=3.  Given x=3, our
//equation is
//
//  43(3)+7y+17z = 400
//  129+7y+17z = 400
//  7y+17z = 271
//
//Now for a demonstration of the standard method for solving
//diophantine equations....look for the above function
*/
/// ***********************************************************///

///Power mod
//li power_mod(li a, li x, li p)
//{
//	li res = 1;
//	while(x>0) {
//		if(x & 1) res = (res*a) % p;
//		a=(a*a)%p;
//		x >>= 1;
//	}
//
//	return res;
//}
/// ***********************************************************///

///BigMOD algorithm of (a^p) % mod
//#define MOD 1000000007
//
//
///* algorithm of (a^p) % m */
//long long int BigMod(long long int a, long long int P, long long int M)
//{
//    /* (a^0) % m = 1 */
//    if(P==0)
//    {
//        return 1LL%MOD;
//    }
//
//    /* a^8 = a^4 * a^4 => hence (a^8) % m = (((a^4)%m) * ((a^4) % m)) % m */
//    if(P%2==0)
//    {
//        long long ret  = (BigMod(a, P/2LL,M)%M);
//        return (ret * ret) % M;
//    }
//
//    /*(a^9) % m = (a^8 * a)%m = ((a^8)%m * (a)%m) % m*/
//    else
//    {
//        return (BigMod(a,P-1,M) * (a % M)) % M;
//    }
//
//}
/// ***********************************************************///

///*BIGMOD version 2*/
//li bigmod_2(li a, li b)
//{
//    if(b == 0) return (long long)1 % MOD;
//    li x = bigmod_2(a, b/(long long)2);
//    x = (x * x)%MOD;
//    if(b % 2 == 1)x = (x * a) % MOD;
//    return x;
//}


///BigInt Remainder
//li bigint_remainder(string integer, li mod)
//{
//        li res = 0;
//        if(integer[0] >= '0' && integer[0] <= '9')
//        {
//            for(int i = 0; i < integer.size(); i++)
//            {
//                res = (res*10 + (integer[i] -  48)) % mod;
//            }
//        }
//        else{
//            for(int i = 1; i < integer.size(); i++)
//            {
//                res = (res*10 + (integer[i] -  48)) % mod;
//            }
//        }
//        return res;
////        if(res == 0)
////        {
////            printf("Case %d: divisible\n", t);
////        }
////        else{
////            printf("Case %d: not divisible\n", t);
////        }
//}
/// ***********************************************************///

///Last Digit of n^k
//li last_digit_of_n_k(li n, li k)
//{
//        if(k == 0)
//        {
//            return 1;
//        }
//        lastdig = n%10;cur = lastdig;
//        li m =(li) (k-1)/4;
//        m = 4*m + 1;
//
//        li trns;
//        if(m != 1) trns = (k%m);
//        else trns = k-1;
//        for(li i = 1; i <= trns; i++)
//        {
//            cur = cur*lastdig;
//            cur%=10;
//        }
//        return cur;
//}
/// ***********************************************************///

///Inverse Modulus
///*(X^-1)%MOD = inverse_modulus( (X % MOD), MOD)% MOD*/
///(X^-1)%MOD = (X^(MOD-2))%MOD
//li inverse_modulus(li a, li b)
//{
//	li b0 = b, t, q;
//	li x0 = 0, x1 = 1;
//	if (b == 1) return 1;
//	while (a > 1) {
//		q = a / b;
//		t = b, b = a % b, a = t;
//		t = x0, x0 = x1 - q * x0, x1 = t;
//	}
//	if (x1 < 0) x1 += b0;
//	return x1;
//}
/// ***********************************************************///

///Generic Modulus; deals with negative cases
//template <typename t1> t1 generic_mod(t1 a, t1 b)
//{
//    if(a*b >= 0 && b != 0 )return a%b;
//    t1 q = a/b;
//    t1 m = a%b;
//    if(m == 0) return 0;
//    else{
//        q--;
//        b*=(-1*q);
//        m = b+a;
//        return m;
//    }
//}
/// ***********************************************************///

///Digits of factorial, Digits of Factorial Division
////fact_digits will have the actual digits of factorial
////fact_digits_float will have the floating point value of the log10 value
//int fact_digits[100006];
//double fact_digit_float[100006];
//void factorialDigit (int n)
//{
//	double x = 0;
//	int res;
//	for(int i = 1; i <= n; i++)
//	{
//        x+=log10(i);
//        fact_digit_float[i] = x; //required value for digits of factorial division
//        res = ((int) x) + 1;
//        fact_digits[i] = res;
//	}
//}
/// ***********************************************************///

/// Leading Digit of a factorial : RANGE
///This will store the leading first k digit of (factorial 1 to factorial(n))
//int lead[100001];
//void leadingDigitFact(int n)
//{
//	double fact = 0;
//	double q,B;
//	for(int i = 1; i <=n; i++)
//	{
//		fact+=log10(i);
//		q = fact - floor(fact + eps);
//		B = pow(10,q);
//    ///Shift decimal point k-1 times
//    for ( int i = 0; i < k - 1; i++ )
//    {
//        B *= 10;
//    }
//    lead[i] = floor(B+eps);//storing the first k digits of factorial(i)
//	}
//}
/// ***********************************************************///

///Leading Digit of a factorial : factorial(n) : Single Number
///Find the first K digits of N!
//int leadingDigitFact ( int n, int k ) {
//    double fact = 0;
//
//    ///Find log(N!)
//    for ( int i = 1; i <= n; i++ ) {
//        fact += log10 ( i );
//    }
//
//    ///Find the value of q
//    double q = fact - floor ( fact+eps );
//
//    double B = pow ( 10, q );
//
//    ///Shift decimal point k-1 times
//    for ( int i = 0; i < k - 1; i++ ) {
//        B *= 10;
//    }
//
//    ///Don't forget to floor it
//    return floor(B+eps);
//}
/// ***********************************************************///

///Maximum value of a point decimal number s after doing at most t round-ups
//string max_round_up(int n, int t, string s)
//{
//	int i,z=0;
//	int point_index=-1;
//
//	//let's suppose s = 99.44395656
//	for(i=0;i<n;i++)if(s[i]=='.')
//    {
//        //i stops at 3, as s[3] = '.'
//        point_index = i;
//        break;
//    }
//	for(i=point_index+1;i<n;i++)
//    {
//        //i stops at 6, as s[6] = '9' is the first digit from left after '.' that is >= '5'
//        if(s[i]>'5')break;
//    }
//
//	if(i<n) //if we found a point and a digit after point
//    {
//        //while we have turn > 0 and while ith digit >= 5
//		for(;t&&s[i] >= '5';i--,t--)
//        {
//            //if the next to i is not a '.' then we are adding 1 to that value
//            //it is guaranted that the next i-1th digit < 5;
//            //because we stopped searching after we found the first digit that is >=5
//            if(s[i-1] != '.')
//            {
//                s[i-1]++;
//            }
//            //if the next digit is a '.' then we are adding 1 to the digit next to the dot.
//			else if(s[i-1]=='.')
//			{
//			    s[i-2]++;
//			    //and turning z = 1 ;means that we are keeping a marker to work on the
//			    //integer part of the number later.
//			    //for example, in this case 99.4439, if we add 1 to s[1] that is next to s[2] = '.'
//			    //it will not result in a digit, hence we'll have to do that checking later.
//			    //also if we have already added 1 to the integer part then no matter how much turn t is left,
//			    //it is of no work to rounding up any more
//			    z=1;
//                break;
//            }
//        }
//
//    }
//    //means there was no point decimal found
//    //so we are simply decrementing i to return the original string
//    else
//    {
//        i--;
//    }
//
//	if(z != 0) //that means addition was done to integer portion
//	{
//	    bool carry = 0;
//        for(i = point_index-1; i > 0; i--)
//        {
//            if(s[i] > '9') //this is so that 09 would turn 10
//            {
//                s[i-1]++;
//                s[i]=0;
//            }
//            else break;
//        }
//        if(s[0] > '9')
//        {
//            s[0] = '0';
//            s.insert(s.begin(), '1'); //in case of 99 we're inserting a 1 to the left
//            point_index++;//every previous index would shift 1 to the right
//            n++;
//        }
//        //as 1 was added to the integer part,
//        //that means 99.59 was turned to 100, so no need to print anything after '.'
//        return s.substr(0,point_index);
//	}
//	else {
//        //we're making a substring from 0 to ith, total length i+1
//	    return s.substr(0,i+1);
//    }
//}
/// ***********************************************************///

///Fast Fibonacci
//const li P = 1000000007;
///* Fast  ibonacci using cache */
//li fib (li n)
//{
//    static std::unordered_map<li,li> cache;
//
//    if (cache.find(n) == cache.end())
//    {
//        li f;
//        if (n==0)
//            f = 0;
//        else if (n < 3)
//            f = 1;
//        else if (n % 2 == 0)
//        {
//            li k = n/2;
//            f = (fib(k) * (2*fib(k+1) – fib(k))) % P;
//        }
//        else
//        {
//            li k = (n-1)/2;
//            f = (fib(k+1)*fib(k+1)+ fib(k) * fib(k)) % P;
//        }
//        if (f<0)
//            f += P;
//
//        cache[n] = f;
//    }
//    return cache.at(n);
//}
////Driver Code
////    cout<<fib(10)<<endl;
/// ***********************************************************///

///PRIME FACTORIAZATION OF n!
/////*MUST HAVE SIV WRITTEN ABOVE THIS*/
//void factFactorize ( int n )
//{
//    int cntr = 0;
//    for ( int i = 0; i < pr_ctr && primes[i] <= n; i++ )
//    {
//        int x = n;
//        int freq = 0;
//
//        while ( x / primes[i] ) {
//            freq += x / primes[i];
//            x = x / primes[i];
//        }
//        if(freq == 0)continue;
//
//        cntr++;
//        if(cntr > 1) printf(" *");
//        printf (" %d (%d)", primes[i], freq );
//    }
//    printf("\n");
//}
/// ***********************************************************///

///EULER SIEVE PHI/ RANGED COPRIME COUNTER:
///complexity O(nlogn)
////MUST HAVE SIV WRITTEN ABOVE THIS
//ui phi[5000001];
//bitset<5000001> mark(0);
//
//void sievephi(int n)
//{
//    int i,j;
//    for(i = 1; i <= n; i++)
//    {
//        phi[i]=i;
//    }
//
//    mark.set(1,1);
//    phi[1] = 1;
//    for(i = 2; i <= n; i+=2)
//    {
//        if( i != 2)mark[i]=1;
//        phi[i]/=2;
//    }
//
//    for(i = 3; i <= n; i+=2)
//    {
//        if(mark[i]==0)
//        {
//            phi[i]--;
//
//            for(j = 2*i; j <= n; j+=i)
//            {
//                mark.set(j,1);
//                phi[j] = phi[j]/i * (i-1);
//            }
//        }
//    }
//}
/// ***********************************************************///

///EULER PHI/SINGLE INPUT COPRIME COUNTER
///complexity O(sqrt(n))
//li eulerPhi(li n)
//{
//    li res = n;
//    li sqrtn = sqrt(n);
//    for(int i = 0; i < pr_ctr && primes[i] <= sqrtn; i++)
//    {
//        if(n % primes[i] == 0)
//        {
//            while(n % primes[i] == 0)
//            {
//                n/=primes[i];
//            }
//            sqrtn = sqrt(n);
//            res/=primes[i];
//            res*=(primes[i]-1);
//        }
//    }
//    if(n != 1)
//    {
//        res/=n;
//        res*=(n-1);
//    }
//    return res;
//}
/*
additional info:
1. jodi testcase*sqrt(n) <= 10^6; only taile eita use korba. n holo worst case e n
*/
/// ***********************************************************///

///Function to count prime factors of all numbers from 1 to n
///O(nloglog(n))
//int factor_ctr[2000001];
//int pr_ctr = 0;
//pair<int,int> arr[2000001];
//
//void siv_factorize()
//{
//    int n = 2000000;
//    for(int i = 2; i <= n; i++)
//    {
//        if(factor_ctr[i] == 0)
//        {
//            factor_ctr[i] = 1;
//            //proves that 'i' is a prime, so it's only prime factor is itself
//            for(int j = i << 1; j <= n; j+=i)//(i << 1) = 2*i
//            {
//                int p = j;
//                int freq = 0;
//                while(p % i == 0)
//                {
//                    p/=i;
//                    freq++;
//                }
//                factor_ctr[j]+=freq;
//                //adding how many times i (the prime) is in j;
//            }
//        }
//    }
//    factor_ctr[1] = 0; //1 has no prime factors
//    for(int i = 1; i <= n; i++)
//    {
//        arr[i] = make_pair(factor_ctr[i],i);
//        //storing each number with it's prime_factor counts
//        //for sorting factor_ctr is the primary key
//        //number itself is the secondary key
//    }
//    sort(arr+1, arr+n+1); //sorting the numbers on basis of the keys
//}
/// ***********************************************************///

///SUM OF DIVISOR OF A SINGLE INTEGER N
///# It is to be noted:
///Maximum sum of LCM of N = sum of divisors of N
//
//# if 12 = (3^1)*(2^2) or (2^a)*(3^b) then
//SUM OF DIVISOR(12) = (2^0+2^1+2^2)*(3^0+3^1)
//		    = (2^0+2^1+………+2^a)*(3^0+…………+3^b)
//CODE***********************
//int SOD( int n )
//{
//	int sum_of_divisors = 0;
//	int sqrtn = sqrt (n) ;
//	for ( int i = 0; i < pr_ctr && primes[i] <= sqrtn; i++ )
//	{
//		if ( n % primes[i] == 0 )
//		{
//			int primesum = 1;
//			int p_mul=1;
//			while ( n % primes[i] == 0 )
//			{
//				n /= prime[i] ;
//				p_mul*=prime[i];
//				primesum+=p_mul;
//			}
//			sqrtn = sqrt ( n ) ;
//			sum_of_divisors*= primesum;
//		}
//	}
//	if ( n != 1 )
//	{
//		int primesum = 1 + n;
//		sum_of_divisors*=primesum;
//	}
//	return sum_of_divisors;
//}
/// ***********************************************************///

///N digit number that is divisible by d
//string n_dig_divisible_by_d(int N, string d)
//{
//    int len = d.length();
//    if(len > N)
//    {
//        string s = "No solution";
//        return s;
//    }
//    else{
//        int left = N-len;
//        ostringstream ss;
//        ss<<d;
//        for(int i = 1; i <= left; i++)
//        {
//            ss<<"0"; //simply adding 0's to the end means multiplying them by powers of 10
//                    //k*10^m would always be divisible by k
//        }
//        return ss.str();
//    }
//}
/// ***********************************************************///

///Pair of integers whose gcd is G and LCM is L
//pair<int,int> pair_gcd_lcm(int G, int L)
//{
//    int a, b;
//    a = G;
//    //gcd(a,b) * lcm(a,b) = a*b
//    //if lcm % gcd != 0, that means no a,b exists such that (a*b) = G * L
//    //if L % G == 0 ; that means G*L = a*b
//    //we can simply put a = G, b = L (we could swap a,b, but given condition is a<=b)
//    if ( L % G != 0 ) {
//        return make_pair(-1,-1);
//    }
//    b = L;
//    return make_pair(a,b);
//}
/// ***********************************************************///

///Given N integers, and you are told to output a value closest to M;
///which can be constructed using each of the N integers
/*
with N integers, the minimum value you can construct,
which will be constructable by every one of them is their lcm.
for example, 1,3,5,6. what is the minimum value that can be constructed by every one of them?
Of course, it is the minimum value that is divisible by each one of them, which is 30 in this case.
now if LCM is strictly greater than M, then LCM is the answer.
if LCM is < M, than we'll have to find div = M/LCM, hence, div*L will be the answer.
if such case occurs that abs(M - div*L) < abs(M - (div+1)*L) then (div+1)*L will be the answer
*/
/// ***********************************************************///

///Number of integer (m)'s, where [(1<=m<=n) and (gcd(m,n) != 1) && (gcd(m,n) != m)]
///Complexity (sqrt(n))*2
//int function_num_m_gcd(int n)
//{
//    ///there must be a siv() call from main, where the limit should be sqrt(n)where, n @ worst case
//    return n - (eulerPhi(n) + NOD(n)) + 1;
//}
/// ***********************************************************///


///Sorting numbers of a range 1 to N on the basis of each individual's total prime factor
///Function to count prime factors of all numbers from 1 to n
///O(nloglog(n))
//int factor_ctr[2000001];
//int pr_ctr_f = 0;
//pair<int,int> arr[2000001];
//
//void siv_factorize()
//{
//    int n = 2000000;
//    for(int i = 2; i <= n; i++)
//    {
//        if(factor_ctr[i] == 0)
//        {
//            factor_ctr[i] = 1;
//            //proves that 'i' is a prime, so it's only prime factor is itself
//            for(int j = i << 1; j <= n; j+=i)// (i << 1) = 2*i
//            {
//                int p = j;
//                int freq = 0;
//                while(p % i == 0)
//                {
//                    p/=i;
//                    freq++;
//                }
//                factor_ctr[j]+=freq;
//                //adding how many times i (the prime) is in j;
//            }
//        }
//    }
//    factor_ctr[1] = 0; //1 has no prime factors
//    for(int i = 1; i <= n; i++)
//    {
//        arr[i] = make_pair(factor_ctr[i],i);
//        //storing each number with it's prime_factor counts
//        //for sorting factor_ctr is the primary key
//        //number itself is the secondary key
//    }
//    sort(arr+1, arr+n+1); //sorting the numbers on basis of the keys
//}
/// ***********************************************************///

///CHINESE REMAINDER THEOREM BLOCK
//// returns g = gcd(a, b); finds x, y such that d = ax + by
//ll extended_euclid(ll a, ll b, ll &x, ll &y) {
//    ll xx = y = 0;
//    ll yy = x = 1;
//    while (b) {
//        ll q = a / b;
//        ll t = b; b = a%b; a = t;
//        t = xx; xx = x - q*xx; x = t;
//        t = yy; yy = y - q*yy; y = t;
//    }
//    return a;
//}
//// return a % b (positive value)
//ll mod(ll a, ll b) {
//    return ((a%b) + b) % b;
//}
//// Chinese remainder theorem (special case): find z such that
//// z % m1 = r1, z % m2 = r2.  Here, z is unique modulo M = lcm(m1, m2).
//// Return (z, M).  On failure, M = -1.
//pair<int,int> chinese_remainder_theorem(li m1, li r1, li m2, li r2) {
//    li s, t;
//    li g = extended_euclid(m1, m2, s, t);
//    if (r1%g != r2%g) return make_pair(0LL, -1LL);
//    return make_pair(mod(s*r2*m1 + t*r1*m2, m1*m2) / g, m1*m2 / g);
//}

///Huge MOD... (2^(2^n)+1) % K algorithm
//li huge_mod(li n, li k)
//{
//    sievephi(1000000); ///n was upto 10^10, save to calculate upto sqrt(n)*logn
//    if(__gcd(2LL,k)==1) ///if k is odd
//    {
//        ll ans=BigMod(2,n,phi[k]);
//        ans=(BigMod(2,ans,k)+1)%k;
//        return ans;
//    }
//    int k1=k,c=0;
//    while(k%2==0)
//        k/=2,c++;
//    int m1=k1/k,m2=k;
//    int r2=BigMod(2,n,phi[k]);
//    r2=(BigMod(2,r2,k)+1)%k;
//    int r1;
//    k1=k1/k;
//    if(n>=5)
//        r1=0;
//    else
//        r1=BigMod(2,BigMod(2,n,100),k1);
//    r1=(r1+1)%k1;
//    //cout<<m1<<" "<<r1<<" "<<m2<<" "<<r2<<endl;
//    return chinese_remainder_theorem(m1,r1,m2,r2).first;
//}


///Zellers algorithm begin
///:: Weakday of a date algorithm
//map<int,string> day_table;
//int m_table[13];
//map<string,int> d_table;
//
//
//int leapyeartest(int a)
//{
//    if(a % 4 == 0)
//    {
//        if(a % 100 == 0)
//        {
//            if(a % 400 == 0)
//            {
//                return 1;
//            }
//
//            else{return 0;}
//        }
//        else{
//                return 1;
//        }
//    }
//
//    else{
//        return 0;
//    }
//
//}
//
//string weekday_calculator(int d, int m, int y)
//{
//    int year,century,month,day;
//    day=d;
//    month = m_table[m];
//
//    if(month > 10)y--;
//
//    year=generic_mod(y,100);
//    century=y/100;
//
//    int weekday = generic_mod(((13 * month - 1) / 5 + year / 4 + century / 4 + day + year - 2 * century) , 7);
//    //cout<<weekday<<endl;
//    return day_table[weekday];
//}
//void initiate_zellers_calender()
//{
//    m_table[1]=11;
//    m_table[2]=12;
//    for(int i=3;i<=12;i++)m_table[i]=i-2;
//
//    day_table[0]="Sunday" ;
//    day_table[1]= "Monday";
//    day_table[2]= "Tuesday";
//    day_table[3]= "Wednesday";
//    day_table[4]= "Thursday" ;
//    day_table[5]= "Friday";
//    day_table[6]= "Saturday";
//
//
//    d_table["Sunday"]=0;
//    d_table["Monday"]=1;
//    d_table["Tuesday"]=2;
//    d_table["Wednesday"]=3;
//    d_table["Thursday"]=4;
//    d_table["Friday"]=5;
//    d_table["Saturday"]=6;
//}

///zellers algorithm end
///*********************************************************************************************///


///Check if N=even*odd is possible
/*
    1. a number n would have one even and one odd divisor iff it is an even number itself.
        cause even*odd = even

        Hence eliminate all the numbers that are odd.they can't have an odd and even divisor

    2. now if a number is even, it still may not have an odd divisor, if it is in a for of 2^k.
    hence check
        if 2^k=n
        => k = log2(n); and test if 2^k == n or not. if yes, eliminate this case as well.

    3. If n survives the above 2 cases, then obviously n has an even and odd divisor.
        so start from the lowest even, 2
        take even=2; hence rest=n/2;
        unless (rest == even) keep doing (rest=rest/2,even=even*2)
        or;
        while(rest %2 != 1)
        {rest/=2,even*=2;}

    4. Be careful here as, they don't approve 1 as an answer for even.
*/
///*********************************************************************************************///


///In between 1 to N how many square free numbers are there [who are not divisible by any k^2 where k>=2]
///sqfree(n) = for(i=1 to sqrt(N)){sum of (mu[i]*(N/i^2))} //mu(i) hosse Mobius_Function of i
///alternate solution O(sqrt(n)) : solution technique : Inclusion Exclusion
//li squares[2000001];
//int sq_ctr=0;
//int m;
//li res=0;
//void prime_square_generator(li n)
//{
//    li sqr = sqrt(n);
//    sq_ctr=0;
//
//    /*
//    for(li i=1; i<=sqr; i++)
//    {
//        squares[sq_ctr++]=i*i;
//    }
//    */
//    ///this would be the usual way. But non prime er power niye laav nai,
//    ///as eventually the lcm()s would break down into prime factors
//    ///so amra khali prime er power gula nibo
//
//    siv(sqr);
//    for(li i=0; i<pr_ctr; i++)
//    {
//        squares[sq_ctr++]=primes[i]*primes[i];
//    }
//    m=sq_ctr;
//}

//
//void sq_free(int cur, li product_b4, int counter) ///counter means, subset e koyta element ase
//{
//    if(product_b4 > n)
//        return;
//
//    if(counter % 2 == 0)
//        res+=(n/product_b4);
//    else
//        res-=(n/product_b4);
//
//    for (int it=current_index; it < m,it+=1){
//        v = product_b4*squares[it];
//        if(v > n)
//            break;
//        sq_free(it+1, v, counter+1);
//    }
//}
///***********************************************************************************************************


///Mobius Function mu(x)
/*
Mobius Function

mu(x) != 0 if x is a square free number. onnovabe bola jay x er prime factorization e kono prime 2 bar nai. karon kono prime 2 bar thakar manei to oi prime er square diye x divisible
      = 1 if x is 1
      = (-1)^k if x has k distinct primes in its prime factor
      = 0 means x is not squarefree

*/
//short int mu[10001];
//int Lim;
//
//void gen(int val, int cur, int counter)
//{
//    if(mu[val] != 0)return;
//    if(counter % 2==0)mu[val]=1;
//    else mu[val]=-1;
//
//    for(int i=cur; i < pr_ctr; i++)
//    {
//        int newval=val*primes[i];
//        if(newval <= Lim)gen(newval, i+1, counter+1);
//        else break;
//    }
//}
//void generate_mobius(int n)
//{
//    memset(mu,0,sizeof(mu));
//    siv(n);
//    Lim = n;
//    mu[1]=1;
//    int val=1;
//    for(int i=0; i < pr_ctr; i++)
//    {
//        gen(val*primes[i], i+1, 1);
//    }
//
//}
///*******************************************************************************


///Extreme GCD (Given N<=10^4 numbers, how many ways can you select 4 numbers such that their gcd is 1)
///solution technique : Inclusion Exclusion
/*
    multiples[10001] ekta array rakho
    suppose given list 2 4 6 1
    1 er divisor gular multiples e 1 kore add koro
    2 er divisor gular multiples e 1 kore add koro
    4 er divisor gular multiples e 1 kore add koro
    6 er divisor gular multiples e 1 kore add koro

    so
    multiples er list
    [1]=4
    [2]=3
    [3]=1
    [4]=1
    [5]=0
    [6]=1

    now first e dhori je shob combination er e gcd 1. hence total option 4c4


    4c4 - mult[2]c4 - mult[3]c4 - ..... + lcm(mult[2],mult[3])c4.... - lcm(mult[2],mult[3], mult[4]) ... as long lcm()Cr > 0

    https://v...content-available-to-author-only...e.net/status/#un=&OJId=LightOJ&probNum=1161&res=0&orderBy=run_id&language=


*/
///******************************************************************

/// number of pairs for whom gcd = 1 or a prime, where N <= 10^5 numbers are given, and no prime factor is > 50
///and all the numbers of the N numbers are square free.
/*
    in between 1 and 50, the number of primes are 15.
    so total distinct numbers in between 1 to




*/
///******************************************************************

///Caution points
/*
1. I need to divide N with lcm of 3 numbers a,b,c. a,b,c <= 10^9
    if(a*b > N)we don't need to continue

*/
///*************************

///LuckySIV() :: lucky number - a number with at least 3 distinct prime factors.
///60 = 2*2*3*5 is a lucky number because it has 2,3,5 = 3 distinct primes
//int prime_factors[100001], lucky[100001];
//int lucky_ctr=0;
//void luckySiv(int n = 10000)
//{
//    ///initializing that no number has any prime factors yet
//    for(int i=0;i<=n;i++){prime_factors[i]=0;}
//
//    for(int i=0; i <= n; i++)
//    {
//        ///if i has no prime factor yet, means its a prime itself
//        if(prime_factors[i]==0)
//        {
//            prime_factors[i]=1; ///i has only 1 factor, itself
//
//            ///mark all of its multipliers as non prime by decreasing -1.
//            ///is something has prime_factors[i]=-2, that means it has been decreamented
//            ///by 2 primes. that means it has 2 distinct prime factors.
//
//            for(int j=2; j*i <= n; j++)
//            {
//                int product=j*i;
//                prime_factors[product]-=1;
//
//                ///we're only adding the number to list
//                ///when it finds its 3rd distinct factor.
//                ///it may get 4th, 5th .. factors later
//                ///but they won't be added then because
//                ///it was already added at the time of third.
//                if(prime_factors[product] == -3)
//                {
//                    lucky[lucky_ctr++]=product;
//                }
//            }
//        }
//    }
//    sort(lucky,lucky+lucky_ctr);
//}

///isprime(long long n):: checks whether a value n is prime or not in sqrt(n) complexity
//bool isprime(long long n)
//{
//    if(n==1 or (n%2==0 and n!=2)){
//        return 0;
//    }
//    long long sq=(long long)sqrt((double)n);
//    for(long long i=2;i<=sq;i++){
//        if(n%i==0){
//            return 0;
//        }
//    }
//    return 1;
//}
///********************************************************************

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
};

int main()
{
	FAST_IO
}
