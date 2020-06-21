#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = unsigned long long int;
const int MOD = 1e9 + 7;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
ll products_made(ll time,ll arr[],int n)
{
    ll products_made=0;
    for(int i=0;i<n;i++)
    {
        products_made+=time/arr[i];
    }
    return products_made;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    ll t;
    cin>>t;
    ll k[n];
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin>>temp;
        k[i]=temp;
    }

    ll lb=0,ub=10e18+1;
    ll ans=10e18+1;
    while(lb<=ub)
    {
        ll mid=(lb+ub)/2;
        ll prod=products_made(mid,k,n);
        if(prod>=t)
        {
            ans=min(ans,mid);
            ub=mid-1;
        }

        else
        {
            lb=mid+1;
        }

    }
    // cout<<products_made(7,k,n)<<endl;
    // for(ll i=ans-1;i>0;i--)
    // {
    //     if(products_made(i,k,n)==t)
    //     {
    //         ans=min(ans,i);
    //     }
    //     else
    //     {
    //         break;
    //     }

    // }
    cout<<ans;
}