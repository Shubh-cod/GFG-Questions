//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool bfsbipartite(int inital, vector<int> &color, vector<int> adj[])
{
    queue<pair<int, int>> q;
    color[inital] = 1;
    q.push({inital, color[inital]});

    while (!q.empty())
    {
        int node = q.front().first;
        int nodecolor = q.front().second;
        q.pop();
        for (auto x : adj[node])
        {
            if (color[x] == 0)
            {
                if (nodecolor == 1)
                {
                    color[x] = 2;
                }
                else
                {
                    color[x] = 1;
                }
                q.push({x,color[x]});
            }
            else
            {
                if (color[x] == nodecolor)
                {
                    return false;
                }
            }
            
        }
    }

    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (color[i]==0)
        {
            if (!bfsbipartite(i, color, adj))
            {
                return false;
            }
            
        }
        
    }
    return true;
}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends