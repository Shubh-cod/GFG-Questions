//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int maxfallingPathsum_tab(int x, int y, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    for (int i = 0; i < n; i++) {
        dp[n - 1][i] = matrix[n - 1][i];
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            int ans = -1E9;
            if (j - 1 >= 0) {
                ans = max(ans, dp[i + 1][j - 1]);
            }
            if (j + 1 < n) { 
                ans = max(ans, dp[i + 1][j + 1]);
            }
            ans = max(ans, dp[i + 1][j]);

            dp[i][j] = ans + matrix[i][j];
        }
    }

    return dp[x][y];
}

int maximumPath(int N, vector<vector<int>> Matrix) {
    int n = Matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
    maxfallingPathsum_tab(0, 0, n, Matrix, dp);
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, dp[0][i]); 
    }
    return maxi;
}


};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends