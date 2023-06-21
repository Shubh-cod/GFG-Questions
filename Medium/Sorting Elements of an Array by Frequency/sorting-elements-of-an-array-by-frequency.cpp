#include <iostream>
#include <queue>
#include <stack>

#include <bits/stdc++.h> 
using namespace std;

class myComparator{
public:
    int operator()(pair<int,int>& p1, pair<int,int>& p2){

        if(p1.first<p2.first)
            return true;
        else if(p1.first>p2.first)
            return false;
        else{
            if(p1.second>p2.second)
                return true;
            else return false;
        }

    }
};
int main() {
	//code
	
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	    map<int,int>mp;
	    for(int i=0;i<n;i++)
	    mp[arr[i]]++;
	    
	    priority_queue<pair<int,int>,vector<pair<int,int>>,myComparator>q;
	    
	    for(auto i=mp.rbegin();i!=mp.rend();i++)
	    {
	        q.push({i->second,i->first});
	    }
	    
	    while(!q.empty())
	    {
	        int x=q.top().first;
	        int p=q.top().second;
	        while(x!=0)
	        {
	            x--;
	            cout<<p<<" ";
	        }
	        q.pop();
	    }
	    cout<<endl;
	}
	return 0;
}