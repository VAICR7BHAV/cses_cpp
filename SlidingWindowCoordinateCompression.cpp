#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define vect vector
# define pll pair<ll,ll>
# define pii pair<int,int>
# define map unordered_map
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = long long int;
const int MOD = 1e9 + 7;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
void build(vector<ll>&a,int v,int tl,int tr,vector<ll>&t)
{
    if(tl==tr)
    {
        t[v]=a[tl];
    }
    else
    {
        int tm=(tl+tr)/2;
        build(a,2*v,tl,tm,t);
        build(a,2*v+1,tm+1,tr,t);
        t[v]=t[2*v]+t[2*v+1];
    }
}
ll sum(int v,int tl,int tr,int l,int r,vector<ll>&t)
{
    if(l>r)
        return 0;
    if(l==tl && r==tr)
    {
        return t[v];
    }
    int tm=(tl+tr)/2;
    return sum(2*v,tl,tm,l,min(r,tm),t)+sum(2*v+1,tm+1,tr,max(l,tm+1),r,t);
}
void update(int v,int tl,int tr,int pos,ll new_val,vector<ll>&t)
{
    if(tl==tr)
    {
        t[v]=new_val;
    }
    else
    {
        int tm=(tl+tr)/2;
        if(pos<=tm)
        {
            update(2*v,tl,tm,pos,new_val,t);
        }
        else
        {
            update(2*v+1,tm+1,tr,pos,new_val,t);
        }
        t[v]=t[2*v]+t[2*v+1];
    }
}
int bin_search_pos(vect<ll>&tree,int freq_size,int to_find)
{
    int lb=0,ub=freq_size-1;
    while(lb<=ub)
    {
        int mid=(lb+ub)/2;
        if(sum(1,0,freq_size-1,0,mid,tree)<to_find)
            lb=mid+1;
        else
            ub=mid-1;
    }
    //cout<<"lower bound is "<<lb<<'\n';
    return lb;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t-->0)
    {
        int n,k;
        cin>>n>>k;
        vector<int> x(n);
        map<ll,ll> visited;
        vector<int> unique_values;
        for(int i=0;i<n;i++)
        {
            cin>>x[i];
            if(visited.find(x[i])==visited.end())
            {
                unique_values.push_back(x[i]);
            }
            visited[x[i]]+=1;
        }
        sort(unique_values.begin(),unique_values.end());
        map<int,int> mapped_values;
        map<int,int> unmapped_values;
        for(int i=0;i<unique_values.size();i++)
        {
            mapped_values[unique_values[i]]=i+1;
            unmapped_values[i+1]=unique_values[i];
        }
        vector<int> mapped_arr(n);
        for(int i=0;i<n;i++)
        {
            mapped_arr[i]=mapped_values[x[i]];
        }
        vect<ll> freq_arr(3*1e5,0);int count=0;
        for(int i=0;i<n;i++)
        {
            //cin>>x[i];
            if(count<k)
            {
                freq_arr[mapped_arr[i]-1]+=1;count+=1;
            } else
                break;
        }

        int freq_size=freq_arr.size();
        vector<ll>tree(4*freq_size);
        build(freq_arr,1,0,freq_size-1,tree);
        cout<<unmapped_values[bin_search_pos(tree,freq_size,k-k/2)+1]<<" ";
        for(int i=k;i<n;i++)
        {
            freq_arr[mapped_arr[i]-1]+=1;
            update(1,0,freq_size-1,mapped_arr[i]-1,freq_arr[mapped_arr[i]-1],tree);
            freq_arr[mapped_arr[i-k]-1]-=1;
            update(1,0,freq_size-1,mapped_arr[i-k]-1,freq_arr[mapped_arr[i-k]-1],tree);
            cout<<unmapped_values[bin_search_pos(tree,freq_size,k-k/2)+1]<<" ";
        }
    }
}