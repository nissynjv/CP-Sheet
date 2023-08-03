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
    // Fast input/output stream handling
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout<<setprecision(12)<<fixed;

    int n;
    cin>>n;

    // --------------------------------------
    // Naive Approach: Prime Factorization
    // --------------------------------------
    // Time complexity: O(sqrt(n))

    int num = n;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n = n / i;
        }
    }
    if (n > 1)
    {
        cout << n;
    }
    cout << "\n";

    // Reset 'n' for the next approach
    n = num;

    // --------------------------------------
    // Sieve of Eratosthenes Approach: Prime Factorization
    // --------------------------------------
    // Time complexity: O(N * log(log(N)))

    // Define the upper limit for the sieve
    int N=1000000;

    // Vector to store the smallest prime factor for each number
    vector<int> sieve(N+1);

    // Construct the Sieve of Eratosthenes
    for(int i=1; i<=N+1; i++)
    {
        sieve[i] = i;
    }

    for(int i=2; i*i<=N; i++)
    {
        if(sieve[i] == i)
        {
            for(int j=i*i; j<=N; j+=i)
            {
                if(sieve[j] == j)
                {
                    sieve[j] = i;
                }
            }
        }
    }

    // Find and print prime factors of 'n'
    while(n != 1)
    {
        cout << sieve[n] << " ";
        n = n / sieve[n];
    }
    cout << "\n";

    return 0;
}
