//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
    long long int low=0;
    long long int high=x;
    long long int ans=-1;
    while (low<=high)
    {
        long long int mid = low+(high-low)/2;
        if (mid*mid >x )
        {
            high=mid-1;
        }
        else if (mid*mid<x)
        {
            ans=mid;
            low=mid+1;
        }
        else
        {
            return mid;
        }  
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends