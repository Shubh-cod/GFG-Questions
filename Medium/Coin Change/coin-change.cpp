//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
// Coin Change 2


long long int count_rec(int coins[],int N,int sum,vector<vector<long long int>> &dp)
{
    if (N==0 and sum==0)
    {
        return 1;
    }

    if (N==0)
    {
        return 0;
    }

    if (dp[N][sum]!=-1)
    {
        return dp[N][sum];
    }
    
    
    if (coins[N-1]<=sum)
    {
        return dp[N][sum]=count_rec(coins,N,sum-coins[N-1],dp)+count_rec(coins,N-1,sum,dp);
    }
    
    return dp[N][sum]=count_rec(coins,N-1,sum,dp);
    
}

long long int count(int coins[], int N, int sum)
{
    vector<vector<long long int>>dp(N+1,vector<long long int>(sum+1,-1));
    return count_rec(coins,N,sum,dp);
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends