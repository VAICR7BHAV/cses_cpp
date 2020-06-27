#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll =unsigned long long int;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
vector<vector<pair<int,ll>>> adj;
void djikstra(int s/*Source vertex*/,vector<ll>&d/*Vector to store distance*/
        )
{
    int n=adj.size();//Number of nodes
    d.assign(n,INF);//Initializing all distances as infinity at the beginning.
    //Defind INF as some large number const int INF = 1000000000;

    vector<bool> visited(n,false);//All vertices are marked unvisited at the beginning
    d[s]=0;//Source vertex has distance 0 from itself.
    for (int i = 0; i < n; ++i)
    {
        int u=-1;
        for (int j = 0; j < n; ++j)
        {
            if(!visited[j] && (u==-1 || d[j]<d[u]))
            {
                u=j;
            }
        }
        if(d[u]==INF)
            break;

        visited[u]=true;
        for(auto edge:adj[u])
        {
            int v=edge.first;
            int len=edge.second;
            if(d[u]+len<d[v])
            {
                d[v]=d[u]+len;

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
    for (int i = 0; i < n; ++i) {
        vector<pair<int,ll>> temp;
        adj.push_back(temp);
    }
    for (int i = 0; i < m; ++i) {
        int a,b;ll c;
        cin>>a>>b>>c;
        adj[a-1].push_back(make_pair(b-1,c));
    }
    vector<ll> shortest_path;
    djikstra(0,shortest_path);
    for (int i = 0; i < n; ++i) {
        cout<<shortest_path[i]<<" ";
    }
}