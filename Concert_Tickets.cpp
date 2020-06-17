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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    multiset <ll> price;
    for(int i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        price.insert(temp);
    }
    //sort(price.begin(),price.end());
    
    for(int i=0;i<m;i++)
    {
        ll temp;
        cin>>temp;
        auto iter=price.upper_bound(temp);
        
        if(iter==price.begin())
        {
            cout<<-1<<'\n';
        }
        else
        {
            --iter;
            cout<<*(iter)<<'\n';
            price.erase(iter);
        }
    }
}