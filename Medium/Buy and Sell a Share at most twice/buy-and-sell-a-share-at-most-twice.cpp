//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
    

int f(vector<int>& prices,int n,int ind,int buy,int cap,vector<vector<vector<int>>>& dp)
    {
        if(ind==n){
            return 0;
        }

        if(dp[ind][buy][cap]!=-1){
            return dp[ind][buy][cap];
        }
        
        if(cap>0)
        {
            if(buy)
            { 
                return dp[ind][buy][cap]= max(-prices[ind]+f(prices,n,ind+1,0,cap,dp),f(prices,n,ind+1,1,cap,dp));
            }  
        else
            { 
                return dp[ind][buy][cap]= max(prices[ind]+f(prices,n,ind+1,1,cap-1,dp),f(prices,n,ind+1,0,cap,dp));
            }
        }
        
        return 0;
    }

    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(prices,n,0,1,2,dp);
    }

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends