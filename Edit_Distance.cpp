#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = long long int;
const int MOD = 1e9 + 7;
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    string n,m;
    cin>>n;
    cin>>m;
    int matrix[n.size()+1][m.size()+1];
    matrix[0][0]=0;
    for(int i=1;i<=m.size();i++)
    {
        matrix[0][i]=i;
    }
    for(int i=1;i<=n.size();i++)
    {
        matrix[i][0]=i;
    }
    for(int i=1;i<=n.size();i++)
    {
        for(int j=1;j<=m.size();j++)
        {
            if(n[i-1]==m[j-1])
            {
                matrix[i][j]=min(matrix[i][j-1]+1,matrix[i-1][j]+1);
                matrix[i][j]=min(matrix[i][j],matrix[i-1][j-1]);
            }
            else
            {
                matrix[i][j]=min(matrix[i][j-1]+1,matrix[i-1][j]+1);
                matrix[i][j]=min(matrix[i][j],matrix[i-1][j-1]+1);
            }   
        }
    }
    cout<<matrix[n.size()][m.size()];
}