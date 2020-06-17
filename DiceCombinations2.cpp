#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
int main()
{
    int x;
    cin>>x;
    vector<int> coins;
    for(int i=0;i<6;i++)
    {
        coins.push_back(i+1);
    }
    ll dp[x];
    //dp[0]=1;
    //dp[1]=2;
    for(int i=0;i<x;i++)
    {
        ll temp=0;
        for(int j=0;j<6;j++)
        {
            if(i-coins[j]>=0)
            {
                temp+=dp[i-coins[j]];
                //cout<<"dp["<<(i-coins[j])<<"]";
            }
        }
        if(binary_search(coins.begin(),coins.end(),i+1))
        {
            temp+=1;
        }
        dp[i]=temp%MOD;
    }
    // for(int i=0;i<x;i++)
    // {
    //     cout<<dp[i]<<" ";
    // }
    cout<<endl<<dp[x-1];
}