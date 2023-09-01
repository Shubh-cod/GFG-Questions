//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        if(n==1){
            return {{},{arr[n-1]}};
        }
        
        
        vector<vector<int>>v=AllSubsets(arr,n-1);
        set<vector<int>>s(v.begin(),v.end());
        
        int x=v.size();
        
        for(int i=0;i<x;i++)
        {
            vector<int>temp=v[i];
            temp.push_back(arr[n-1]);
            
            sort(temp.begin(),temp.end());
            
            if(s.find(temp)==s.end()){
                s.insert(temp);
            }
            
        }
        
        vector<vector<int>>ans;
        for(auto x:s){
            ans.push_back(x);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends