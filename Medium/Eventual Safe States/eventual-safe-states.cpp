//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<int> rev[V];

    for (int i = 0; i < V; i++)
    {
        for (auto x : adj[i])
        {
            rev[x].push_back(i);
        }
    }

    vector<int> indegree(V);
    for (int i = 0; i < V; i++)
    {
        for (auto x : rev[i])
        {
            indegree[x]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> safeNodes;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);
        for (auto x : rev[node])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }
    sort(safeNodes.begin(),safeNodes.end());
    return safeNodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends