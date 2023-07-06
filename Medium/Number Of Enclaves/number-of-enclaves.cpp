//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
void dfs_numberOfEnclaves(int x,int y,int n, int m,vector<vector<int>>&visited,vector<vector<int>> &grid)
{
    visited[x][y]=1;
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = x + delrow[i];
        int ncol = y + delcol[i];
        if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !visited[nrow][ncol] and grid[nrow][ncol] == 1)
        {
            dfs_numberOfEnclaves(nrow, ncol, n, m,visited, grid);
        }
    }

}

int numberOfEnclaves(vector<vector<int>> &grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>visited(n,vector<int>(m,0));
    int count=0;

   for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 1 and !visited[i][0])
        {
            dfs_numberOfEnclaves(i, 0, n, m,visited, grid);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (grid[0][i] == 1 and !visited[0][i])
        {
            dfs_numberOfEnclaves(0, i, n, m,visited, grid);
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (grid[i][m - 1] == 1 and !visited[i][m - 1])
        {
            dfs_numberOfEnclaves(i, m - 1, n, m,visited, grid);
        }
    }

    for (int i = 1; i < m; i++)
    {
        if (grid[n - 1][i] == 1 and !visited[n - 1][i])
        {
            dfs_numberOfEnclaves(n - 1, i, n, m,visited, grid);
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (grid[i][j] == 1 and !visited[i][j])
            {
                count++;
            }
        }
    }

    return count;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends