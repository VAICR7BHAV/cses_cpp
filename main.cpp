#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = long long int;
const int MOD = 1e9 + 7;
const ll INF=1e18;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    ll x[n];
    for(int i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        x[i]=temp;
    }
    //dp[i]=Element at which a subsequence of length i terminates
    vector <ll> dp(n+1);

    for(int i=0;i<=n;i++)
    {
        dp[i]=INF;
    }
    dp[0]=-1*INF;

    for(int i=0;i<n;i++)
    {
        int pos=upper_bound(dp.begin(),dp.end(),x[i])-dp.begin();
        //cout<<x[i]<<" "<<pos<<endl;
        if(dp[pos-1]<x[i] && x[i]<dp[pos])
        {
            dp[pos]=x[i];
        }
    }
    int ans=0;
    for(int i=0;i<n+1;i++)
    {
        if(dp[i]<INF)
        {
            ans=i;
        } else
        {
            break;
        }
    }
    cout<<ans;
}