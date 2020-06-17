#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
ll power(ll a,ll b)
{
    ll ans=1;
    for(int i=0;i<b;i++)
    {
        ans=ans*a;
        ans=ans%MOD;
    }
    return ans;
}
int main()
{
    ll n;
    cin>>n;
    ll ans=0,curr_pow=5;
    while(true)
    {
        if(floor(n/curr_pow)==0)
        {
            break;
        }
        ans+=floor(n/curr_pow);
        curr_pow*=5;
    }
    cout<<ans;
}