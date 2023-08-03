#include<bits/stdc++.h>
using namespace std;
constexpr long double eps=1e-9;
using ll= long long;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define loop(i,a,b) for (int i = a; i <= b; i++)

int N=1000000;
vector<bool> sieve(N+1,true); // Declare a boolean vector to hold sieve information

void createsieve()
{
    sieve[0]=sieve[1]=false; // 0 and 1 are not prime numbers
    for(int i=2;i<=sieve.size();i++)
    {
        sieve[i]=true; // Assume all other numbers are prime initially
    }
    for(int i=2;i*i<=N;i++)
    {
        if(sieve[i]==true)
        {
            // Mark all multiples of 'i' as non-prime
            for(int j=i*i;j<=N;j+=i) // Instead of i+j, it should be j+=i (increment by i)
            {
                sieve[j]=false;
            }
        }
    }
    // The outer loop runs approximately sqrt(N) times (up to i = sqrt(N)), 
    // and the inner loop runs N/i times, where i is a prime number.
    // Therefore, the overall time complexity of this function is O(sqrt(N) * N / i) ~ O(N * log(log(N))).
}

int main()
{
    createsieve(); // Create the sieve to find prime numbers up to N
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout<<setprecision(12)<<fixed;
    
    int n;
    cin>>n;
    
    if(sieve[n]==true)
    {
        cout<<"PRIME\n"; // If the number is prime, print "PRIME"
    }
    else
    {
        cout<<"NOT PRIME\n"; // If the number is not prime, print "NOT PRIME"
    }
}
