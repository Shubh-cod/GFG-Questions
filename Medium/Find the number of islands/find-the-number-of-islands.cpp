//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
void bfs_island(int i, int j, vector<vector<char>> &grid,vector<vector<int>> &visited,int n,int m)
{
    visited[i][j]=1;
    queue<pair<int,int>>q;
    q.push({i,j});
    while (!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        // traverse the neighbours
        for (int delrow = -1; delrow <= 1; delrow++)
        {
            for (int delcol = -1; delcol <= 1; delcol++)
            {
                int row=x+delrow;
                int col=y+delcol;
                if (row<n and row >= 0 and col<m and col>=0 and grid[row][col]=='1' and visited[row][col]==0)
                {
                    q.push({row,col});
                    visited[row][col]=1;
                }
                
            }
            
        }
        
        
    }
    

}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int count=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' and visited[i][j] == 0)
            {
                count++;
                bfs_island(i, j, grid,visited,n,m);
            }
        }
    }

    return count;
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends