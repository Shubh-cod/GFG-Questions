//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
bool isSubsetSum_table(vector<int> arr, int n, int sum, vector<vector<int>> &t)
{
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if (i==0 and j==0)    
            {
                t[i][j]=1;
            }
            else if (j==0)
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
        for (int j = 1; j < sum+1; j++)
        {
            if (arr[i-1]>j)
            {
                t[i][j]=t[i-1][j];
            }
            else
            {
                t[i][j]= (t[i-1][j-arr[i-1]] or t[i-1][j]);
            } 
        }
    }
    
    return t[n][sum];
}

bool isSubsetSum(vector<int> arr, int sum)
{
    int n=arr.size();
    vector<vector<int>>t(n+1,vector<int>(sum+1));

    return isSubsetSum_table(arr,n,sum,t);

}

};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends