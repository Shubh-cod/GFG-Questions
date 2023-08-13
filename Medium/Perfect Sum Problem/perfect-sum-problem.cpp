//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
int perfsum_tabl(int arr[],int n,int sum,vector<vector<int>>&t){

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if (i==0 and j==0)
            {
                t[i][j]=1;
            }
            else if (i==0)
            {
                t[i][j]=0;   
            } 
        }
    }

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if (arr[i-1]<=j)
            {
                t[i][j]=(t[i-1][j-arr[i-1]]%1000000007+t[i-1][j]%1000000007)%1000000007;
            }
            else
            {
                t[i][j]=t[i-1][j]%1000000007;
            }
        }
        
    }
    return t[n][sum]%1000000007;
    
}

int perfectSum(int arr[], int n, int sum){
    vector<vector<int>>t(n+1,vector<int>(sum+1));
    return perfsum_tabl(arr,n,sum,t);
}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends