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
    stack<int> st;

    vect<bool> visited(n+1);vect<int> parent(n+1);
    int terminating_node;bool ans_found=false;
    for (int i = 1; i <=n; ++i)
    {
        if(!visited[i])
        {
            st.push(i);
            while(!st.empty())
            {
                int node=st.top();st.pop();
                visited[node]=true;bool should_stop_dfs=false;
                for(int u:adj[node])
                {
                    if(!visited[u])
                    {
                        st.push(u);parent[u]=node;
                    }
                    else if(parent[node]!=u)
                    {
                        terminating_node=u;should_stop_dfs=true;parent[u]=node;
                        break;
                    }
                }
                if(should_stop_dfs)
                {ans_found=true;break;}
            }
        }
        if(ans_found)
            break;
    }

    if(!ans_found)
        cout<<"IMPOSSIBLE\n";
    else
    {
        vector<int> path;int temp=terminating_node;
        path.pb(terminating_node);
        do{
            path.pb(parent[temp]);
            temp=parent[temp];
            if(temp==0)
                break;
        }while(temp!=terminating_node);
        if(path[0]!=path[path.size()-1])
        {
            path[path.size()-1]=path[0];
        }
        cout<<path.size()<<"\n";
        for (int i = 0; i < path.size(); ++i)
        {
            cout<<path[i]<<" ";
        }
    }

}