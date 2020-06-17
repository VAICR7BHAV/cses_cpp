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
	ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int k[n];
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        k[i]=temp;
    }
    sort(k,k+n);
    set<int> sum_values;
    for(int i=0;i<n;i++)
    {
        //cout<<"loop "<<i<<endl;
        if(sum_values.size()!=0)
        {
            vector<int> temp;
            for(auto x:sum_values)
            {
                //cout<<"x ="<<x<<' ';
                temp.push_back(x);
            }
            //cout<<endl;
            for(int j=0;j<temp.size();j++)
            {   
                //cout<<temp[j]<<' ';
                sum_values.insert(temp[j]+k[i]);
            }
            //cout<<endl;
        }
        sum_values.insert(k[i]);
    }
    cout<<sum_values.size()<<'\n';
    for(auto x:sum_values)
    {
        cout<<x<<' ';
    }
}