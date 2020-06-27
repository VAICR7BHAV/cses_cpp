#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = long long int;
const int MOD = 1e9 + 7;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
const ll INF=1e12;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    ll d[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i==j)
            {
                d[i][j]=0;
            } else
            {
                d[i][j]=INF;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int a,b;ll c;
        cin>>a>>b>>c;
        if(c<d[a-1][b-1]) {
            d[a - 1][b - 1] = c;
            d[b - 1][a - 1] = c;
        }
    }
    int qa[q],qb[q];
    for (int i = 0; i < q; ++i) {
        int a,b;
        cin>>a>>b;
        qa[i]=a;qb[i]=b;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        int a,b;
        a=qa[i];b=qb[i];
        ll ans=d[a-1][b-1];
        if(ans==INF)
        {
            cout<<-1<<'\n';
        }
        else
        cout<<d[a-1][b-1]<<'\n';
    }
}