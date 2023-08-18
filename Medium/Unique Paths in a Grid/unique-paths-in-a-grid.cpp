//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
int uniquePaths_rec(int n, int m,int x,int y, vector<vector<int>> &grid,vector<vector<int>>&dp)
{
    if (grid[x][y]==0)
    {
        return 0;
    }

    if (x==n-1 and y==m-1)
    {
        return 1;
    }

    if (dp[x][y]!=-1)
    {
        return dp[x][y];
    }
    
    
    int ways=0;

    if (x+1<n)
    {
        ways= (ways%1000000007 + uniquePaths_rec(n,m,x+1,y,grid,dp)%1000000007)%1000000007;
    }
    if (y+1<m)
    {
        ways=(ways%1000000007 + uniquePaths_rec(n,m,x,y+1,grid,dp)%1000000007)%1000000007;
    }
    
    dp[x][y]=ways%1000000007;
    return dp[x][y];

}

int uniquePaths(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return uniquePaths_rec(n,m,0,0,grid,dp);
}


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends