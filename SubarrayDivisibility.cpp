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

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t-->0)
    {
        int n;
        cin>>n;
        vect<ll> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }
        map<ll,ll> mp;ll count=0;
        ll curr_sum=a[0];
        mp[(curr_sum%n+n)%n]+=1;
        if((curr_sum%n+n)%n==0)
            count+=1;
        for(int i=1;i<n;i++)
        {
            curr_sum+=a[i];
            if((curr_sum%n+n)%n==0)
                count+=1;
            ll rem=((curr_sum%n)+n)%n;
            count+=mp[rem];
            mp[rem]+=1;
        }
//        for(auto itr=mp.begin();itr!=mp.end();itr++)
//        {
//            if(itr->second>1)
//            {
//                count+=(itr->second*(itr->second-1))/2;
//            }
//        }
        cout<<count;
    }
}