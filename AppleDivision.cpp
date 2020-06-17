#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
ll get_diff(ll p[],int len,ll sum_so_far,ll total_sum)
{
    if(len==0)
    {
        return(abs(total_sum-2*(sum_so_far)));
    }
    return min(get_diff(p,len-1,sum_so_far,total_sum),get_diff(p,len-1,sum_so_far+p[len-1],total_sum));
}
int main()
{
    int n;
    cin>>n;
    ll p[n];
    ll total_sum=0;
    for(int i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        total_sum+=temp;
        p[i]=temp;
    }
    cout<<get_diff(p,n,0,total_sum);
}