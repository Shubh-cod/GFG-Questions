//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>>dp;
    int countWays_rec(string S1,string S2,int n,int m){
        if(m==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        
        if(S1[n-1]==S2[m-1]){
            return dp[n][m]=countWays_rec(S1,S2,n-1,m-1)+countWays_rec(S1,S2,n-1,m);
        }
        else{
            return dp[n][m]=countWays_rec(S1,S2,n-1,m);
        }
    }
    
    int countWays(string S1, string S2){
        int n=S1.size();
        int m=S2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return countWays_rec(S1,S2,n,m);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}
// } Driver Code Ends