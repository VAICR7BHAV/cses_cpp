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
    vector <int> steps(n+1,10e6);
    for(int i=0;i<10;i++)
    {
        steps[i]=1;
    }
    for(int i=10;i<=n;i++)
    {
        int j=i;
        
        while(j!=0)
        {
            int last=j%10;
            j=j/10;
            if(last!=0)
            {
                steps[i]=min(steps[i],1+steps[i-last]);
            }
        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     cout<<steps[i]<<" ";
    // }
    cout<<steps[n];
}