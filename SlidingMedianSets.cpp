#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define vect vector
# define pll pair<ll,ll>
# define pii pair<int,int>
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = long long int;
const int MOD = 1e9 + 7;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

void balance_sets(set<pii> &l,set<pii> &r)
{
    if(l.size()==r.size())
        return;
    if(l.size()==r.size()+1)
        return;
    if(l.size()+1==r.size())
    {
        auto itr=r.begin();
        l.insert(*itr);
        r.erase(*itr);
        return;
    }
    if(l.size()==r.size()+2)
    {
        auto itr=l.end();itr--;
        r.insert(*itr);
        l.erase(*itr);
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t-->0)
    {
        int n,k;
        cin>>n>>k;
        vect<int> x(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>x[i];
        }
        set<pii> L,R;
        for (int i = 0; i < k; ++i)
        {
            if(L.empty())
            {
                L.insert({x[i],i});
            }
            else
            {
                int max_of_L;
                auto itr=L.end();itr--;
                max_of_L=(*itr).F;
                if(x[i]<=max_of_L)
                {
                    L.insert({x[i],i});
                }
                else
                {
                    R.insert({x[i],i});
                }
            }
            balance_sets(L,R);
        }
        auto itr=L.end();itr--;
        cout<<(*itr).F<<" ";
        for(int i=k;i<n;i++)
        {
            L.erase({x[i-k],i-k});
            R.erase({x[i-k],i-k});
            balance_sets(L,R);
            if(L.empty())
            {
                L.insert({x[i],i});
            }
            else
            {
                int max_of_L;
                itr=L.end();itr--;
                max_of_L=(*itr).F;
                if(x[i]<=max_of_L)
                {
                    L.insert({x[i],i});
                }
                else
                {
                    R.insert({x[i],i});
                }
            }
            balance_sets(L,R);
            itr=L.end();itr--;
            cout<<(*itr).F<<" ";
        }
    }
}