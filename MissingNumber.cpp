#include<iostream>
using namespace std;
using ll = long long int;
int main()
{
	ll n;
	cin>>n;
	ll val=((n+1)*n)/2;
	ll sum=0;
	for(int i=0;i<n-1;i++)
	{
		ll temp;
		cin>>temp;
		sum+=temp;
	}
	cout<<(val-sum);
}