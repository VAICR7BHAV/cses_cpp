#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = unsigned long long int;
const int MOD = 1e9 + 7;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
ll find_min(vector<ll> vect)
{
    ll mini=vect[0];
    for (ll & i : vect) {
        mini=min(i,mini);
    }
    return mini;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,q;
    cin>>n>>q;
    vector<ll> x(n);
    vector<vector<ll>> sqrt_dec;
    for (ll i = 0; i < n; ++i)
    {
        cin>>x[i];
    }
    ll sqr=(ll)sqrt(n)+1;
    ll count=0;vector<ll> temp;
    unordered_map<int,int> block_number;int bno=0;
    for(ll i=0;i<n;i++)
    {
        block_number[i]=bno;
        temp.push_back(x[i]);
        count+=1;
        if(count==sqr)
        {

            count=0;sqrt_dec.push_back(temp);bno++;temp.clear();
        }
    }
    if(!temp.empty())
        sqrt_dec.push_back(temp);
    temp.clear();
    vector<ll> mini_for_each_block;
    for (ll j = 0; j < sqrt_dec.size(); ++j)
    {
        mini_for_each_block.push_back(find_min(sqrt_dec[j]));
    }
    while(q-->0)
    {
        ll a,b,type;cin>>type>>a>>b;
        if(type==1)
        {
            x[a-1]=b;
            ll block_for_a=block_number[a-1];
            sqrt_dec[block_for_a][a-block_for_a*sqr-1]=b;
            mini_for_each_block[block_for_a]=find_min(sqrt_dec[block_for_a]);
        }
        else if(type==2)
        {
            ll block_for_a=block_number[a-1];
            ll block_for_b=block_number[b-1];
            if(block_for_a==block_for_b || block_for_b-block_for_a<=2)
            {
                ll mini=x[a-1];
                for (ll i = a-1; i <b ; ++i)
                {
                    mini=min(mini,x[i]);
                }
                cout<<mini<<'\n';
            }
            else
            {
                ll mini_in_block_of_a=x[a-1];
                for(ll i=a-1;i<(block_for_a+1)*sqr;i++)
                {
                    mini_in_block_of_a=min(mini_in_block_of_a,x[i]);
                }
                ll mini_in_block_of_b=x[b-1];

                for(ll i=block_for_b*sqr;i<b;i++)
                {
                    mini_in_block_of_b=min(mini_in_block_of_b,x[i]);
                }
                ll mini_overall=min(mini_in_block_of_a,mini_in_block_of_b);

                for (ll j = block_for_a+1; j <block_for_b ; ++j)
                {
                    mini_overall=min(mini_overall,mini_for_each_block[j]);
                }
                cout<<mini_overall<<'\n';
            }
        }
    }
}