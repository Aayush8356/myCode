#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

void printDoublyLL(Node *head)
{
    while (head != nullptr)
    {
        cout << " <- " << head->data << " -> ";
        head = head->next;
    }
    cout << '\n';
}
Node *deleteHeadNode(Node* head)
{
    if(head==nullptr)
    return nullptr;
    else if(head->next==nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *newNode = head->next;
    delete head;
    return newNode;
}
Node *deleteTailNode(Node* head)
{
    if(head==nullptr)
    return nullptr;
    else if(head->next==nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *newNode = head;
    Node *prevNode;
    while(head -> next != nullptr)
    {
        prevNode = head;
        head = head -> next;
    }
    prevNode -> next = nullptr;
    delete head;
    return newNode;
}
Node *InsertAtEnd(Node *head, int value)
{
    Node *temp = new Node();
    temp->data = value;
    if (head == nullptr)
    {
        head = temp;
        return head;
    }
    Node *newNode = head;
    while (head->next != nullptr)
    {
        head = head->next;
    }
    head->next = temp;
    temp->prev = head;
    return newNode;
}
Node *createDoublyLL(Node *head, int n)
{
    int value;
    for (int i = 0; i < n; ++i)
    {
        cin >> value;
        head = InsertAtEnd(head, value);
    }
    return head;
}



Node *InsertAtBegin(Node *head, int value)
{
    Node *temp = new Node();
    temp->data = value;
    if (head != nullptr)
    {
        head->prev = temp;
    }
    temp->next = head;
    return temp;
}

Node *createRevDoublyLL(Node *head, int n)
{
    int value;
    for (int i = 0; i < n; ++i)
    {
        cin >> value;
        head = InsertAtBegin(head, value);
    }
    return head;
}
int main()
{
    Node *head = nullptr;
    int n,value;
    cin >> n;
    // head = createDoublyLL(head, n);
    head = createRevDoublyLL(head,n);
    // head = deleteHeadNode(head);
    // head = deleteTailNode(head);
    printDoublyLL(head);

    return 0;
}