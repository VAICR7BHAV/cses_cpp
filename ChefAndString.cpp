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
        string s,ls,rs;
        cin>>s;
        ls=s.substr(1,s.size())+s[0];
        rs=s[s.size()-1]+s.substr(0,s.size()-1);
        if(ls==rs)
        {
            cout<<"YES"<<endl;;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        
        t-=1;
    }
}