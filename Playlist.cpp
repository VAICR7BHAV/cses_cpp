#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
//This is the 2 pointer method to deal with longest subarray type questions
int main()
{
    int n;
    cin>>n;
    ll k[n];
    for(int i=0;i<n;i++)
    {
        cin>>k[i];
    }
    map<int,int> mp;
    set<int> se;
    int pointer1=0,pointer2=0,curr_max=0;
    while(pointer2<n)
    {
        bool is_in = se.find(k[pointer2]) != se.end();
        if(!is_in)
        {
            se.insert(k[pointer2]);
            pointer2++;
            int size=se.size();
            curr_max=max(curr_max,size);
        }
        else
        {
            se.erase(k[pointer1]);
            pointer1++;
            int size=se.size();
            curr_max=max(curr_max,size);
        }
    }
    cout<<curr_max;
}