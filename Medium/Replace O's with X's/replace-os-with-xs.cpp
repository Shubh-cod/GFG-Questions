//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void dfs_fill(int x, int y, vector<vector<int>> &visited, int n, int m, vector<vector<char>> mat)
{
    visited[x][y] = 1;
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = x + delrow[i];
        int ncol = y + delcol[i];
        if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !visited[nrow][ncol] and mat[nrow][ncol] == 'O')
        {
            dfs_fill(nrow,ncol,visited,n,m,mat);
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] == 'O' and !visited[i][0])
        {
            dfs_fill(i,0,visited,n,m,mat);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (mat[0][i] == 'O' and !visited[0][i])
        {
            dfs_fill(0,i,visited,n,m,mat);
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (mat[i][m-1] == 'O' and !visited[i][m-1])
        {
            dfs_fill(i,m-1,visited,n,m,mat);
        }
    }

    for (int i = 1; i < m; i++)
    {
        if (mat[n-1][i] == 'O' and !visited[n-1][i])
        {
            dfs_fill(n-1,i,visited,n,m,mat);
        }
    }

    for (int i = 1; i < n-1; i++)
    {
        for (int j = 1; j < m-1; j++)
        {
            if (mat[i][j]=='O' and !visited[i][j])
            {
                mat[i][j]='X';
            }
        }
        
    }
    
    return mat;
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends