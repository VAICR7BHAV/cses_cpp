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
    //Priority Queue to implement min heap.
    priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
    int k=0;
    //A vector that keeps track of the room assigned to the traveller at i'th position
    //first number of pair is the i'th position and the second one is the room assigned
    vector<pair<ll,ll>> room_allocation;

    // Stack with 10e5 rooms in reverse order. So whenever we need an empty room and all the 
    // other room are occupied we can pop one from the stack. 
    stack<int> current_free_room;
    for(int i=100000;i>=1;i--)
    {
        current_free_room.push(i);
    }
    //vector to store the pair(b,a) along with the position, so that the position doesn't get lost
    //while sorting according to the earliest finishing time
    vector<pair<pair<ll,ll>,int>> abi;
    for(int i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        abi.push_back(make_pair(make_pair(a,b),i));
    }
    // sorting according to the earliest finish time. The passenger with the earliest finish time
    // is allocated the room first.
    sort(abi.begin(),abi.end());
    for(int i=0;i<n;i++)
    {
        ll a,b;
        b=abi[i].first.second;
        a=abi[i].first.first;
        //if heap is empty allocate the room by popping up a room from stack
        // Allocate the room to the i'th passenger and store in the room allocation vector
        if(pq.empty())
        {
            pq.push(make_pair(b,current_free_room.top()));
            room_allocation.push_back(make_pair(abi[i].second,current_free_room.top()));
            current_free_room.pop();
            //Keep track of the maximum heap size throughout the entire process. we would
            // minimum those many rooms
            int size=pq.size();
            k=max(k,size);
        }
        else
        {
            //Get the passenger with minimum finishing time and check if it is less than the 
            //arrival time of the next incoming passenger. If yes then we can pop that out
            //from the heap and the room occupied by the passenger that is just popped out from
            //the heap is added into the stack of current_free_room so we can allocate the same
            //room to an incoming passenger by simply popping from the stack
            ll top=pq.top().first;
            if(top<a)
            {
                current_free_room.push(pq.top().second);
                pq.pop();
                pq.push(make_pair(b,current_free_room.top()));
                
                room_allocation.push_back(make_pair(abi[i].second,current_free_room.top()));
                current_free_room.pop();
                int size=pq.size();
                k=max(k,size);
            }
            //If the minimum finish time in the heap is still greater than the arrical time of 
            // next passenger we have no choice but to get a new room from the stack
            else
            {
                pq.push(make_pair(b,current_free_room.top()));    
                room_allocation.push_back(make_pair(abi[i].second,current_free_room.top()));
                current_free_room.pop();
                int size=pq.size();
                k=max(k,size);    
            } 
        }  
    }
    cout<<k<<'\n';
    //Sorted based on the order of incoming of passengers.
    sort(room_allocation.begin(),room_allocation.end());
    for(int i=0;i<room_allocation.size();i++)
    {
        cout<<room_allocation[i].second<<" ";
    }
}