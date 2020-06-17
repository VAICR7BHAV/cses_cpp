#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type)) 
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = long long int;
const int MOD = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    if((n*(n+1))%4!=0)
    {
        cout<<"NO";
    }
    else
    {
        vector<int> set1;
        vector<int> set2;
        if(n%2==0)
        {
            int arr[n];
            for(int i=0;i<n;i++)
            {
                arr[i]=i+1;
            }
            for(int i=0;i<n/2;i++)
            {
                if(i%2==0)
                {
                    set1.push_back(arr[i]);
                    set1.push_back(arr[n-i-1]);
                }
                else
                {
                    set2.push_back(arr[i]);
                    set2.push_back(arr[n-i-1]);
                }
                
            }
        }
        else
        {
            set1.push_back(1);
            set1.push_back(2);
            set2.push_back(3);
            int arr[n-3];
            for(int i=0;i<n-3;i++)
            {
                arr[i]=i+4;
            }
            int size=my_sizeof(arr)/my_sizeof(arr[0]);
            for(int i=0;i<size/2;i++)
            {
                if(i%2==0)
                {
                    set1.push_back(arr[i]);
                    set1.push_back(arr[size-i-1]);
                }
                else
                {
                    set2.push_back(arr[i]);
                    set2.push_back(arr[size-i-1]);
                } 
            }
        }
        cout<<"YES\n";
        cout<<set1.size()<<'\n';
        for(int i=0;i<set1.size();i++)
        {
            cout<<set1[i]<<" ";
        }
        cout<<'\n'<<set2.size()<<'\n';
        for(int i=0;i<set2.size();i++)
        {
            cout<<set2[i]<<" ";
        }
    }
    
}