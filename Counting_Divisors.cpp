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

int count_number_of_divisors(int num)
{
    int count=0;
    for (int i = 1; i <= num; ++i) {
        if(num%i==0)
        {
            count+=1;
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    while(n-->0)
    {
        int x;
        cin>>x;
        cout<<count_number_of_divisors(x)<<'\n';
    }
}