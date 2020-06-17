#include <bits/stdc++.h>
using namespace std;
# define M_PI 3.14159265358979323846
using ll = long long int;
const int MOD = 1e9 + 7;
//sweeping line algorithm
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    ll req[n],size[m];
    for (int i = 0; i < n; i++)
    {
        cin>>req[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>size[i];
    }
    ll count=0,pointer_apar=0,pointer_req=0;
    sort(req,req+n);
    sort(size,size+m);
    while(pointer_apar<m && pointer_req<n)
    {
        ll required=req[pointer_req];
        ll size_apartment=size[pointer_apar];
        if(size_apartment>=required-k && size_apartment<=required+k)
        {
            count+=1;
            pointer_apar+=1;
            pointer_req+=1;
        }
        else if(size_apartment<required-k)
        {
            pointer_apar+=1;
        }
        else
        {
            pointer_req+=1;
        }
    }
    cout<<count;
}