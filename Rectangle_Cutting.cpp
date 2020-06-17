#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = long long int;
const int MOD = 1e9 + 7;
vector<vector<int>> moves;
int min_horiz(int l, int h)
{
    int ans=10e6;
    for(int i=1;i<l;i++)
    {
        ans=min(ans,moves[i][h]+moves[l-i][h]);
    }
    return ans;
}
int min_vertic(int l, int h)
{
    int ans=10e6;
    for(int i=1;i<h;i++)
    {
        ans=min(ans,moves[l][i]+moves[l][h-i]);
    }
    return ans;
}
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin>>a>>b;

    for(int i=0;i<=a;i++)
    {
        vector<int> temp(b+1,0);
        moves.push_back(temp);
    }
    // for(int i=1;i<=a;i++)
    // {
    //     for(int j=1;j<=b;j++)
    //     {
    //         cout<<moves[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            if(i==j)
            {
                moves[i][j]=0;
            }
            else
            {
                moves[i][j]=min(min_horiz(i,j),min_vertic(i,j))+1;
            }
        }
    }
    cout<<moves[a][b];
}