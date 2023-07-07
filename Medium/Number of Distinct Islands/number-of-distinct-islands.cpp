//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
void dfs_countDistinctIslands(int i, int j,pair<int,int> base,vector<pair<int,int>>&v, vector<vector<int>> &visited,vector<vector<int>> &grid)
{
    int n=grid.size();
    int m=grid[0].size();
    visited[i][j]=1;
    
    v.push_back({i-base.first,j-base.second});

    int delrow[]={0,1,-1,0};
    int delcol[]={1,0,0,-1};
    for (int x = 0; x < 4; x++)
    {
        int nrow=i+delrow[x];
        int ncol=j+delcol[x];
        if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !visited[nrow][ncol] and grid[nrow][ncol]==1)
        {
            dfs_countDistinctIslands(nrow,ncol,base,v,visited,grid);
        }
    }

    
    
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> s;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j]==1 and !visited[i][j])
            {
                vector<pair<int,int>>v;
                dfs_countDistinctIslands(i,j,{i,j},v,visited,grid);
                s.insert(v);
            }
        }
    }

    return s.size();

}
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends