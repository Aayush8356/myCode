#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

Node *insertNode(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == nullptr)
    {
        head = temp;
        return head;
    }
    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = temp;
    return head;
}

Node *createLinkList(Node *head, int n)
{
    int x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        head = insertNode(head, x);
    }
    return head;
}

void printLinkList(Node *head)
{
    Node *temp = head;
    while(temp!=nullptr)
    {
        cout << temp -> data << " -> ";
        temp = temp -> next; 
    }
}

int main()
{
    Node *head = nullptr;
    int n;
    cin >> n;
    head = createLinkList(head,n);
    printLinkList(head);
}
