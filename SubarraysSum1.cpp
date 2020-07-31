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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t-->0)
    {
        ll n,x;
        cin>>n>>x;
        vect<ll>a(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            ll sum_temp=a[i];
            if(sum_temp==x)
                count+=1;
            for(int j=i+1;j<n;j++)
            {
                sum_temp+=a[j];
                if(sum_temp==x)
                {count+=1;break;}
            }
        }
        if(a[n-1]==x)
            count+=1;
        cout<<count;
    }
}