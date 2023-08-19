//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
bool issubsetsum(int n, int sum, int nums[],vector<vector<int>>&dp)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                dp[i][j] = false;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (nums[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - nums[i - 1]] or dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int minDifference(int arr[], int n)
{
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    issubsetsum(n,sum,arr,dp);
    int mini=INT_MAX;
    for (int i = 0; i < sum; i++)
    {
        if (dp[n][i]==1)
        {
            mini=min(mini,abs(sum-2*i));
        }
        
    }
    
    return mini;
}
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends