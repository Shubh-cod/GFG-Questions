//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    vector<vector<int>> ans;
    
    void solve(vector<int>& A,int ind, vector<int>& temp)
    {
        if(ind==A.size()){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(A[ind]);
        solve(A,ind+1,temp);
        
        temp.pop_back();
        
        solve(A,ind+1,temp);
        
    }
    
    vector<vector<int>> subsets(vector<int>& A)
    {
        vector<int>temp;
        solve(A,0,temp);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends