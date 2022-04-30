#include<bits/stdc++.h>
struct Node
{
    int data;
    Node *next;
    Node (int x)
    {
        data = x;
        next = nullptr;
    }
};
int main()
{
    Node *head = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);

    head -> next = node2;
    node2 -> next = node3;
    // node3 -> next = nullptr;
   
    return 0;
}