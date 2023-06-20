//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
    stack<long long>s;
    vector<long long> leftsmaller;

    for (int i = 0; i < n; i++)
    {
        if (s.size()==0)
        {
            leftsmaller.push_back(-1);
        }
        else if (arr[s.top()]<arr[i])
        {
            leftsmaller.push_back(s.top());
        }
        else
        {
            while (s.size()!=0 and arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            if (s.size()==0)
            {
                leftsmaller.push_back(-1);
            }
            else
            {
                leftsmaller.push_back(s.top());
            }  
        }
        s.push(i);
    }
    
    while (!s.empty())
    {
        s.pop();
    }

    vector<long long> rightsmaller;
    for (int i = n-1; i >=0 ; i--)
    {
        if (s.size()==0)
        {
            rightsmaller.push_back(n);
        }
        else if (arr[s.top()]<arr[i])
        {
            rightsmaller.push_back(s.top());
        }
        else
        {
            while (s.size()!=0 and arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            if (s.size()==0)
            {
                rightsmaller.push_back(n);
            }
            else
            {
                rightsmaller.push_back(s.top());
            }  
        }
        s.push(i);
    }
    reverse(rightsmaller.begin(),rightsmaller.end());
    long long maxarea=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxarea=max(maxarea, (arr[i]*(rightsmaller[i]-leftsmaller[i]-1)));
    }
    
    return maxarea;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends