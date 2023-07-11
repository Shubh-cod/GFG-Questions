//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
    vector<int> indegree(N, 0);
    vector<int> adj[N];
    for (auto x : prerequisites)
    {
        indegree[x.second]++;
        adj[x.first].push_back(x.second);
    }

    queue<int> q;
    int count = 0;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            count++;
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for (auto x : adj[node])
        {
            indegree[x]--;
            if (indegree[x]==0)
            {
                q.push(x);
                count++;
            }  
        }
    }

    if (count == N)
    {
        return true;
    }
    else
    {
        return false;
    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends