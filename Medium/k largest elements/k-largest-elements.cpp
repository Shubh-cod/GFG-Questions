//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
    vector<int>v;
    priority_queue<int,vector<int>,greater<int>>pq;  // Min heap
	for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size()>k)
        {
            pq.pop();
        }  
    }

    while (!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }
    reverse(v.begin(),v.end());
    return v;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends