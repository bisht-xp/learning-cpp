#include <iostream>
#include <math.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

void insertAtBegining(Node *&head, int value)
{
    Node *node = new Node(value);
    if (head == NULL)
    {
        head = node;
        return;
    }
    node->next = head;
    head = node;
}

void insertAtEnd(Node *&head, int value)
{
    Node *node = new Node(value);
    if (head == NULL)
    {
        head = node;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
}

void insertAtMiddle(Node *&head, int value, int pos)
{
    Node *n = new Node(value);
    Node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    Node *node = temp->next;
    temp->next = n;
    n->next = node;
}

void deleteNode(Node *&head, int pos)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    if (pos == 1)
    {
        Node *n = temp->next;
        temp = n->next;
        head = temp;
        delete n;
        return;
    }
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }
    Node *n = temp->next;
    temp->next = n->next;

    delete n;
}

void reverse(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *temp;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

Node *reverseKNode(Node *&head, int k)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *temp;
    int count = 0;
    while (curr != NULL && count < k)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        count++;
    }
    if (temp != NULL)
    {
        head->next = reverseKNode(temp, k);
    }
    // cout << prev->data << endl;
    // head = prev;
    return prev;
}

Node *reverseRecussive(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newNode = reverseRecussive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newNode;
}

// floyd Algorithm and Hear and tortois alogrithm implementation.
bool detectCycle(Node *&head)
{
    Node *tortois = head;
    Node *rabbit = head;

    while (rabbit != NULL && rabbit->next != NULL)
    {
        tortois = tortois->next;
        rabbit = rabbit->next->next;
        if (rabbit == tortois)
        {
            return true;
        }
    }

    return false;
}

// how to solve when we detect the cycle in the linked list
void removeCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != slow);

    fast = head;

    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = NULL;
}

void moveKNode(Node *&head, int k)
{
    Node *temp = head;
    Node *newHead;
    Node *newTail;
    while (temp->next != NULL)
    {
        if (temp->data == k)
        {
            newHead = temp->next;
            newTail = temp;
        }
        temp = temp->next;
    }
    newTail->next = NULL;
    temp->next = head;
    head = newHead;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL \n";
}

void makeCycle(Node *&head, int pos)
{
    Node *temp = head;
    Node *startNode;
    int count = 0;
    while (temp->next != NULL)
    {
        if (pos == count)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

// let check the length of the two node
int listLength(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

// lets make intersection point
void makeIntersection(Node *&head1, Node *&head2, int pos)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    int count = 1;
    while (temp1->next != NULL && count < pos)
    {
        temp1 = temp1->next;
        count++;
    }

    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    temp2->next = temp1->next;
}

// Now check the insersection Node

int insersectionPoint(Node *&head1, Node *&head2)
{
    int node1 = listLength(head1);
    int node2 = listLength(head2);

    Node *temp1 = head1;
    Node *temp2 = head2;

    if (node1 > node2)
    {
        temp1 = head1;
        temp2 = head2;
    }
    else
    {
        temp1 = head2;
        temp2 = head1;
    }
    cout << " lenght: " << node1 << " " << node2 << endl;
    int count = abs(node1 - node2);
    while (count--)
    {
        temp1 = temp1->next;
    }
    while (temp2 != temp1)
    {
        cout << temp2->data << " " << temp1->data << endl;
        temp2 = temp2->next;
        temp1 = temp1->next;
    }
    return temp2->data;
}

// merge two linked list

Node *mergeLinkedList(Node *&head1, Node *&head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *newNode = NULL;
    Node *tail = NULL;

    if(temp1 == NULL) {
        return temp2;
    }else if(temp2 == NULL) {
        return temp1;
    }
    if (temp1->data < temp2->data)
    {
        newNode = temp1;
        // cout << "Node1 : " << newNode->data << endl;
        temp1 = temp1->next;
    }
    else
    {
        // cout << "Node2 : " << newNode->data << endl;
        newNode = temp2;
        temp2 = temp2->next;
    }
    tail = newNode;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            tail->next = temp1;
            temp1 = temp1->next;
        // cout << "New Node1 : " << newNode->data << endl;
        }
        else
        {
            tail->next = temp2;
            temp2 = temp2->next;
        // cout << "New Node1 : " << newNode->data << endl;
        }
        // cout << "New Node : " << newNode->data << endl;
        tail = tail->next;
    }
    while (temp1 != NULL)
    {
        // insertAtEnd(newNode, temp1->data);
        tail->next = temp1;
        temp1 = temp1->next;
        tail = tail->next;
    }
    while (temp2 != NULL)
    {
        tail->next = temp2;
        // insertAtEnd(newNode, temp2->data);
        temp2 = temp2->next;
        tail = tail->next;
    }
    return newNode;
}

Node* mergeRecursive(Node* &head1, Node* &head2) {

    if(head1 == NULL) {
        return head2;
    }
    if(head2 == NULL) 
        return head1;
    Node* result;
    if(head1->data < head2->data) {
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    } else {
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }
    return result;
}

int main()
{
    Node *head = NULL;
    Node *head2 = NULL;
    insertAtEnd(head2, 2);
    insertAtEnd(head2, 4);
    insertAtEnd(head2, 8);
    insertAtEnd(head2, 10);
    insertAtEnd(head2, 13);
    // insertAtBegining(head, 8);
    insertAtEnd(head, 1);
    insertAtEnd(head, 3);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);
    insertAtEnd(head, 9);
    insertAtEnd(head, 11);
    insertAtEnd(head, 12);
    insertAtEnd(head, 14);
    // insertAtMiddle(head, 32, 1);
    // insertAtBegining(head, 1);
    // makeCycle(head, 3);
    display(head);
    display(head2);
    Node *newNode = mergeRecursive(head, head2);
    display(newNode);
    // makeIntersection(head, head2, 3);
    // display(head2);
    //  cout << "interSection point: " << insersectionPoint(head, head2) << endl;
    // int data = insersectionPoint(head, head2);
    // cout << "value: " << data << endl;
    //  deleteNode(head, 1);
    //  Node *newNode = reverseKNode(head, 2);
    //  Node *newNode =  reverseRecussive(head);
    //  cout << detectCycle(head) << endl;
    //  removeCycle(head);
    //  moveKNode(head, 10);
    //  display(head);
    return 0;
}
