//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
    stack<char>st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='(' or s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/')
        {
            st.push(s[i]);
        }
        else
        {
            if (s[i]==')')
            {
                bool isreduntant=true;
                while (st.top()!='(')
                {
                    char top=st.top();
                    if (top =='+' or top =='-' or top =='*' or top =='/')
                    {
                        isreduntant=false;
                    }
                    st.pop();
                }
                st.pop();
                if (isreduntant==true)
                {
                    return true;
                }   
            }
            
        }
    }
    return false;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends