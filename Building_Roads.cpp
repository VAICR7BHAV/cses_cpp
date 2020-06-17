#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = long long int;
const int MOD = 1e9 + 7;
vector<bool> visited;
vector<vector<int>> adj;
void dfs(int v)
{
    visited[v]=true;
    for(int u:adj[v])
    {
        if(!visited[u])
        {
            dfs(u);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        vector<int> temp;
        visited.push_back(false);
        adj.push_back(temp);
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    int ans=0;
    vector<int> non_connected;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            dfs(i);
            non_connected.push_back(i+1);
            ans+=1;
        }
    }
    cout<<ans-1<<'\n';
    for(int i=0;i<non_connected.size()-1;i++)
    {
        cout<<non_connected[i]<<" "<<non_connected[i+1]<<'\n';
    }
}