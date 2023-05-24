//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
   public:
    int findSum(int A[], int N)
    {
    int maxi=INT_MIN;
    int mini=INT_MAX;
    int i=-1;
    if (N%2==0)
    {
        if (A[0]>A[1])
        {
            maxi=A[0];
            mini=A[1];
        }
        else
        {
            maxi=A[1];
            mini=A[0];
        }
        i=2;
    }
    else
    {
        maxi=A[0];
        mini=A[0];
        i=1;
    }
    
    while (i<N-1)
    {
        int pairMax=INT_MIN;
        int pairMin=INT_MAX;
        pairMax=max(A[i],A[i+1]);
        pairMin=min(A[i],A[i+1]);
        mini=min(pairMin,mini);
        maxi=max(pairMax,maxi);  
        i=i+2;
    }
    
    return maxi+mini;
    }

};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.findSum(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends