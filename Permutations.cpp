#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
int main()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"1";
    }
    else if(n==2)
    {
        cout<<"NO SOLUTION";
    }
    else if(n==3)
    {
        cout<<"NO SOLUTION";
    }
    else
    {
        string s1="",s2="";
        for(int i=1;i<=n;i++)
        {
            if(i%2==0)
            {
                s1+=to_string(i)+" ";
            }
            else
            {
                s2+=to_string(i)+" ";
            }
        }
        cout<<s1+s2;
    }
    
}