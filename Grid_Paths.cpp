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
    int n;
    cin>>n;
    int inp_matrix[n][n];
    ll count_matrix[n][n];
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<n;j++)
        {
            inp_matrix[i][j]=s[j];
        }
    }
    if(inp_matrix[0][0]=='*')
    count_matrix[0][0]=0;
    else
    {
        count_matrix[0][0]=1;
    }
    
    for(int i=1;i<n;i++)
    {
        if(inp_matrix[0][i]!='*')
        {
            count_matrix[0][i]=count_matrix[0][i-1];
        }
        else
        {
            count_matrix[0][i]=0;
        }
        if(inp_matrix[i][0]!='*')
        {
            count_matrix[i][0]=count_matrix[i-1][0];
        }
        else
        {
            count_matrix[i][0]=0;
        }
        
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(inp_matrix[i][j]!='*')
            {
                count_matrix[i][j]=count_matrix[i-1][j]+count_matrix[i][j-1];
                count_matrix[i][j]%=MOD;
            }
            else
            {
                count_matrix[i][j]=0;
            }
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout<<count_matrix[i][j]<<" ";   
    //     }
    //     cout<<endl;
    // }
    cout<<count_matrix[n-1][n-1];  
}