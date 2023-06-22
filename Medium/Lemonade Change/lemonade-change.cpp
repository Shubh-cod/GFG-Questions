//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
    int dollor5=0 ,dollor10=0 ,dollor20=0;
    
    for (int i = 0; i < N; i++)
    {
        if (bills[i]==5)
        {
            dollor5++;
        }
        else if (bills[i]==10)
        {
            dollor10++;
            if (dollor5>0)
            {
                dollor5--;
            }
            else
            {
                return false;
            }
        }
        else
        {
            dollor20++;
            if (dollor10>0 and dollor5>0)
            {
                dollor10--;
                dollor5--;
            }
            else if (dollor5>=3)
            {
                dollor5=dollor5-3;
            }
            else
            {
                return false;
            }    
        }
    }
    
    return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends