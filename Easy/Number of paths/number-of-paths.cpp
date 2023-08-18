//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

long long numberofpathrec(int rows, int columns, int x, int y, vector<vector<int>> &dp)
{
    if (x == rows - 1 && y == columns - 1) {
        return 1;
    }
    // if (x >= rows || y >= columns) {
    //     return 0;
    // }
    if (dp[x][y] != -1) {
        return dp[x][y];
    }
    
    long long ways = 0;
    if (y + 1 < columns) {
        ways += numberofpathrec(rows, columns, x, y + 1, dp);
    }
    if (x + 1 < rows) {
        ways += numberofpathrec(rows, columns, x + 1, y, dp);
    }
    dp[x][y] = ways;
    return dp[x][y];
}

long long numberOfPaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return numberofpathrec(m, n, 0, 0, dp);
}


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends