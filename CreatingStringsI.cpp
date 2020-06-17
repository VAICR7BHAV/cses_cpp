#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
int main()
{
    string str1;
    cin>>str1;
    sort(str1.begin(),str1.end());
    vector<string> result;
    do
    {
        result.push_back(str1);
    } while (next_permutation(str1.begin(),str1.end()));
    cout<<result.size()<<endl;
    for(auto itr=result.begin();itr!=result.end();itr++)
    {
        cout<<*itr<<endl;
    }
}