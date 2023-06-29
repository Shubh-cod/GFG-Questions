//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
bool isHappy(int N){
    set<int>s;
    s.insert(N);
    while (true)
    {
        int sum=0;
        while (N!=0)
        {
            sum=sum+ (N%10)*(N%10);
            N=N/10;
        }
        if (sum==1)
        {
            return true;
        }

        N=sum;
        if (s.find(N)!=s.end())
        {
           return false;
        }
        else
        {
            s.insert(N);
        }
    }
    
}

int nextHappy(int N)
{N=N+1;
    while (!isHappy(N) and N<=100000)
    {
        N++;
    }
    return N;
}

};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends