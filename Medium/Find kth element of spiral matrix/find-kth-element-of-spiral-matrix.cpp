//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;
    int num = 0;
    int element;

    while (top<=bottom and left<=right)
    {
        for (int i = left; i <= right; i++)
        {
            if (num == k)
            {
                return element;
            }
            num++;
            element = a[top][i];
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            if (num == k)
            {
                return element;
            }
            num++;
            element = a[i][right];
        }
        right--;

        if (left <= right and top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                if (num == k)
                {
                    return element;
                }
                num++;
                element = a[bottom][i];
            }
            bottom--;
        }

        if (left <= right and top <= bottom)
        {
            for (int i = bottom; i >= top; i--)
            {
                if (num == k)
                {
                    return element;
                }
                num++;
                element = a[i][left];
            }
            left++;
        }
    }

    return element;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends