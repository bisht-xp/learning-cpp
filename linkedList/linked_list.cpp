#include<iostream>
using namespace std;

struct Node { 
    int data;
    Node *next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

void insertAtBeginning(Node *&root1, int value) {
    Node *node = new Node(value);
    if(root1 == NULL) {
        node->next = root1;
        root1 = node;
        return;
    }

    node->next = root1;
    root1 = node;
    return;
}


void print(Node *root1) {
    while(root1 != NULL) {
        cout << root1->data << "->";
        root1 = root1->next;
    }
    cout << "NULL\n";
    return;
}

void append(Node *&head, int data) {
    Node *temp = head;
    Node *node = new Node(data);
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

Node* alternateMerge(Node * root1, Node* root2){
    Node *curr1 = NULL;
    Node *curr2 = NULL;
    Node *newHead = NULL;
    if(!root1) return root2;
    if(!root2) return root1;
    if(root1) {
        newHead = root1;
    } else {
        newHead = root2;
    }
    // Node *temp = root1;
    while(root1 != NULL && root2 != NULL) {
        curr1 = root1->next;
        root1->next = root2;
        curr2 = root2->next;
        root2->next = curr1;
        root1 = root2->next;
        // root1 = curr1;
        root2 = curr2;
    }

    while(root1 != NULL) {
       append(newHead, root1->data);
       root1 = root1->next;
    }
    while(root2 != NULL) {
        append(newHead, root2->data);
       root2 = root2->next;
    }


    return newHead;
}


int len(Node* head)
{
    Node* temp = head ;
    int i = 0 ;
     while(temp!=NULL)
     {
         i++;
         temp=temp->next ;
     }
    
    return i ;
}


Node* bubble_sort_LinkedList_itr(Node* head)
{
    int n = len(head)-1;
  
   while(n--)
 
   {
       Node* prev =NULL;
    Node*cur = head;
    while(cur->next!=NULL)
    {
        if(cur->data >=cur->next->data)
        {
            
            if(prev==NULL)
            {
                //first Node
                Node* nxt = cur->next ;
                cur->next = nxt->next ;
                nxt->next = cur ;
               prev=nxt ;
                head = prev ;
               
                
            }
            
            else
            {
                
                Node* nxt = cur->next ;
                prev->next = nxt ;
                cur->next = nxt->next ;
                nxt->next = cur ;
                prev = nxt ;
              
                
            }
            
        }
        else
        {
           
             prev = cur ; 
            cur=cur->next ;
           
        }
        
        
    
    }
       
   }
    return head ;
    
}
 

int main() {
    Node *root1 = NULL;
    // Node *root2 = NULL;
    insertAtBeginning(root1, 1);
    insertAtBeginning(root1, 2);
    insertAtBeginning(root1, 3);
    insertAtBeginning(root1, 4);
    insertAtBeginning(root1, 5);
    // insertAtBeginning(root2, 6);
    // insertAtBeginning(root2, 7);
    // insertAtBeginning(root2, 8);
    // insertAtBeginning(root2, 9);
    // insertAtBeginning(root2, 10);
    // // print(root1);
    // // print(root2);
    // Node *head = alternateMerge(root1, root2);
    // Node *head = alternateMerge(root1, root2);
    print(root1);
    Node *head = bubble_sort_LinkedList_itr(root1);
    print(head);
    // Node 
    // print(root1);
    return 0;
}