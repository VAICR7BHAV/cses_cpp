#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = long long int;
const int MOD = 1e9 + 7;
int solve(int x,int c[],int n)
{
    if(x==0)
        return 0;
    if(x<0)
    {
        return 10e6;
    }
    int best=10e6;
    REP(i,0,n-1)
    {
        best=min(best,solve(x-c[i],c,n)+1);
    }
    return best;
}
int main()
{
    int n,x;
    cin>>n>>x;
    int c[n];
    REP(i,0,n-1)
    {
        int temp;
        cin>>temp;
        c[i]=temp;
    }
    int value[x+1];
    value[0]=1;
    for(int i=1;i<=x;i++)
    {
            value[i]=0;
            for(auto coin:c)
            {
                if(i-coin>=0)
                {
                    value[i]+=value[i-coin];
                    value[i]%=MOD;
                }
            }
    }
    // REP(i,0,x)
    // {
    //     cout<<value[i]<<" "<<endl;
    // }
    if(value[x]==10e6)
    {
        cout<<-1;
    }
    else
    {
        cout<<value[x];
    }
}