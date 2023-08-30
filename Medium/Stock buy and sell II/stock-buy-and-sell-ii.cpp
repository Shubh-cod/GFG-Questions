//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  vector<vector<int>>dp;
    int f(vector<int>& prices,int index,int buy,int n)
    {
        if(index==n){
            return 0;
        }
        if (dp[index][buy]!=-1){
            return dp[index][buy];
        }

        if(buy){
            return dp[index][buy]=max(-prices[index]+f(prices,index+1,0,n),f(prices,index+1,1,n));
        }
        else{
            return dp[index][buy]=max(prices[index]+f(prices,index+1,1,n),f(prices,index+1,0,n));
        }
    }
    int stockBuyAndSell(int n, vector<int> &prices) {
        dp.resize(n,vector<int>(2,-1));
        return f(prices,0,1,n);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends