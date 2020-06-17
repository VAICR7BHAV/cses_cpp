#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
map<int,ll> mp;
int get_min_steps(int n,ll curr_steps)
{
    //cout<<n<<endl;
    if(n==0)
    {
        return curr_steps;
    }
    if(n<10 && n>0)
    {
        curr_steps+=1;
        return curr_steps;
    }
    string num=to_string(n);
    if(mp[n]==0)
    {
        ll steps[num.size()];
        for(int i=0;i<num.size();i++)
        {
            //cout<<"num[i]="<<num[i]<<endl;
            // string temp=""+num[i];
            // cout<<"temp= "<<temp<<endl;
            // int nu=stoi(temp);
            if(num[i]=='0')
            continue;
            int nu=(int)num[i]-48;
            //cout<<"nu="<<nu<<" "<<n-nu<<endl;
            steps[i]=get_min_steps(n-nu,curr_steps+1);
        }
        int size= sizeof(steps) / sizeof(steps[0]); 
        ll ans=*min_element(steps,steps+size);
        mp[n]=ans;
        return(ans);
    }
    else
    {
        curr_steps+=mp[n];
        return curr_steps;
    }
    
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<10;i++)
    {
        mp[i]=1;
    }
    for(int i=10;i<=n;i++)
    {
        mp[i]=get_min_steps(i,0);
    }
    // for(auto i=mp.begin();i!=mp.end();i++)
    // {
    //     cout<<i->first<<" "<<i->second<<endl;
    // }
    cout<<mp[n];    
}