    #include <bits/stdc++.h>

    using namespace std;
    # define M_PI 3.14159265358979323846
    # define epsi 1e-9
    # define F first
    # define S second
    # define REP(i,a,b) for(int i=a;i<=b;i++)
    using ll = int;
    const int MOD = 1e9 + 7;
    # define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll n,q;
        cin>>n>>q;
        vector<ll> x(n);ll maxi=INT16_MIN;
        for (int i = 0; i < n; ++i)
        {
            cin>>x[i];maxi=max(maxi,x[i]);
        }
        maxi+=1;
        //creating the sparse table
        //int k=floor(log2(n));
        int k= 31 - __builtin_clz(n);
        ll sparse_table[k+1][n];//cell (i,j) gives the minimum value for range
        //between [j,j+2^i)
        for(int i=0;i<n;i++)
            sparse_table[0][i]=x[i];
        for(int i=1;i<k+1;i++)
        {
            for (int j = 0; j < n; ++j)
            {
                //ll pow2=(ll)pow(2,i-1);
                ll pow2=1<<(i-1);
                if((j+pow2)<n)
                sparse_table[i][j]=min(sparse_table[i-1][j],sparse_table[i-1][j+pow2]);
                else
                    sparse_table[i][j]=maxi;
            }
        }
        while(q-->0)
        {
            int l,r;
            cin>>l>>r;int len=r-l+1;
            //int p=(int)floor(log2(len));
            int p= 31 - __builtin_clz(len);
            //ll K=(ll)pow(2,p);
            ll K=1<<p;
            cout<<min(sparse_table[p][l-1],sparse_table[p][r-1-K+1])<<'\n';
        }
    }