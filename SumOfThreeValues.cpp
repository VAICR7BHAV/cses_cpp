#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
int main()
{
    int n;
    ll x;
    cin>>n>>x;
    ll a[n];
    unordered_map<ll,int> hm;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        hm[a[i]]=i+1;
    }
    bool found=false;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            //int val=hm[x-a[i]-a[j]];
            auto itr=hm.find(x-a[i]-a[j]);
            if(itr!=hm.end())
            {
                if((i+1)!=itr->second && (j+1)!=itr->second)
                {
                    cout<<(i+1)<<" "<<(j+1)<<" "<<itr->second;
                    found=true;
                    break;
                }
            }
        }
        if(found)
        break;
    }
    if(!found)
        {
            cout<<"IMPOSSIBLE";
        }
}