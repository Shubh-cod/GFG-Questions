//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isSumsubset(int sum, int arr[], int N, vector<vector<int>> &t)
{
    for (int i = 0; i < N+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if (i==0 and j==0)
            {
                t[i][j]=true;
            }
            else if (j==0)
            {
                t[i][j]=true;
            }
            else if(i==0)
            {
                t[i][j]=false;
            }
        }
    }

    for (int i = 1; i < N+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if (arr[i-1]>j)
            {
                t[i][j]=t[i-1][j];
            }
            else
            {
                t[i][j]=t[i-1][j] or t[i-1][j-arr[i-1]];
            }
            
        }
        
    }
    
    return t[N][sum];
}

int equalPartition(int N, int arr[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }

    if (sum % 2 != 0)
    {
        return false;
    }

    vector<vector<int>> t(N + 1, vector<int>(sum + 1));
    return isSumsubset(sum / 2, arr, N, t);
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends