#include<bits/stdc++.h>
using namespace std;
constexpr long double eps=1e-9;
using ll= long long;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define loop(i,a,b) for (int i = a; i <= b; i++)
void csieve(ll n )
{
    vector<bool>sieve(n,true);
    //create sieve
    for(int i=2;i*i<=n;i++)
    {
        if(sieve[i]==true)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                sieve[j]=false;
            }
        }
    }
    vector<ll>s2;
    for(ll i=2;i<=n;i++)
    {
       if(sieve[i]==true)
       {
        s2.push_back(i);
       }
    }
    for(int i=0;i<=s2.size();i++)
    {
       ll m=100*i;
       if(m<=s2.size())
       {
           cout<<s2[m]<<"\n";
       }
       
    }    
}

int main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout<<setprecision(12)<<fixed;
    ll n=100000000;
    csieve(n);
}
