//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
int minEnergy(int i,vector<int>& height,int n,vector<int>&dp)
{
    if (n-1==0)
    {
        dp[0]=0;
        return 0;
    }
    if (n-1==1)
    {
        dp[1]=abs(height[i]-height[i+1]);
        return abs(height[i]-height[i+1]);
    }

    if (dp[n-1]!=-1)
    {
        return dp[n-1];
    }
    int t1= abs(height[i]-height[i+1])+minEnergy(i+1,height,n-1,dp);
    int t2= abs(height[i]-height[i+2])+minEnergy(i+2,height,n-2,dp);
    dp[n-1]=min(t1,t2);
    return dp[n-1];    
}


int minimumEnergy(vector<int> &height, int n)
{
    vector<int>dp(n,-1);
    return minEnergy(0,height,n,dp);
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends