#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = long long int;
const int MOD = 1e9 + 7;
int main()
{
    int n,x;
    cin>>n>>x;
    int coins[n];
    REP(i,0,n-1)
    {
        int temp;
        cin>>temp;
        coins[i]=temp;
    }
    vector<ll> dp(x+1,0);
    //sort(coins,coins+n);
    for (int i = 0; i <=x; i++)
    {
        if(i%coins[0]==0)
        {
            dp[i]=1;
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=coins[i];j<=x;j++)
        {
            dp[j]=dp[j]+dp[j-coins[i]];
            dp[j]%=MOD;
        }
    }
    cout<<dp[x];
}