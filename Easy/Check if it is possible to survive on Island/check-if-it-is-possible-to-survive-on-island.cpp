//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M)
    {
        int sunday=S/7;
        int buyday=S-sunday;
        
        int foodreq=S*M;
        int maxfoodpurch=buyday*N;
        
        if(foodreq>maxfoodpurch){
            return -1;
        }
        
        else{
            if(foodreq%N==0){
                return foodreq/N;
            }
            else{
                return (foodreq/N)+1;
            }
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends