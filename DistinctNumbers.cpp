#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
int main()
{
    int n;
    cin>>n;
    set<int> mp;
    for(int i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        mp.insert(temp);
    }
    cout<<mp.size();
}