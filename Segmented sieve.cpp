#include<bits/stdc++.h>
using namespace std;
constexpr long double eps=1e-9;
using ll= long long;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define loop(i,a,b) for (int i = a; i <= b; i++)
/*
Imagine you have a large range of numbers, let's say from 1 to 100. And you want to find all the prime numbers in this range.
Instead of checking each number one by one, which can be slow for large ranges, you can use the segmented sieve approach.
Step 1: Create a small list of prime numbers up to the square root of the upper limit (100 in this example). Let's say the primes are [2, 3, 5, 7].
Step 2: Divide the large range (1 to 100) into smaller segments. For example, you could divide it into segments of size 10. 
So, the segments would be [1-10], [11-20], [21-30], ..., [91-100].
Step 3: For each segment, create a "dummy" list of numbers from the segment and mark them all as potential prime numbers.
Step 4: Go through the list of small primes [2, 3, 5, 7]. For each prime, find the first multiple of that prime within the current segment,
and mark all multiples of that prime as non-prime in the "dummy" list.
Step 5: Move to the next segment and repeat step 4.
Step 6: After going through all segments, the numbers that are still marked as potential prime numbers in the "dummy" lists are 
indeed prime numbers within the entire range.
This way, you find prime numbers in the large range by breaking it into smaller segments, making the process much faster and efficient. 
The segmented sieve is a clever way to find prime numbers in a range without checking every number individually.

*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout<<setprecision(12)<<fixed;
    
    int t;
    cin >> t;

    while (t--)
    {
        int m, n;
        cin >> m >> n;

        // If m is 1, set it to 2 to skip 1 as it's not a prime number
        if (m == 1)
        {
            m = 2;
        }

        // Limit the upper bound of segmented sieve to sqrt(n)
        int N = sqrt(n) + 1;

        // Vector to store prime numbers up to sqrt(n) (using the regular sieve)
        vector<bool> sieve(N, true);
        for (int i = 2; i * i < N; i++)
        {
            if (sieve[i])
            {
                for (int j = i * i; j < N; j += i)
                {
                    sieve[j] = false;
                }
            }
        }

        // Vector to store all primes in the given range [m, n] (using segmented sieve)
        vector<int> primes;
        vector<bool> is_prime(n - m + 1, true);

        for (int i = 2; i < N; i++)
        {
            if (sieve[i])
            {
                // Calculate the first multiple of i in the range [m, n]
                int first_multiple = max(i * i, (m + i - 1) / i * i);

                // Mark all multiples of i as non-prime
                for (int j = first_multiple; j <= n; j += i)
                {
                    is_prime[j - m] = false;
                }
            }
        }

        // Print all the prime numbers in the given range [m, n]
        for (int i = m; i <= n; i++)
        {
            if (is_prime[i - m])
            {
                cout << i << "\n";
            }
        }

        // Print an empty line to separate test cases
        cout << "\n";
    }
}
/*
Time complexity analysis:

The time complexity of this code is determined by the construction of the sieve of Eratosthenes up to sqrt(N+1) and the segmented sieve approach.
Let's denote the range [L, R] as M = R - L. Here's the breakdown:

Sieve of Eratosthenes (up to sqrt(N+1)): O(N * log(log(N)))
Segmented sieve approach: O((R - L) * log(log(R)))
The overall time complexity is O((N + M) * log(log(N + M))).
*/
