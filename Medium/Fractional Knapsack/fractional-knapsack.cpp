//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    bool static comp(Item a, Item b) {
         double r1 = (double) a.value / (double) a.weight;
         double r2 = (double) b.value / (double) b.weight;
         return r1 < r2;
      }
    double fractionalKnapsack(int W, Item arr[], int n)
{
    
    sort(arr,arr+n,comp);
    double profit=0;

    for(int i=n-1;i>=0;i--){
        if(W!=0 and arr[i].weight<W)
        {
            profit=profit+arr[i].value;
            W=W-arr[i].weight;
        }
        else
        {
            profit=profit+ (double)arr[i].value/arr[i].weight*(W);
            break;
        }
    }
    return profit;
}

        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends