#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
int main()
{
    int n;ll x;
    cin>>n>>x;
    ll arr1[n];
    bool alloted[n];
    for(int i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        arr1[i]=temp;
        alloted[i]=false;
    }
    sort(arr1,arr1+n);
    int leftp=0,rightp=n-1;
    int ans=0,count=0;
    while(count!=n)
    {
        if(leftp==rightp && !alloted[leftp])
        {
            count+=1;
            ans+=1;
        }
        else if(!alloted[leftp] && !alloted[rightp])
        {
            if(arr1[leftp]+arr1[rightp]<=x)
            {
                count+=2;
                ans+=1;
                alloted[leftp]=true;
                alloted[rightp]=true;
                leftp+=1;
                rightp-=1;
            }
            else
            {
                alloted[rightp]=true;
                count+=1;
                ans+=1;
                rightp-=1;
            }
        }
        else if(!alloted[leftp])
        {
            alloted[leftp]=true;
            count+=1;
            ans+=1;
            leftp+=1;
        }
        else if(!alloted[rightp])
        {
            alloted[rightp]=true;
            count+=1;
            ans+=1;
            rightp-=1;
        }
    }
    cout<<ans;
}