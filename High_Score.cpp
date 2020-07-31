#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define pi pair<ll,ll>
#define vect vector
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = long long int;
const int MOD = 1e9 + 7;
const ll INF=1e18;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))


struct edge
{
    ll a, b, cost;
};
pair<ll,bool> bellman_ford(int n,int m,int v,vect<edge> &e)
{
    vector<ll> d (n, INF);
    d[v] = 0;
    int x;
    for (int i=0; i<n; ++i)
    {
        x = -1;
        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
                    x = e[j].b;
                }
    }
    if (x == -1)
        return {d[n-1],false};
    else
    {
        return {d[n-1],true};
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vect<edge> e;
    for (int i = 0; i < m; ++i)
    {
        ll s,d,x;
        cin>>s>>d>>x;
        edge temp;
        temp.a=s-1;
        temp.b=d-1;
        temp.cost=(-1)*x;
        e.push_back(temp);
    }
    vector<ll>d(n,INF);
    pair<ll,bool> ans=bellman_ford(n,m,0,e);
    if(ans.S)
    {
        if(ans.F==-1)
        cout<<(-1)*ans.F;
        else
            cout<<-1;
    }
    else
    {
        cout<<-1*ans.F;
    }
}
