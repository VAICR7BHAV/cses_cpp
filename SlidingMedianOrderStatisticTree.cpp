#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
        indexed_set<pii> se;
        for (int i = 0; i < k; ++i)
        {
            se.insert({x[i],i});
        }
//        for(auto itr=se.begin();itr!=se.end();itr++)
//            cout<<(*itr).F<<" ";
//        cout<<'\n';
        cout<<(*se.find_by_order((k-1)/2)).F<<" ";
        for(int i=k;i<n;i++)
        {
            se.erase({x[i-k],i-k});
            se.insert({x[i],i});
            cout<<(*se.find_by_order((k-1)/2)).F<<" ";
        }
    }

}