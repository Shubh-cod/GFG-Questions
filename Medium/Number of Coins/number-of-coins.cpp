//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
int mincoins_rec(int coins[], int M, int V, vector<vector<int>> &dp)
{
    if (V == 0)
    {
        return 0;
    }

    if (M == 0)
    {
        return 1E9;
    }
    if (dp[M][V]!=-1)
    {
        return dp[M][V];
    }
    

    int ans = 1E9;
    if (coins[M - 1] <= V)
    {
        ans = min(ans, 1 + mincoins_rec(coins, M , V - coins[M - 1], dp));
        ans = min(ans, mincoins_rec(coins, M - 1, V, dp));
    }

    else
    {
        ans = min(ans, mincoins_rec(coins, M - 1, V, dp));
    }

    return dp[M][V]=ans;
}
int minCoins(int coins[], int M, int V)
{
    vector<vector<int>>dp(M+1,vector<int>(V+1,-1));
    if(mincoins_rec(coins,M,V,dp)==1E9){
        return -1;
    }
    
    return mincoins_rec(coins,M,V,dp);

}

	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends