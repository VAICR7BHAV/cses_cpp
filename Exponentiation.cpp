#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
ll arr_of_pow[30];
ll binpow(ll a,ll b)
{
    ll res = 1;
    while (b > 0) 
    {
        if (b & 1)
            res = (res * a)%MOD;
        a = (a * a)%MOD;
        b >>= 1;
    }
    return res%MOD;
}
int main()
{
    int n;
    cin>>n;
    while(n>0)
    {
        ll a,b;
        cin>>a>>b;
        cout<<binpow(a,b)<<endl;
        n-=1;   
    }
}