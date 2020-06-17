#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;
int main()
{
    string st;
    cin>>st;
    map<char,int> d;
    
    for(int i=0;i<st.size();i++)
    {
        d[st[i]]+=1;
    }
    int odd_count=0;
    bool possible=false,single_odd=false;
    char single_odd_key=' ';
    string str1="";
    map<char, int>::iterator itr;
    for (itr = d.begin(); itr != d.end(); ++itr)
    {
        
        if(itr->second%2!=0)
        {
            odd_count+=1;
            if(odd_count==2)
            {
                possible=false;
                break;
            }
            else
            {
                single_odd_key=itr->first;
                possible=true;
                single_odd=true;
            }
        }
        else
        {
            for(int j=0;j<itr->second/2;j++)
            {
                str1+=itr->first;
            }
            possible=true;
        }
    } 
    if(possible)
    {
        if(single_odd)
        {
            string temp_str="";
            for(int i=0;i<d[single_odd_key];i++)
            {
                temp_str+=single_odd_key;
            }
            string final_str=str1+temp_str;
            reverse(str1.begin(),str1.end());
            final_str=final_str+str1;
            cout<<final_str<<'\n';
        }
        else
        {
            string final_str=str1;
            reverse(str1.begin(),str1.end());
            final_str=final_str+str1;
            cout<<final_str<<'\n';
        }
        
    }
    else
    {
        cout<<"NO SOLUTION\n";
    }
    
}