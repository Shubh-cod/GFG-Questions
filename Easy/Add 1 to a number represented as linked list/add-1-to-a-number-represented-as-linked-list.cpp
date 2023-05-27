//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node *reverseList(struct Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forw = head;
    while (curr != NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}

Node *addOne(Node *head)
{
    if (head == NULL)
    {
        return (new Node(1));
    }
    

    head = reverseList(head);
    int carry = 1;
    Node *temp = head;
    while (carry != 0)
    {
        if (temp->next != NULL)
        {
            int sum = temp->data + carry;
            carry = sum / 10;
            sum = sum % 10;
            temp->data = sum;
            temp = temp->next;
        }
        else
        {
            if (temp->data < 9)
            {
                temp->data++;
                carry = 0;
            }
            else
            {
                temp->data = 0;
                Node* temp1 = new Node(1);
                temp->next = temp1;
                temp = temp->next;
                carry = 0;
            }
        }
    }
    return reverseList(head);
}
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends