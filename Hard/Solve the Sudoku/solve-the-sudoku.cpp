//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
bool checkrow(int grid[N][N], int k, int row)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[row][i] == k)
        {
            return false;
        }
    }

    return true;
}
bool checkcol(int grid[N][N], int k, int col)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[i][col] == k)
        {
            return false;
        }
    }
    return true;
}

bool checkgrid(int grid[N][N], int k, int row, int col)
{
    if (row <= 2 and col <= 2)
    {
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                if (grid[i][j] == k)
                {
                    return false;
                }
            }
        }
        return true;
    }

    else if (row <= 2 and col > 2 and col <= 5)
    {
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 3; j <= 5; j++)
            {
                if (grid[i][j] == k)
                {
                    return false;
                }
            }
        }
        return true;
    }

    else if (row <= 2 and col > 5 and col <= 8)
    {
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 6; j <= 8; j++)
            {
                if (grid[i][j] == k)
                {
                    return false;
                }
            }
        }
        return true;
    }

    else if (row > 2 and row <= 5 and col <= 2)
    {
        for (int i = 3; i <= 5; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                if (grid[i][j] == k)
                {
                    return false;
                }
            }
        }
        return true;
    }
    else if (row > 2 and row <= 5 and col > 2 and col <= 5)
    {
        for (int i = 3; i <= 5; i++)
        {
            for (int j = 3; j <= 5; j++)
            {
                if (grid[i][j] == k)
                {
                    return false;
                }
            }
        }
        return true;
    }

    else if (row > 2 and row <= 5 and col > 5 and col <= 8)
    {
        for (int i = 3; i <= 5; i++)
        {
            for (int j = 6; j <= 8; j++)
            {
                if (grid[i][j] == k)
                {
                    return false;
                }
            }
        }
        return true;
    }

    else if (row > 5 and row <= 8 and col <= 2)
    {
        for (int i = 6; i <= 8; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                if (grid[i][j] == k)
                {
                    return false;
                }
            }
        }
        return true;
    }

    else if (row > 5 and row <= 8 and col > 2 and col <= 5)
    {
        for (int i = 6; i <= 8; i++)
        {
            for (int j = 3; j <= 5; j++)
            {
                if (grid[i][j] == k)
                {
                    return false;
                }
            }
        }
        return true;
    }

    else
    {
        for (int i = 6; i <= 8; i++)
        {
            for (int j = 6; j <= 8; j++)
            {
                if (grid[i][j] == k)
                {
                    return false;
                }
            }
        }
        return true;
    }
}

bool safe(int grid[N][N], int k, int row, int col)
{
    return (checkrow(grid, k, row) and checkcol(grid, k, col) and checkgrid(grid, k, row, col));
}

bool SolveSudoku(int grid[N][N])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j] == 0)
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (safe(grid, k, i, j))
                    {
                        grid[i][j] = k;
                        if (SolveSudoku(grid))
                        {
                            return true;
                        }
                        else
                        {
                            grid[i][j] = 0;
                        }
                    }
                }

                return false;
            }
        }
    }
}

// Function to print grids of the Sudoku.
void printGrid(int grid[N][N])
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " ";
        }
    }
}
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends