#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
int main()
{
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        arr[i]=temp;
    }
    ll count=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        {
            long diff=arr[i-1]-arr[i];
            arr[i]=arr[i-1];
            count+=diff;
        }
    }
    cout<<count;
}