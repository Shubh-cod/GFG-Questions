//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
double count = 0;

void merge(vector<int>& arr, int s, int mid, int e)
{
    vector<int> temp;
    int i = s;
    int j = mid + 1;

    while (i <= mid && j <= e)
    {
        if (arr[i] > arr[j])
        {
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

    int x=s;
    int y=mid+1;
    while(x<=mid and y<=e){
        if(2ll*arr[y]<1ll*arr[x]){
            count+=mid-x+1;
            y++;
        }
        else{
            x++;
        }
    }

    for (int i = 0; i < temp.size(); i++)
    {
        arr[s + i] = temp[i];
    }
}


void mergesort(vector<int>& arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    
    merge(arr, s, mid, e);
}

int countRevPairs(int n, vector<int> arr) {
     mergesort(arr,0,n-1);
     return(int) count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends