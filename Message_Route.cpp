#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define REP(i,a,b) for(int i=a;i<=b;i++)
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
using ll = long long int;
const int MOD = 1e9 + 7;
const int INF=10e6;
vector<vector<pair<int,int>>> adj;
priority_queue<pair<int,int>> q;
vector<int> restore_path(int s, int t, vector<int> const& p) {
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}
int maine()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> path(n,-1);
    for (int i = 0; i < n; ++i)
    {
        vector<pair<int,int>> temp;
        adj.push_back(temp);
    }
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(make_pair(b-1,1));
        adj[b-1].push_back(make_pair(a-1,1));
    }
    int distance[n];bool processed[n];
    for (int i = 0; i < n; ++i) {
        distance[i]=INF;
        processed[i]=false;
    }
    distance[0]=0;
    q.push(make_pair(0,0));
    while(!q.empty())
    {
        int a=q.top().second;
        q.pop();
        if(processed[a])
            continue;
        else
        {
            for(auto u: adj[a])
            {
                int b=u.first,w=u.second;
                if(distance[a]+w<distance[b])
                {
                    distance[b]=distance[a]+w;
                    q.push(make_pair(-1*distance[b],b));
                    path[b]=a;
                }
            }
        }
    }
    path=restore_path(0,n-1,path);
    if(distance[n-1]!=INF)
    {
        cout<<distance[n-1]+1<<'\n';
        for (int i  = 0; i < path.size(); ++i)
        {
            if(path[i]==-1)
                break;
            cout<<path[i]+1<<' ';
        }
    }

    else
        cout<<"IMPOSSIBLE";
}