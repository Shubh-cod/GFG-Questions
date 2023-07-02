//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
void dfs_floodfill(vector<vector<int>> &image, int sr, int sc, int newColor, vector<vector<int>>& visited, int initalColor)
{
    visited[sr][sc]=1;
    int n = image.size();
    int m = image[0].size();
    image[sr][sc]=newColor;

    if (sc+1<m and image[sr][sc+1]==initalColor and !visited[sr][sc+1])
    {
        dfs_floodfill(image,sr,sc+1,newColor,visited,initalColor);
    }
    
    if (sc-1>=0 and image[sr][sc-1]==initalColor and !visited[sr][sc-1])
    {
        dfs_floodfill(image,sr,sc-1,newColor,visited,initalColor);
    }

    if (sr+1<n and image[sr+1][sc]==initalColor and !visited[sr+1][sc])
    {
        dfs_floodfill(image,sr+1,sc,newColor,visited,initalColor);
    }

    if (sr-1>=0 and image[sr-1][sc]==initalColor and !visited[sr-1][sc])
    {
        dfs_floodfill(image,sr-1,sc,newColor,visited,initalColor);
    }
    
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int initalColor = image[sr][sc];
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));

    dfs_floodfill(image, sr, sc, newColor, visited, initalColor);
    return image;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends