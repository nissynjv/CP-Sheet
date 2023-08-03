#include<bits/stdc++.h>
using namespace std;
constexpr long double eps=1e-9;
using ll= long long;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define loop(i,a,b) for (int i = a; i <= b; i++)
ll m=90000001;
vector<bool>sieve(m,true);
vector<ll>s2;
void cs()
{
        ll n=90000000;
        sieve[0]=sieve[1]=false;
        for(ll i=2;i*i<=n;i++)
        {
            if(sieve[i]==true)
            {
                for(ll j=i*i;j<=n;j+=i)
                {
                    sieve[j]=false;
                }
            }
        }
        for(int i=0;i<=n;i++)
        {
            if(sieve[i]==true)
            {
                s2.push_back(i);
            }
        }
}


int main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout<<setprecision(12)<<fixed;
    int t;
    cs();
    cin>>t;
    while(t--)
    {
        ll s;
        cin>>s;
        cout<<s2[s-1]<<"\n";
        // for(int i=0;i<=10;i++)
        // {
        //     cout<<s2[i]<<"\n";
        // }
    }
}
