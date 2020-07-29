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

void build(vector<ll>&a,int v,int tl,int tr,vector<ll>&t)
{
    if(tl==tr)
    {
        t[v]=a[tl];
    }
    else
    {
        int tm=(tl+tr)/2;
        build(a,2*v,tl,tm,t);
        build(a,2*v+1,tm+1,tr,t);
        t[v]=t[2*v]+t[2*v+1];
    }
}
ll sum(int v,int tl,int tr,int l,int r,vector<ll>&t)
{
//    if(v>t.size())
//        return 0;
    if(l>r)
        return 0;
    if(l==tl && r==tr)
    {
        return t[v];
    }
    int tm=(tl+tr)/2;
    return sum(2*v,tl,tm,l,min(r,tm),t)+sum(2*v+1,tm+1,tr,max(l,tm+1),r,t);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

        int n,q;
        cin>>n>>q;
        vector<ll> x(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>x[i];
        }
        vector<ll>t(4*n);
        build(x,1,0,n-1,t);
        while(q-->0)
        {
            int l,r;
            cin>>l>>r;
            cout<<sum(1,0,n-1,l-1,r-1,t)<<'\n';
        }
}