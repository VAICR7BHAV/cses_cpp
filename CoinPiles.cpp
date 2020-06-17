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
        ll a,b;
        cin>>a>>b;
        
           
            if(a==0)
            {
                if(b!=0)
                {
                    cout<<"NO\n";
                }
                else
                {
                   cout<<"YES\n";
                }
                t-=1;
                continue;
            }
            if(b==0)
            {
                if(a!=0)
                    cout<<"NO\n";
                t-=1;
                continue;
            }
            ll temp1=(2*a-b)%3;
            ll temp2=(2*b-a)%3;
 
            if(temp1==0 && temp2==0 && (2*a-b)>=0 && (2*b-a)>=0)
                cout<<("YES\n");
            else
                cout<<("NO\n");
        t-=1;
    }
}