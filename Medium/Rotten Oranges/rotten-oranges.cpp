//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));

    queue<pair<int, int>> q;

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2 && visited[i][j] != 2) {
                q.push({i, j});
                visited[i][j] = 2;
            }
        }
    }

    int time = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int j = 0; j < 4; j++) {
                int nrow = row + delrow[j];
                int ncol = col + delcol[j];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 2;
                }
            }
        }
        if (!q.empty()) {
            time++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 0 && grid[i][j] != 0) {
                return -1;
            }
        }
    }

    return time;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends