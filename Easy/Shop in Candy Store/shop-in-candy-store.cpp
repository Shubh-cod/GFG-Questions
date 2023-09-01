//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        int candi=0;
        int miniamount=0;
        for(int i=0;i<N;i++)
        {
            if(candi<N)
            {
                miniamount+=candies[i];
                candi+=K+1;
            }
            else{
                break;
            }
        }
        
        candi=0;
        int maxiamount=0;
        for(int i=N-1;i>=0;i--){
            if(candi<N)
            {
                maxiamount+=candies[i];
                candi+=K+1;
            }
            else{
                break;
            }
        }
        
        return {miniamount,maxiamount};
       
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends