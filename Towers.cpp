#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
int main()
{
    int n;
    cin>>n;
    ll k[n];
    vector<ll> tower;
    cin>>k[0];
    tower.push_back(k[0]);
    for(int i=1;i<n;i++)
    {
        cin>>k[i];
        if(k[i]>tower[tower.size()-1])
        {
            tower.push_back(k[i]);
        }
       else
       {
           int pos=upper_bound(tower.begin(),tower.end(),k[i])-tower.begin();
           if(pos<tower.size())
           {
               if(tower[pos]==k[i])
               {
                   tower[pos+1]=k[i];
               }
               else
               {
                   tower[pos]=k[i];
               }
           }
           else
           {
               tower.push_back(k[i]);
           }     
       }
    }
    cout<<tower.size();
}