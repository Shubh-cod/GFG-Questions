//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
bool isValid(int arr[], int n, int m, int maxpage)
{
    int students=1;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum=sum+arr[i];
        if (sum>maxpage)
        {
            students++;
            sum=arr[i];
        }
        if (students>m)
        {
            return false;
        }
    }
    return true;
}

int findPages(int A[], int N, int M)
{
    if(N<M){
        return -1;
    }
    int start = INT_MIN;
    int end = 0;
    int res = -1;
    for (int i = 0; i < N; i++)
    {
        start = max(start, A[i]);
        end = end + A[i];
    }

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(A, N, M, mid))
        {
            res = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return res;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends