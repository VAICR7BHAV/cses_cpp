#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = long long int;
const int MOD = 1e9 + 7;
vector<ll> x;
ll solve(int lb,int ub)
{
    if(lb==ub)
    {
        return x[lb];
    }
    if(lb>ub)
    {
        return 0;
    }
    ll first_chosen=x[lb]+min(solve(lb+2,ub),solve(lb+1,ub-1));
    ll second_chosen=x[ub]+min(solve(lb+1,ub-1),solve(lb,ub-2));
    return max(first_chosen,second_chosen);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin>>temp;
        x.push_back(temp);
    }
    ll dp[n][n];
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                dp[i][j]=x[i];
            }
            else if(i>j)
            {
                dp[i][j]=0;
            }
            else
            {
                ll first_chose_val_1=0;
                if(i+2<n)
                    first_chose_val_1=dp[i+2][j];
                ll first_chose_val_2=0;
                if(i+1<n && j-1>=0)
                    first_chose_val_2=dp[i+1][j-1];
                ll first_chosen=x[i]+min(first_chose_val_1,first_chose_val_2);
                ll last_chose_val_1=0;
                if(i+1<n && j-1>=0)
                    last_chose_val_1=dp[i+1][j-1];
                ll last_chose_val_2=0;
                if(j-2>=0)
                    last_chose_val_2=dp[i][j-2];
                ll last_chosen=x[j]+min(last_chose_val_1,last_chose_val_2);
                dp[i][j]=max(first_chosen,last_chosen);
            }
            
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout<<dp[i][j]<<" "; 
    //     }
    //     cout<<endl;
    // }
    cout<<dp[0][n-1];
}