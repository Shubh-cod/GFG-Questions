//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
void toposort_dfs(vector<pair<int, int>> adj[], vector<int> &visited, stack<int> &s, int inital)
{
    visited[inital] = 1;
    for (auto x : adj[inital])
    {
        int node = x.first;
        if (!visited[node])
        {
            toposort_dfs(adj, visited, s, node);
        }
    }

    s.push(inital);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < M; i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }

    vector<int> visited(N, 0);
    stack<int> s;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            toposort_dfs(adj, visited, s, i);
        }
    }

    vector<int> dist(N, INT_MAX);
    dist[0] = 0;

    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        if (dist[node] != INT_MAX)
        {
            for (auto x : adj[node])
            {
                int adjnode = x.first;
                int wt = x.second;
                dist[adjnode] = min(dist[adjnode], dist[node] + wt);
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] != INT_MAX)
        {
            ans.push_back(dist[i]);
        }
        else
        {
            ans.push_back(-1);
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends