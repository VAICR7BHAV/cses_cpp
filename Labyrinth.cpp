#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = long long int;
const int MOD = 1e9 + 7;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
int Left[]={0,0,-1,1};
int Right[]={-1,1,0,0};
char direction[]={'L','R','U','D'};
bool dfs(char map[1000][1000],int n,int m,int r,int c,vector<vector<bool>> visited,vector<char>&path)
{
    //cout<<map[r][c]<<" "<<r<<" "<<c<<endl;
    visited[r][c]=true;
    if(map[r][c]=='B')
    {
        return true;
    }
    bool ans=false;
    for (int i = 0; i < 4; ++i)
    {
        if(r+Left[i]>=0 && c+Right[i]>=0 && r+Left[i]<n && c+Right[i]<m)
        {
            if(!visited[r+Left[i]][c+Right[i]] && map[r+Left[i]][c+Right[i]]!='#')
            {
                path.push_back(direction[i]);
                bool temp=dfs(map,n,m,r+Left[i],c+Right[i],visited,path);
                ans=ans|temp;
                if(temp)
                    break;
            }
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    char map[1000][1000];
    vector<vector<bool>> visited(n);
    int source_row,source_col,target_row,target_col;
    vector<vector<array<int, 3>>> parent(n);
    for (int i = 0; i < n; ++i)
    {
        string c;
        cin>>c;
        for (int j = 0; j < m; ++j)
        {
            map[i][j]=c[j];visited[i].push_back(false);
            if(map[i][j]=='A')
            {source_row=i;source_col=j;}
            parent[i].push_back({-1,-1,-1});
            if(map[i][j]=='B')
            {
                target_row=i;target_col=j;
            }
        }
    }
    vector<char> path;
    queue<array<int, 3>> q;
    q.push({source_row,source_col,0});
    visited[source_row][source_col]=true;
    bool path_found=false;
    while(!q.empty())
    {
        array<int, 3> temp=q.front();q.pop();
        int row=temp[0];int col=temp[1];
        //cout<<row<<" "<<col<<" "<<endl;
        visited[row][col]=true;
        if(map[row][col]=='B')
        {path_found=true;break;}
        for (int i = 0; i < 4; ++i)
        {
            if(row+Left[i]>=0 && col+Right[i]>=0 && row+Left[i]<n && col+Right[i]<m)
            {
                if(!visited[row+Left[i]][col+Right[i]] && map[row+Left[i]][col+Right[i]]!='#')
                {
                    parent[row+Left[i]][col+Right[i]]={row,col,i};
                    visited[row+Left[i]][col+Right[i]]=true;
                    q.push({row+Left[i],col+Right[i],i});
                }
            }
        }
    }

    if(path_found)
    {
        string ans="";
        array<int, 3> temp=parent[target_row][target_col];
        while(true)
        {

            if(temp[0]==source_row && temp[1]==source_col ||(temp[0]==-1 && temp[1]==-1))
            {ans+=direction[temp[2]];break;}
            ans+=direction[temp[2]];
            temp=parent[temp[0]][temp[1]];
        }
        cout<<"YES\n";
        cout<<ans.size()<<'\n';
        reverse(ans.begin(),ans.end());
        cout<<ans;
        cout<<'\n';
    }
    else
    {
        cout<<"NO\n";
    }
}