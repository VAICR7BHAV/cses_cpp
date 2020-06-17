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
    int n;
    cin>>n;
    vector<pair<ll,ll>> start_end;
    REP(i,0,n-1)
    {
        ll a,b;
        cin>>a>>b;
        start_end.push_back(make_pair(b,a));
    }
    sort(start_end.begin(),start_end.end());
    ll count=1;
    ll curr_end=start_end[0].F;
    REP(i,0,n-2)
    {
        if(curr_end<=start_end[i+1].S)
        {
            curr_end=start_end[i+1].F;
            count+=1;
        }
    }
    cout<<count;
}