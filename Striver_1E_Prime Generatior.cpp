#include<bits/stdc++.h>
using namespace std;
constexpr long double eps=1e-9;
using ll= long long;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define loop(i,a,b) for (int i = a; i <= b; i++)

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
