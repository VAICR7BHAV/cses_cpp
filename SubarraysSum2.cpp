#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define vect vector
# define pll pair<ll,ll>
# define pii pair<int,int>
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = long long int;
const int MOD = 1e9 + 7;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t-->0)
    {
        ll n, x;
        cin >> n >> x;
        vect<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll count = 0;ll curr_sum=a[0];
        map<ll,int> mp;
        mp[curr_sum]+=1;
        if(curr_sum==x)
            count+=1;
        for(int i=1;i<n;i++)
        {
            curr_sum+=a[i];
            if(curr_sum==x)
                count+=1;
              if(mp.find(curr_sum-x)!=mp.end())
                {
                    count+=mp[curr_sum-x];
                }

            mp[curr_sum]+=1;
        }
        cout<<count;
    }
}