#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int value) {
            data = value;
            next = NULL;
        }
};

void insertAtBegining(Node *&head, int value) {
    Node *node = new Node(value);
    if(head == NULL) {
        head = node;
        return;
    }
    node->next = head;
    head = node;
}

void insertAtEnd(Node *&head, int value) {
    Node *node = new Node(value);
    if(head == NULL) {
        head = node;
        return;
    } 
    Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

void insertAtMiddle(Node *&head, int value, int pos) {
    Node *n = new Node(value);
    Node *temp = head;
    for(int i=0; i<pos-1; i++) {
        temp = temp->next;
    }
    Node *node = temp->next;
    temp->next = n;
    n->next = node;
}

void deleteNode(Node *&head, int pos) {
    if(head == NULL) {
        return;
    }
    Node *temp = head;
    if(pos == 1) {
        Node *n = temp->next;
        temp = n->next;
        head = temp;
        delete n;
        return;
    }
    for(int i=0; i<pos-2; i++) {
        temp = temp->next;
    }
    Node *n = temp->next;
    temp->next = n->next;

    delete n;
}

void reverse(Node *&head) {
    if(head == NULL) {
        return;
    }
    Node *prev = NULL;
    Node* curr = head;
    Node *temp;

    while(curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

Node* reverseKNode(Node* &head, int k) {
    Node *prev = NULL;
    Node *curr = head;
    Node *temp;
    int count = 0;
    while(curr!=NULL && count < k) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        count++;
    }
    if(temp!= NULL) {
      head->next =  reverseKNode(temp, k);
    }
    // cout << prev->data << endl;
    // head = prev;
    return prev;
}

Node* reverseRecussive(Node* &head) {
    if( head == NULL || head->next == NULL ) {
        return head;
    } 

    Node *newNode = reverseRecussive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newNode;
}

// floyd Algorithm and Hear and tortois alogrithm implementation.
bool detectCycle(Node* &head) {
    Node *tortois = head;
    Node *rabbit = head;

    while(rabbit != NULL && rabbit->next != NULL) {
        tortois = tortois->next;
        rabbit = rabbit->next->next;
        if(rabbit == tortois) {
            return true;
        }
    }

    return false;
}

// how to solve when we detect the cycle in the linked list
void removeCycle(Node* &head) {
    Node *slow = head;
    Node *fast = head;

    do
    {
      slow = slow->next;
      fast = fast->next->next;  
    } while (fast!=slow);
    
    fast = head;

    while(fast->next != slow->next) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = NULL;
}

void display(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL \n";
}

void makeCycle(Node* &head, int pos) {
    Node* temp = head;
    Node*startNode;
    int count = 0;
    while(temp->next != NULL) {
        if(pos == count) {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}


int main() {
    Node *head = NULL;
    // insertAtBegining(head, 8);
    insertAtEnd(head, 8);
    insertAtEnd(head, 10);
    insertAtEnd(head, 9);
    insertAtEnd(head, 69);
    insertAtEnd(head, 29);
    insertAtMiddle(head, 32, 1);
    insertAtBegining(head, 1);
    makeCycle(head, 3);
    // display(head);
    // deleteNode(head, 1);
    // Node *newNode = reverseKNode(head, 2);
    // Node *newNode =  reverseRecussive(head);
    // cout << detectCycle(head) << endl;
    removeCycle(head);

    display(head);
    return 0;
}