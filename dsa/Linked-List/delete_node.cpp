#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value)
    {
        next = nullptr;
        data = value;
    }
};

void display(Node *head)
{
    if(head == nullptr)
    cout << "kuch daalo toh shi :)\n";
    while(head!=nullptr)
    {
        cout << head -> data << " -> ";
        head = head -> next;
    } 
}

Node *delkthNode(Node *head, int k)
{
    if(head == nullptr)
    return head;
    Node *temp = head;
    Node *curr = head;
    int flag = 0;
    while(head -> next != nullptr or flag != k)
    {
        
    }
}
int main()
{
    Node *head = new Node(10);
    Node *node1 = new Node(20);
    Node *node2 = new Node(30);
    Node *node3 = new Node(40);
    Node *node4 = new Node(50);

    head ->next = node1;
    node1 ->next = node2;
    node2 ->next = node3;
    node3 ->next = node4;
    display(head);
}