#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
int main()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<1;
    }
    else if(n==2)
    {
        cout<<2;
    }
    else
    {
        ll dp[n];
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;i++)
        {
            ll temp=dp[i-1]+dp[i-2];
            if(i-3>=0)
            {
                temp+=dp[i-3];
            }
            if(i-4>=0)
            {
                temp+=dp[i-4];
            }
            if(i-5>=0)
            {
                temp+=dp[i-5];
            }
            if(i-6>=0)
            {
                temp+=dp[i-6];
            }
            if(i<6)
            dp[i]=(temp+1)%MOD;
            else
            {
                dp[i]=temp%MOD;
            }
        }
        cout<<dp[n-1];
    }
}