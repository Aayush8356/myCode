#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

void printCLL(Node *head)
{
    Node* temp = head;

    do
    {
        cout << head -> data << " -> ";
        head = head -> next;
    } while(head != temp);
}

Node *insertBegin(Node *head, int value)
{
    Node *newHead = new Node(value);
    if(head == nullptr)
    {
        head = newHead;
        head -> next = head;
        return head;
    }
    
    Node *curr = head;
    while(head != curr->next)
    {
        curr = curr -> next;
    }
    newHead -> next = head;
    curr -> next = newHead;
    return newHead;
}

Node *insertEnd(Node *head, int value)
{
    Node *temp = new Node(value);
    if(head == nullptr)
    {
        head = temp;
        head -> next = head;
        return head;
    }
    
    Node *curr = head;
    while(head != curr->next)
    {
        curr = curr -> next;
    }
    temp -> next = head;
    curr -> next = temp;
    return head;
}
Node *delHead(Node *head)
{
    if(head == nullptr)
    {
        return head;
    }
    Node *curr = head;
    while(curr -> next != head)
    {
        curr = curr -> next;
    }
    
    Node *newHead = head -> next;
    curr -> next = head -> next;
    delete head;
    return newHead;

}

Node *delKthNode(Node *head, int posi)
{
    if(head == nullptr)
    {
        return head;
    }
    else if(posi == 1)
    {
        head = delHead(head);
        return head;
    }
    Node *curr = head;
    Node *prevNode = head;
    int point = 1;
    while(curr -> next != head and point != posi)
    {
        prevNode = curr;
        curr = curr -> next;
        ++point;
    }
    prevNode -> next = curr -> next;
    delete curr;
    return head;
}



int main()

{  
    Node *head = new Node(10);
    Node *temp2 = new Node(20);
    Node *temp3 = new Node(40);
    Node *temp4 = new Node(70);
    head -> next = temp2;
    temp2 -> next = temp3;
    temp3 -> next = temp4;
    temp4 -> next = head;
    head = insertBegin(head,69);
    head = insertEnd(head,68);
    head = delHead(head);
    head = delKthNode(head,1);
    printCLL(head);
    return 0;
}