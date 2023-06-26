//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int nCr(int n, int r) {
    if (r > n) {
        return 0;
    }
    
    const int MOD = 1000000007;
    long long ans = 1;
    long long j = 1;
    
    for (long long i = n; i > n - r; i--) {
        ans = (ans * i) % MOD;
        ans = (ans * inverse(j, MOD)) % MOD;
        j++;
    }
    
    return ans;
}

long long inverse(long long x, int MOD) {
    long long result = 1;
    long long exp = MOD - 2;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * x) % MOD;
        }
        
        x = (x * x) % MOD;
        exp /= 2;
    }
    
    return result;
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends