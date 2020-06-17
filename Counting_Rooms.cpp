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
    char input[n][m];
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            input[i][j]=s[j];
        }
    }
    for(int i=0;i<n*m;i++)
    {
        visited.push_back(false);
    }
    for(int i=0;i<n*m;i++)
    {
        // if((i)%m==0)
        // cout<<endl;
        // //cout<<(i)/m<<(i)%m<<" ";
        // cout<<input[i/m][i%m]<<" ";
        vector<int> temp;
        if(input[i/m][i%m]!='#')
        {
        if((i/m)-1>=0)
        {
            if(input[(i/m)-1][i%m]=='.')
            {
                temp.push_back(i-m);
            }
        }
        if((i/m)+1<n)
        {
            if(input[(i/m)+1][i%m]=='.')
            {
                temp.push_back(i+m);
            }
        }
        if((i%m)-1>=0)
        {
            if(input[i/m][(i%m)-1]=='.')
            {
                temp.push_back(i-1);
            }
        }
        if((i%m)+1<m)
        {
            if(input[i/m][(i%m)+1]=='.')
            {
                temp.push_back(i+1);
            }
        }
        }
        else
        {
            visited[i]=true;
        }
        adj.push_back(temp);
    }
    //cout<<count(visited.begin(),visited.end(),true);
    int ans=0;
    for(int i=0;i<n*m;i++)
    {
        if(visited[i]==false)
        {
            //cout<<"i not visited= "<<i<<endl;
            dfs(i);
            ans+=1;
        }
    }
    cout<<ans;
}