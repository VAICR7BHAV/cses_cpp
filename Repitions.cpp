#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
int main()
{
	string s;
	cin>>s;
	int max=1,curr=1;
    for(int i=1;i<s.size();i++)
    {
        if(s[i-1]==s[i])
        {
            curr+=1;
        }
        else
        {
            {
                max=(curr>max)?curr:max;
                curr=1;
            }
        }
    }
    max=(curr>max)?curr:max;
    cout<<max;
}