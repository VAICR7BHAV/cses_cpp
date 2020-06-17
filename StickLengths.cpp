#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
int main()
{
    int n;
    cin>>n;
    ll p[n];
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        sum+=p[i];
    }
    /*
    ll ave=sum/n;
    cout<<ave<<endl;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=abs(p[i]-ave);
    }
    cout<<ans;
    */
   sort(p,p+n);
   ll medi;
   if(n%2==0)
   {
       medi=(p[n/2]+p[n/2-1])/2;
   }
   else
   {
       medi=p[n/2];
   }
   ll ans=0;
   for(int i=0;i<n;i++)
   {
       ans+=abs(p[i]-medi);
   }
    cout<<ans;
}