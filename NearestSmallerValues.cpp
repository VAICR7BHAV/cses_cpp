#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define vect vector
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = int;
const int MOD = 1e9 + 7;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t-->0)
    {
        ll n;
        cin>>n;
        vect<ll> x(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>x[i];
        }
        stack<ll> st;
        ll ans[n];
        ans[0]=0;
        st.push(1);
        for(int i=1;i<n;i++)
        {
            while(!st.empty())
            {
                if(x[st.top()-1]>=x[i])
                    st.pop();
                else
                {
                    break;
                }
            }
            if(st.empty())
            ans[i]=0;
            else
                ans[i]=st.top();
            st.push(i+1);
        }
        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
    }
}