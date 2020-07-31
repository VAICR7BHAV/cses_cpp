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

void dijsktra(int s,vect<ll>&d,vect<ll>&p,vect<vect<pi>> &adj)
{
    int n=adj.size();
    //d.assign(n,INF);
    d[s]=0;
    priority_queue<pi,vect<pi>,greater<pi>> q;
    q.push({0,s});
    while(!q.empty())
    {
        auto v=q.top().S;
        auto d_v=q.top().F;
        q.pop();
        if(d_v!=d[v])
            continue;
        for(auto edge:adj[v])
        {
            ll to=edge.S;
            ll len=edge.F;
            if(d[v]+len<d[to])
            {
                d[to]=d[v]+len;
                p[to]=v;
                q.push({d[to],to});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vect<vect<pi>> adj(n+1);
    for (int i = 0; i < m; ++i)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
    }
    vector<ll> d(n+1,INF);
    vector<ll> p(n+1,INF);
    dijsktra(1,d,p,adj);
    for (int i = 1; i < n+1; ++i)
    {
        cout<<d[i]<<" ";
    }
}