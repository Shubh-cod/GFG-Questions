//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
void dfs_findpath(vector<string>&v,vector<vector<int>> &pathvisited,vector<vector<int>>&m,int n,int r,int c,string s)
{
    pathvisited[r][c]=1;

    if (r+1<n and pathvisited[r+1][c]==0 and m[r+1][c]==1)
    {
        if (r+1==n-1 and c==n-1)
        {
            v.push_back(s+"D");
        }
        else
        {
            dfs_findpath(v,pathvisited,m,n,r+1,c,s+"D");
        }
    }

    if (r-1>=0 and pathvisited[r-1][c]==0 and m[r-1][c]==1)
    {
        if (r-1==n-1 and c==n-1)
        {
            v.push_back(s+"U");
        }
        else
        {
            dfs_findpath(v,pathvisited,m,n,r-1,c,s+"U");
        }
    }

    if (c+1<n and pathvisited[r][c+1]==0 and m[r][c+1]==1)
    {
        if (r==n-1 and c+1==n-1)
        {
            v.push_back(s+"R");
        }
        else
        {
            dfs_findpath(v,pathvisited,m,n,r,c+1,s+"R");
        }
    }

    if (c-1>=0 and pathvisited[r][c-1]==0 and m[r][c-1]==1)
    {
        if (r==n-1 and c-1==n-1)
        {
            v.push_back(s+"L");
        }
        else
        {
            dfs_findpath(v,pathvisited,m,n,r,c-1,s+"L");
        }
    }

    pathvisited[r][c]=0;    
}


vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string>v;
    if (m[0][0]==0)
    {
        return v;
    }

    vector<vector<int>> pathvisited(n, vector<int>(n, 0));
    
    dfs_findpath(v,pathvisited,m,n,0,0,"");

    return v;
    
}
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends