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
        t[v]=min(t[2*v],t[2*v+1]);
    }
}
ll mini(int v,int tl,int tr,int l,int r,vector<ll>&t)
{

    if(l>r)
        return 1e11;
    if(l==tl && r==tr)
    {
        return t[v];
    }
    int tm=(tl+tr)/2;
    return min(mini(2*v,tl,tm,l,min(r,tm),t),mini(2*v+1,tm+1,tr,max(l,tm+1),r,t));
}
void update(int v,int tl,int tr,int pos,ll new_val,vector<ll>&t)
{
    if(tl==tr)
    {
        t[v]=new_val;
    }
    else
    {
        int tm=(tl+tr)/2;
        if(pos<=tm)
        {
            update(2*v,tl,tm,pos,new_val,t);
        }
        else
        {
            update(2*v+1,tm+1,tr,pos,new_val,t);
        }
        t[v]=min(t[2*v],t[2*v+1]);
    }
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
        vector<ll>t(4*n,1e11);
        build(x,1,0,n-1,t);
        while(q-->0)
        {
            int type=2;
//            cin>>type;
            if(type==2)
            {
                int l,r;
                cin>>l>>r;
                cout<<mini(1,0,n-1,l-1,r-1,t)<<'\n';
            }
//            else
//            {
//                int k;ll u;
//                cin>>k>>u;
//                update(1,0,n-1,k-1,u,t);
//            }
        }
}