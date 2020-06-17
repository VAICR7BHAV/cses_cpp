#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = long long int;
const int MOD = 1e9 + 7;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> events;
    while(n>0)
    {
        int a,b;
        cin>>a>>b;
        events.push_back(make_pair(a,0));
        events.push_back(make_pair(b,1));
        n-=1;
    }
    sort(events.begin(),events.end());
    int count=0,maxi=0;
    for(int i=0;i<events.size();i++)
    {
        if(events[i].S==0)
        {
            count+=1;
        }
        else
        {
            count-=1;
        }
        maxi=max(count,maxi);
    }
    cout<<maxi<<endl;
}