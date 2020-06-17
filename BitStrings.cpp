#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
ll power(ll n)
{
    int ans=1;
    for(int i=0;i<n;i++)
    {
        ans=ans*2;
        ans=ans%MOD;
    }
    return ans;
}
int main()
{
    ll n;
    cin>>n;
    cout<<power(n);
}