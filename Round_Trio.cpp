#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define pb push_back
# define vect vector
using ll = long long int;
const int MOD = 1e9 + 7;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vect<vect<int>> adj(n+1);
    for (int i = 0; i < m; ++i)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);adj[b].push_back(a);
    }
    queue<int> q;q.push(1);vect<bool> visited(n+1);vect<int> parent(n+1);
    int terminating_node;
    while(!q.empty())
    {
        int node=q.front();q.pop();
        visited[node]=true;bool should_stop_bfs=false;
        for(int u:adj[node])
        {
            if(!visited[u])
            {
                q.push(u);parent[u]=node;
            }
            else if(parent[node]!=u)
            {
                terminating_node=u;should_stop_bfs=true;parent[u]=node;
                break;
            }
        }
        if(should_stop_bfs)
            break;
    }
    vector<int> path;int temp=terminating_node;
    path.pb(terminating_node);
    do{
        path.pb(parent[temp]);
        temp=parent[temp];
    }while(temp!=terminating_node);
    cout<<path.size()<<"\n";
    for (int i = 0; i < path.size(); ++i)
    {
        cout<<path[i]<<" ";
    }
}