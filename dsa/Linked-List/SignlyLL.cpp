#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    // Node(int x)
    // {
    //     data = x;
    //     next = nullptr;
    // }
    //  Node()
    // {
    //     next = nullptr;
    // }
};
void printll(Node *head)
{
    while(head != nullptr)
    {
        cout << head->data << " -> ";
        head = head -> next;
    }
    cout << '\n';
}

Node *insertatend(Node *head, int value)
{
    Node *temp = new Node(); // default constructor is called so temp node have got garbage value for its next(0x0) and data(0).
    temp->data = value;
    // temp->next = nullptr;
    if(head == nullptr)
    {
        head = temp;
        return head;
    }
    Node *newnode = head;
    while(head->next != nullptr)
    {
        head = head -> next;
    }
    head->next = temp;
    return newnode;
    
}

Node *insertatbegin(Node *head, int value)
{
     Node *temp = new Node();
    temp->data = value;
    if(head == nullptr)
    {
        head = temp;
        return head;
    }
    temp -> next = head;
    return temp;
    
}
Node* insertAtposition(Node* head, int pos, int value)
{
    Node* temp = new Node();
    Node* newHead = head;
    int flag = 1;
    if(pos==1)
    {
        temp -> next = head;
        temp -> data = value;
        return temp;
    }
    while(flag<pos-1)
    {
        head = head -> next;
        ++flag;
    }
    temp -> next = head -> next;
    head -> next = temp;
    temp -> data = value;
    return newHead;

}
Node *DelHeadNode(Node *head)
{
    if(head==nullptr)
        return nullptr;
    else if(head->next==nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *Newhead = head->next;
    delete head;
    return Newhead;
}
Node* DelTailNode(Node* head)
{
    if(head == nullptr)
        return nullptr;
    else if(head->next==nullptr)
    {
        delete head;
        return nullptr;
    }
    Node* newNode = head;
    Node* curr;
    while(head!=nullptr)
    {
        curr = head;
        head = head -> next;
    }
    curr->next = nullptr;
    delete head;
    return newNode;
}
Node *createll(Node *head, int n)
{
    int value;
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> value;
        head = insertatend(head,value);
    }
    return head;
}
Node *createRevll(Node *head, int n)
{
    int value;
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> value;
        head = insertatbegin(head,value);
    }
    return head;
}
Node *revLL(Node *head)
{
    Node *curr = head;
    Node *prev = nullptr;
    Node *next = nullptr;
       while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;

}

Node *sortedinsert(Node *head, int newValue)
{
    Node *temp = nullptr;
    temp -> data = newValue;
    
}



int main()

{
    Node *head = nullptr;
    int n;
    cin >> n;
    head = createll(head,n);
    printll(head);
    cout << " Linked list created\n";
    // head = DelHeadNode(head);
    // printll(head);
    // cout << " First Node deleted\n";
    // head = DelTailNode(head);
    // printll(head);
    int value,pos;
    cin >> pos >> value;
    head = insertAtposition(head,pos,value);
    head = sortedinsert(head, 50);
    printll(head);
    return 0;
}