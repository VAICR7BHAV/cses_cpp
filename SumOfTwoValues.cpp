#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
int main()
{
    ll n,x;
    cin>>n>>x;
    ll arr[n];
    map<ll,int> hm;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        hm[arr[i]]=i+1;
    }
    bool found=false;
    for(int i=0;i<n;i++)
    {
        int val=hm[x-arr[i]];
        if(val!=0)
        {
            if((i+1)!=val)
            {
                cout<<(i+1)<<" "<<val;
                found=true;
                break;
            }
        }
    }
    if(! found)
    {
        cout<<"IMPOSSIBLE";
    }
}