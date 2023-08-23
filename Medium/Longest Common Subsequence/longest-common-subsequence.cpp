//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    string s1, s2;
    vector<vector<int>> dp;
    //Function to find the length of longest common subsequence in two strings.
int lcs_rec(int n, int m)
{
    if (n==0 or m==0)
    {
        return 0;
    }

    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    if (s1[n-1]==s2[m-1])
    {
        return dp[n][m]=1+lcs_rec(n-1,m-1);
    }

    return dp[n][m]=max(lcs_rec(n,m-1),lcs_rec(n-1,m));
    
}

int lcs(int n, int m, string s1, string s2)
{
    this->s1 = s1;
    this->s2 = s2;
    dp.resize(n+1,vector<int>(m+1,-1));
    return lcs_rec(n,m);
}
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends