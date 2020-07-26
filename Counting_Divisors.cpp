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
int power_of_number(int num,int p)
{
    int count=0;
    while(num>0)
    {
        if(num%p==0)
        {
            count+=1;
            num=num/p;
        } else
        {
            break;
        }
    }
    return count;
}
int ma=1e6;
vector<char> is_prime(ma+1,true);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    is_prime[0]=false;
    is_prime[1]=false;
    for (int i = 2; i <= ma; i++)
    {
        if (is_prime[i] && (long long)i * i <= ma)
        {
            for (int j = i * i; j <= ma; j += i)
                is_prime[j] = false;
        }
    }
    int n;
    cin>>n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        ll n_o_d=1;
        if(is_prime[x])
            n_o_d=2;
        else{
            for (int j = 2; j <= x; j++)
            {
                if (is_prime[j] && (long long)j * j <= x)
                {
                    int pow=power_of_number(x,j);
                    if(pow!=0)
                    n_o_d*=pow+1;
                }
            }
        }
        cout<<n_o_d<<'\n';
    }

}