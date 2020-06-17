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
    vector<pair<ll,int>> max_len;
    
    for(int i=0;i<n;i++)
    {
        int max_less_than=0;
        for(int j=0;j<max_len.size();j++)
        {
            if(max_len[j].first<x[i])
            {
                max_less_than=max(max_less_than,max_len[j].second);
            }
        }
        max_len.push_back(make_pair(x[i],max_less_than+1));
    }
    // for(int i=0;i<n;i++)
    // {
    //     cout<<'('<<max_len[i].first<<" "<<max_len[i].second<<")";
    // }
    // cout<<endl;
    int ans=0;
    for(int i=0;i<max_len.size();i++)
    {
        ans=max(ans,max_len[i].second);
    }
    cout<<ans;
}