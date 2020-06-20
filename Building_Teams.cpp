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

vector<vector<int>> adj;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> side(n,-1);
    bool is_bipartite = true;
    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        vector<int> temp;
        adj.push_back(temp);
    }
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    for (int st = 0; st < n; ++st) {
        if (side[st] == -1) {
            q.push(st);
            side[st] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : adj[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    } else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }

    
    if(is_bipartite)
    {
        for(int i=0;i<side.size();i++)
        {
            cout<<side[i]+1<<' ';
        }
    } else
    {
        cout<<"IMPOSSIBLE";
    }
}