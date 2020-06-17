#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = long long int;
const int MOD = 1e9 + 7;
bool valid(double x,ll t,ll n,ll k[])
{
    ll sum=0;
    REP(i,0,n-1)
    {
        sum+=floor(x/k[i]);
        if(sum>t)
        {
            return true;
            break;
        }
    }
    if(sum>=t)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    ll n,t;
    cin>>n>>t;
    ll k[n];
    REP(i,0,n-1)
    {
        cin>>k[i];
    }
    double x = -1;
    double z=1000000000000000001;
    for (double b = floor(z); b >= 1; b = floor(b/2)) 
    {
        while (!valid(x+b,t,n,k)) 
        {
            x = floor(x + b);
        }
    }
    double ans = floor(x+1);
    cout<<fixed;
    string s=to_string(ans);
    string final="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!='.')
        {
            final+=s[i];
        }
        else
        {
            break;
        }
        
    }
    cout<<final;
}