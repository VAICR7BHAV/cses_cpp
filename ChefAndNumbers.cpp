#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n;
        cin>>n;
        vector<int> arr;
        int temp;
        cin>>temp;
        arr.push_back(temp);
        int prev=arr[0];
        for(int i=1;i<n;i++)
        {
            cin>>temp;
            if(temp!=prev)
            {
                prev=temp;
                arr.push_back(temp);
            }
            else
            {
                prev=-1;
            }
        }
        // for(int i=0;i<arr.size();i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        map<int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]+=1;
        }
        int maxi=0;
        int ans=9999999;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            //cout<<i->first<<" "<<i->second;
            if(i->second>maxi)
            {
                maxi=i->second;
                ans=i->first;
            }
        }
        cout<<ans<<endl;
        t-=1;
    }
}