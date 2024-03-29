//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int noofele(vector<vector<int>> &matrix, int R, int C,int k)
    {
        int count=0;
        for(int i=0;i<R;i++)
        {
            int low=0;
            int high=C-1;
            
            while(low<=high){
                int mid=low+(high-low)/2;
                if(matrix[i][mid]<=k){
                    count=count+(mid-low+1);
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }    
        return count;
    }
    
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        int low=matrix[0][0];
        
        for(int i=1;i<R;i++){
            low=min(low,matrix[i][0]);
        }
        
        int high=matrix[0][C-1];
        
        for(int i=1;i<R;i++){
            high=max(high,matrix[i][C-1]);
        }
        
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = noofele(matrix, R, C, mid);
            
            if (count <= (R * C) / 2) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends