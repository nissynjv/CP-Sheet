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
    int n;
    cin>>n;
    int cnt=0;
    vector<int>factors;
    /*
    let's take an example of 36.
    1*36,2*18,3*12,4*9,6*6 9*4,12*3,36*1
    after the square root of 36,factors are repeating in reverse order,therefore it is better to 
    limit the for loop to sqrt(n) but the time complexity of sqrt is log(n),since to further optimise
    it is advised to use the i*i<=n instead of sqrt(n)
    This same program can also be used to determine whether a number is prime or not
    if cnt>2,then it is not prime,else it is composite.
    */
    for(int i=1;i*i<=(n);i++)
    {
    	if(n%i==0&&n/i==i)
    	{
            
    		cnt++;
            factors.pb(i);
           
    	}
        else if(n%i==0)
        {
            cnt+=2;
            factors.pb(i);
            factors.pb(n/i);
        }
    }
    cout<<cnt<<"\n";
    if(cnt>2)
    {
        cout<<"NOT PRIME\n";
    }
    else
    {
        cout<<"PRIME\n";
    }
    cout<<"Factors are:\n";
    sort(factors.begin(),factors.end());
    for(int i=0;i<factors.size();i++)
    {
        cout<<factors[i]<<"\n";
    }
    
	
	

}