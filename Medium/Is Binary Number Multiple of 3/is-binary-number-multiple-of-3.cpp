//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	
int isDivisible(string s)
{
    char state = '0';
    for (int i = 0; i < s.length(); i++)
    {
        // storing binary digit
        char digit = s[i];

        if (state == '0')
        {
            if (digit == '1')
                state = '1';
        }
        else if (state == '1')
        {
            if (digit == '0')
                state = '2';
            else
                state = '0';
        }
        else if (state == '2')
        {
            if (digit == '0')
                state = '1';
        }
    }
    if (state=='0')
    {
        return true;
    }
    else
    {
        return false;
    }
    
    
}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends