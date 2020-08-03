#include <bits/stdc++.h>

using namespace std;
# define M_PI 3.14159265358979323846
# define epsi 1e-9
# define F first
# define S second
# define vect vector
# define pll pair<ll,ll>
# define pii pair<int,int>
# define REP(i,a,b) for(int i=a;i<=b;i++)
using ll = int;
const int MOD = 1e9 + 7;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
struct Vertex
        {
    ll left, right;
    ll sum = 0;
    Vertex *left_child = nullptr, *right_child = nullptr;

    Vertex(ll lb, ll rb) {
        left = lb;
        right = rb;
    }

    void extend() {
        if (!left_child && left + 1 < right) {
            ll t = (left + right) / 2;
            left_child = new Vertex(left, t);
            right_child = new Vertex(t, right);
        }
    }

    void add(ll k, ll x) {
        extend();
        sum += x;
        if (left_child)
        {
            if (k < left_child->right)
                left_child->add(k, x);
            else
                right_child->add(k, x);
        }
    }

    ll get_sum(ll lq, ll rq)
    {
        if (lq <= left && right <= rq)
            return sum;
        if (max(left, lq) >= min(right, rq))
            return 0;
        extend();
        return left_child->get_sum(lq, rq) + right_child->get_sum(lq, rq);
    }
};
ll find_pos(Vertex *root, ll to_find)
{
    if(root->left_child== nullptr && root->right_child== nullptr)
        return root->left;
    if(root->left_child->sum>=to_find)
        return find_pos(root->left_child,to_find);
    else if(root->left_child->sum<to_find)
    {
        return find_pos(root->right_child,to_find-(root->left_child->sum));
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vect<ll> x(n);ll maxi_num=0;
    for (int i = 0; i < n; ++i)
    {
        cin>>x[i];maxi_num=max(maxi_num,x[i]);
    }
    auto *root= new Vertex(0,maxi_num+1);
    for(int i=0;i<k;i++)
    {
        root->add(x[i],1);
    }
    cout<<find_pos(root,k-k/2)<<" ";
    for(int i=k;i<n;i++)
    {
        root->add(x[i],1);
        root->add(x[i-k],-1);
        cout<<find_pos(root,k-k/2)<<" ";
    }
}