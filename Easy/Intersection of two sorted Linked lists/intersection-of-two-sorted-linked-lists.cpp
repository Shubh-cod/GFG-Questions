//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    Node* temp1=head1;
    Node* temp2=head2;
    Node* dummy=new Node(0);
    Node* temp=dummy;
    while (temp1!=NULL and temp2!=NULL)
    {
        if (temp2->data>temp1->data)
        {
            temp1=temp1->next;
        }
        else if (temp1->data>temp2->data)
        {
            temp2=temp2->next;
        }
        else
        {
            temp->next=new Node(temp1->data);
            temp=temp->next;
            // while (temp1->data==temp1->next->data and temp1->next!=NULL)
            // {
            //     temp1=temp1->next;
            // }
            temp1=temp1->next;
            // while (temp2->data==temp2->next->data and temp2->next!=NULL)
            // {
            //     temp2=temp2->next;
            // }
            temp2=temp2->next;
        }           
    }
    return dummy->next;
}