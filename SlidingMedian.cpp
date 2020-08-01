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
        ll n,k;
        cin>>n>>k;
        vect<ll> x(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>x[i];
        }
        set<pll> mst;
        for(int i=0;i<k;i++)
            mst.insert({x[i],i});
        ll count=0;
        for(auto itr=mst.begin();itr!=mst.end();itr++)
        {
            count+=1;
            if(count==(ll)(ceil(k/2.0)))
            {
                ll ans=(*itr).F;
                cout<<ans<<" ";
                break;
            }
        }
        pll to_del={x[0],0};
        for(int i=0;i<n-k;i++)
        {
            to_del={x[i],i};
            mst.erase(to_del);
            mst.insert({x[i+k],i+k});
            count=0;
            for(auto itr=mst.begin();itr!=mst.end();itr++)
            {
                count+=1;
                if(count==(ll)(ceil(k/2.0)))
                {
                    ll ans=(*itr).F;
                    cout<<ans<<" ";
                    break;
                }
            }
        }
//        priority_queue<ll,vect<ll>,greater<ll>> min_heap;
//        priority_queue<ll> max_heap;
//        for(int i=0;i<k;i++)
//        {
//            min_heap.push(x[i]);
//        }
//        for (int i = 0; i < (k-k/2); ++i)
//        {
//            max_heap.push(min_heap.top());
//            min_heap.pop();
//        }
//        cout<<max_heap.top()<<" ";
//        for(int i=k;i<n;i++)
//        {
//
//        }
    }
}