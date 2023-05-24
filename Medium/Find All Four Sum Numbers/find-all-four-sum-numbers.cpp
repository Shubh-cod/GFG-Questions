//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
    sort(arr.begin(),arr.end());
    int n=arr.size(); 
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if(i>0 and arr[i]==arr[i-1]) {continue;}
        for (int j = i+1; j < n; j++)
        {
            if (j!= i+1 and arr[j]==arr[j-1])
            {
                continue;
            }
            int p=j+1;
            int l=n-1;
            while (p<l)
            {
                int sum=arr[i]+arr[j]+arr[p]+arr[l];
                if (sum<k)
                {
                    p++;
                }
                else if (sum>k)
                {
                    l--;
                }
                else
                {
                    ans.push_back({arr[i],arr[j],arr[p],arr[l]});
                    p++;
                    l--;
                    while (p<l and arr[p]==arr[p-1])
                    {
                        p++;
                    }
                    while (p<l and arr[l]==arr[l+1])
                    {
                        l--;
                    }
                } 
            }
            
        }
        
    }
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends