#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = long long int;
const int MOD = 1e9 + 7;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,q;
    cin>>n>>q;
    ll x[n];
    for (int i = 0; i < n; ++i) {
        int temp;
        cin>>temp;
        x[i]=temp;
    }
    ll pre_sum[n];pre_sum[0]=x[0];
    for (int i = 1 ; i < n; ++i)
    {
        pre_sum[i]=pre_sum[i-1]+x[i];
    }
    while(q-->0)
    {
        int a,b;
        cin>>a>>b;
        if(a-2<0)
        {
            cout<<pre_sum[b-1]<<'\n';
        } else
        {
            cout<<pre_sum[b-1]-pre_sum[a-2]<<'\n';
        }
    }
}