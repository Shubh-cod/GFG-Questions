//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
int minimizesum_rec(int n,int x, int y, vector<vector<int>> &triangle,vector<vector<int>>&dp)
{
    if (x==n-1)
    {
        return triangle[x][y];
    }
    if (dp[x][y]!=-1)
    {
        return dp[x][y];
    }
    

    int same=triangle[x][y]+minimizesum_rec(n,x+1,y,triangle,dp);
    int next=triangle[x][y]+minimizesum_rec(n,x+1,y+1,triangle,dp);

    return dp[x][y]= min(same,next);
    
}

int minimizeSum(int n, vector<vector<int>> &triangle)
{
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return (minimizesum_rec(n,0,0,triangle,dp));
}


};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends