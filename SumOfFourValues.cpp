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
        ll n,x;
        cin>>n>>x;
        vect<ll> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }
        map<ll,pii> mp;
        for (int i = 0; i < n-1; ++i)
        {
            for (int j = i+1; j < n; ++j)
            {
                mp[a[i]+a[j]]={i,j};
            }
        }
        bool found=false;array<int,4> ans;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ll rem=x-a[i]-a[j];
                if(mp.find(rem)!=mp.end())
                {
                    auto p=mp[rem];
                    if(p.F==i || p.S==i || p.F==j || p.S==j)
                    {
                        found=false;
                    }
                    else
                    {
                        ans[0]=p.F;ans[1]=p.S;ans[2]=i;ans[3]=j;
                        found=true;break;
                    }
                }
            }
            if(found)
                break;
        }
        if(found)
        {
            for (int i = 0; i < 4; ++i) {
                cout<<ans[i]+1<<" ";
            }
        }
        else
            cout<<"IMPOSSIBLE\n";
    }
}