//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        
        sort(v.begin(),v.end());
        
        // for (int i = 0; i < n; i++)
        //     cout << v[i].first << "," << v[i].second << " ";
        // cout << endl;
        int minEnd = v[n - 1].second, minIdx = n - 1;
        
        vector<int> smallestEnd(n);
        for (int i = n - 2; i >= 0; i--)
        {
            if (minEnd > v[i].second)
                minEnd = v[i].second, minIdx = i;
            smallestEnd[i] = minIdx;
        }
        int res = 1, currentEnd = v[smallestEnd[0]].second;
        for (int i = smallestEnd[0]; i < n - 1; i++)
        {
            // cout << i << " " << currentEnd << endl;
            if (v[i].first <= currentEnd)
                continue;
                
            if (v[i].second < v[i + 1].first)
            {
                res++;
                currentEnd = v[i].second;
                // cout << currentEnd << endl;
                continue;
            }
            
            if (v[i].second < v[i + 1].second)
            {
                i = smallestEnd[i];
                currentEnd = v[i].second;
                res++;
                // cout << currentEnd << endl;
                continue;
            }
        }
        if (v[n - 1].first > currentEnd)
            res++;
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends