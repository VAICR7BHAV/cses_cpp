#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define REP(i,a,b) for(int i=a;i<=b;i++)
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
using ll = long long int;
const int MOD = 1e9 + 7;

ll modpow(ll a, ll n, ll m = MOD) {
    ll r = 1;
    for (;n;n>>=1) {
        if (n&1) r = r*a%m;
        a = a*a%m;
    }
    return r;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    ll S=(n*(n+1))/2;
    if(S%2!=0)
    {
        cout<<0;
    }
    else
    {
        ll ub=S/2;
        ll dp[n+1][ub+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=ub;j++)
            {
                dp[i][j]=0;
            }
        }
        dp[0][0]=0ll;
        for (int i = 1; i <= n; ++i)
        {
            dp[i][0]=1ll;
        }
        for(int i=1;i<=ub;i++)
        {
            dp[0][i]=0ll;
            dp[1][i]=0ll;
        }
        dp[1][1]=1ll;
        for(int i=2;i<=n;i++)
        {
            for (int j = 0; j <=ub ; ++j) {
                if(j-i>=0)
                {
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-i];
                    dp[i][j]%=MOD;
                } else
                {
                    dp[i][j]=dp[i-1][j];
                    dp[i][j]%=MOD;
                }
//                if((i*(i+1))/2==j)
//                {
//                    dp[i][j]+=1;
//                }
            }
        }
//        for (int i = 0; i<= n; ++i) {
//            for (int j = 0; j <=ub ; ++j) {
//                cout<<dp[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        ll mod_inv=modpow(2,MOD-2,MOD);
        cout<<((dp[n][ub])*mod_inv)%MOD;
    }
}