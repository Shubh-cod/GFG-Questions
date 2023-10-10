//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int search(int nums[], int N) 
    {
        int n=N;
        int low =0;
        int high=n-1;
        while(high-low+1>=3){
            int mid=low+(high-low)/2;
            // cout<<"MID"<<" "<<mid<<endl;
            if(mid+1<=high and mid-1>=low and nums[mid-1]!=nums[mid] and nums[mid+1]!=nums[mid]){
                // cout<<high<<" "<<low<<endl;
                return nums[mid];
            }
            
            else if(mid+1<=high and nums[mid+1]==nums[mid]){
                if((mid-low)%2!=0){
                    high=mid-1;
                    // cout<<high<<" "<<low<<endl;
                }
                else{
                    low=mid+2;
                    // cout<<high<<" "<<low<<endl;
                }
            }
            else if(mid-1>=low and nums[mid-1]==nums[mid]){
                if((mid-low+1)%2!=0){
                    high=mid-2;
                    // cout<<high<<" "<<low<<endl;
                }
                else{
                    low=mid+1;
                    // cout<<high<<" "<<low<<endl;
                }
            } 
        }
        
        int mid=low+(high-low)/2;
        // cout<<"MID"<<" "<<mid<<endl;
        if(high-low+1==1){
            return nums[mid];
        }
        else {
            if(nums[mid+1]==nums[mid]){
                return nums[mid-1];
            }
            else{
                return nums[mid+1];
            }
        }
        
    }
    

	
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends