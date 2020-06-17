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
    ll x,n;
    cin>>x>>n;
    ll p[n];
    for(int i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        p[i]=temp;
    }
    set<ll> position;
    position.insert(0);
    position.insert(x);
    multiset<ll> difference;
    difference.insert(x);
    for(int i=0;i<n;i++)
    {
        ll temp=p[i];
        position.insert(temp);
        auto pos=position.find(temp);
        ll curr=*pos;
        auto itr2=pos;
        itr2--;
        ll prev=*itr2;
        itr2=pos;
        itr2++;
        ll next=*itr2;
        difference.erase(difference.find(next-prev));
        difference.insert(curr-prev);
        difference.insert(next-curr);
        itr2=difference.end();
        itr2--;
        cout<<*itr2<<" ";
    }
}