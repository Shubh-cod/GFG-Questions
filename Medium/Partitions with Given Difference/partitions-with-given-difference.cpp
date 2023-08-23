//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
int subsetwithgivensum(int n,vector<int> &arr,int sum,vector<vector<int>> &dp)
{
    if (n==0 and sum==0)
    {
        return 1;
    }

    if (n==0)
    {
        return 0;
    }

    if (dp[n][sum]!=-1)
    {
        return dp[n][sum]%1000000007;
    }
    

    if (arr[n-1]<=sum)
    {
        return dp[n][sum]=(subsetwithgivensum(n-1,arr,sum-arr[n-1],dp)%1000000007+subsetwithgivensum(n-1,arr,sum,dp)%1000000007)%1000000007;
    }
    
    return dp[n][sum]=subsetwithgivensum(n-1,arr,sum,dp)%1000000007;
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int sumarr = 0;
    for (int i = 0; i < n; i++)
    {
        sumarr += arr[i];
    }

    if ((sumarr + d) % 2 == 1)
    {
        return 0;
    }

    int sum = (sumarr + d) / 2;
    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
    return subsetwithgivensum(n, arr, sum,dp);
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends