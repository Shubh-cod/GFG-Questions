//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
int maxipoint_rec(vector<vector<int>> &points, int n,int lastdone,vector<vector<int>>&dp){
    if (n == 0)
    {
        return 0;
    }
    if (n == 1 and lastdone==0)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }

    if (dp[n][lastdone]!=-1)
    {
        return dp[n][lastdone];
    }
    
    int ans = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        if (i+1!=lastdone)
        {
            ans=max(ans,points[n-1][i]+maxipoint_rec(points,n-1,i+1,dp));
        }
    }
    dp[n][lastdone]=ans;
    return dp[n][lastdone];
}

int maximumPoints(vector<vector<int>> &points, int n)
{
    vector<vector<int>>dp(n+1,vector<int>(4,-1));
    return (maxipoint_rec(points,n,0,dp));
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends