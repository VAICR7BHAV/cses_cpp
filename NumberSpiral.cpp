#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
ll get_value(ll y ,ll x)
{
    ll ans=0;
    if(x==1)
    {
        if(y%2==0)
        {
            ans=y*y;
            return ans;
        }
        else
        {
            ans=(y-1)*(y-1)+1;
            return ans;
        }
    }
    else if(y==1)
    {
        if(x%2==0)
        {
            ans=(x-1)*(x-1)+1;
            return ans;
        }
        else
        {
            ans=x*x;
            return ans;
        }
    }
    else if(y==x)
    {
        ans=1+x*(x-1);
        return ans;
    }
    else
    {
         if(x%2==0)
            {
                if(y<x)
                {
                    ans=get_value(1,x)+(y-1);
                    return ans;
 
                }
                else if(y>x)
                {
                    if(y%2==0)
                    {
                        ans=get_value(y,1)-(x-1);
                        return ans;
 
                    }
                    else
                    {
                        ans=get_value(y,1)+(x-1);
                        return ans;
 
                    }
                }
            }
             else
            {
                if(y<x)
                {
                    ans=get_value(1,x)-(y-1);
                    return ans;
 
                }
                else if(y>x)
                {
                    if(y%2==0)
                    {
                        ans=get_value(y,1)-(x-1);
                        return ans;
 
                    }
                    else
                    {
                        ans=get_value(y,1)+(x-1);
                        return ans;
 
                    }
                }
            }
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        ll y,x;
        cin>>y>>x;
        cout<<get_value(y,x)<<"\n";
        t-=1;
    }
}