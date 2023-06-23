//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
Node* solve(int in[],int pre[],int &preorderIndex,int is,int ie,int n){
    if (is>ie or preorderIndex>=n)
    {
        return NULL;
    }
    
    Node* root=new Node(pre[preorderIndex]);
    preorderIndex++;
    int pos=-1;
    for (int i = is; i <= ie; i++)
    {
        if (in[i]==root->data)
        {
            pos=i;
            break;
        } 
    }
    root->left=solve(in,pre,preorderIndex,is,pos-1,n);
    root->right=solve(in,pre,preorderIndex,pos+1,ie,n);
    return root;

}

Node* buildTree(int in[],int pre[], int n)
{

    int preorderIndex=0;
    Node* ans=solve(in,pre,preorderIndex,0,n-1,n);
    return ans;
}
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends