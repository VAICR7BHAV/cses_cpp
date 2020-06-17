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
    int n,m;
    cin>>n>>m;
    int desc[n];
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        desc[i]=temp;
    }
    ll dp[n+1][m+1];
    for(int i=0;i<=m;i++)
    {
        dp[0][i]=0;
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    if(desc[0]==0)
    {
        for(int i=1;i<=m;i++)
        {
            dp[1][i]=1;
        }
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            if(i!=desc[0])
            {
                dp[1][i]=0;
            }
            else
            {
                dp[1][i]=1;
            }
            
        }
    }
    for(int i=2;i<=n;i++)
    {
        for(int x=1;x<=m;x++)
        {
            if(desc[i-1]!=0)
            {
                if(x!=desc[i-1])
                {
                    dp[i][x]=0;
                }
                else
                {
                    //cout<<"x==desc[i]"<<x<<" "<<desc[i]<<endl;
                    if(x!=m)
                    dp[i][x]=(dp[i-1][x-1]+dp[i-1][x]+dp[i-1][x+1])%MOD;
                    else
                    {
                        dp[i][x]=(dp[i-1][x-1]+dp[i-1][x])%MOD;
                    }
                    
                }
            }
            else
            {
                if(x!=m)
                dp[i][x]=(dp[i-1][x-1]+dp[i-1][x]+dp[i-1][x+1])%MOD;
                else
                    {
                        dp[i][x]=(dp[i-1][x-1]+dp[i-1][x])%MOD;
                    }
            }
            
        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=m;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    ll ans=0;
    if(desc[n-1]!=0)
    {
        ans=dp[n][desc[n-1]];
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            ans+=dp[n][i];
            dp[n][i]%=MOD;
        }
    }
    cout<<ans%MOD;
}