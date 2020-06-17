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
    vector <pair<int,int>> dur_dead;
    for (int i = 0; i < n; i++)
    {
        int tempa,tempd;
        cin>>tempa>>tempd;
        dur_dead.push_back(make_pair(tempa,tempd));
    }
    sort(dur_dead.begin(),dur_dead.end());
    ll curr=0,score=0;
    REP(i,0,n-1)
    {
        curr+=dur_dead[i].F;
        score+=dur_dead[i].S-curr;
    }
    cout<<score;
}