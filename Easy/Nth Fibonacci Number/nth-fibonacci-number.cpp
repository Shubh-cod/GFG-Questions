//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
int fib(int n,vector<int> &dp)
{
    if (n==0)
    {
        dp[0]=0;
        
    }
    if (n==1)
    {
        dp[1]=1;
        
    }

    if (dp[n]==-1)
    {
        dp[n]=(fib(n-1,dp)%1000000007) + (fib(n-2,dp)%1000000007);  
    }
    
    return (dp[n]%1000000007);
    
}

int nthFibonacci(int n)
{
    vector<int> dp(n+1,-1);
    return (fib(n,dp)%1000000007);
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends