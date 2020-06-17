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
    int x;
    cin>>x;
    int price[n];
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        price[i]=temp;
    }
    int pages[n];
    vector<pair<int,int>> price_page;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        pages[i]=temp;
        price_page.push_back(make_pair(price[i],pages[i]));
    }
    sort(price_page.begin(),price_page.end());
    for(int i=0;i<n;i++)
    {
        price[i]=price_page[i].F;
        pages[i]=price_page[i].S;
    }
    // for(int i=0;i<n;i++)
    // {
    //     cout<<price[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     cout<<pages[i]<<" ";
    // }
    // cout<<endl;
    int answer[n+1][x+1];
    for(int i=0;i<=x;i++)
    {
        answer[0][i]=0;
    }
    for(int i=0;i<=n;i++)
    {
        answer[i][0]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            if(j-price[i-1]>=0)
            answer[i][j]=max(answer[i-1][j],answer[i-1][j-price[i-1]]+pages[i-1]);
            else
            {
                answer[i][j]=answer[i-1][j];
            }
            
        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=x;j++)
    //     {
    //         cout<<answer[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<answer[n][x];
}