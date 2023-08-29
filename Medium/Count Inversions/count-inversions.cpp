//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int count=0;
    
    void merge(long long arr[], long long s, long long mid, long long e)
    {
        vector<long long> temp;
        long long i = s;
        long long j = mid + 1;
    
        while (i <= mid && j <= e)
        {
            if (arr[i] > arr[j])
            {
                count=count+(mid-i+1);
                temp.push_back(arr[j]);
                j++;
            }
            else
            {
                temp.push_back(arr[i]);
                i++;
            }
        }
    
        while (i <= mid)
        {
            temp.push_back(arr[i]);
            i++;
        }
        while (j <= e)
        {
            temp.push_back(arr[j]);
            j++;
        }
    
        for (int i = 0; i < temp.size(); i++)
        {
            arr[s + i] = temp[i];
        }
    }
    
    void mergesort(long long arr[], long long s, long long e)
    {
        if (s >= e)
        {
            return;
        }
        long long mid = s + (e - s) / 2;
        mergesort(arr, s, mid);
        mergesort(arr, mid + 1, e);
    
        merge(arr, s, mid, e);
    }
    
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        mergesort(arr,0,N-1);
        return count;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends