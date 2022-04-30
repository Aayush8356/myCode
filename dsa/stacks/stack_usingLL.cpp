#include <iostream>
using namespace std;

struct Node
{
private:
    int data;
    Node *next;

public:
    Node(int value)
    {
        next = nullptr;
        data = value;
    }

    Node *insertAtBegin(Node *head, int value)
    {
        Node *temp = new Node(value);
        if (head == nullptr)
            return temp;
        temp->next = head;
        return temp;
    }
    Node *delHead(Node *head)
    {
        if (head == nullptr)
            return head;
        Node *temp = head->next;
        delete head;
        return temp;
    }
    int getHead(Node *head)
    {
        if(head==nullptr)
        return 0;
        return head->data;
    }
};

struct linkedlist
{
private:
    Node *ll;

public:

    linkedlist()
    {
        ll = nullptr;
    }
    void insertAtbegin(int value)
    {
        ll = ll->insertAtBegin(ll, value);
    }

    void deleteHead()
    {
        ll = ll->delHead(ll);
    }

    int getFirstElement()
    {
        return ll->getHead(ll);
    }
};

struct stack
{
private:
    int stackLL_size;
    linkedlist stackLL;

public:

stack()
{
    stackLL_size = 0;
    // stackLL = nullptr;
}
   void push(int value)
   {
       stackLL.insertAtbegin(value);
       stackLL_size++;
   }
   void pop()
   {
       stackLL.deleteHead();
       stackLL_size--;
   }
   int top()
   {
       return stackLL.getFirstElement();
   }
   int size()
   {
       return stackLL_size;
   }
   bool empty()
   {
       return stackLL_size==0;
   }

};

bool matching(char c1, char c2)
{
    return (c1=='(' and c2 == ')' or c1=='{' and c2 == '}' or c1=='[' and c2 == ']');
}

bool balancedparen(string str)
{
    stack s;
    for(int i = 0 ; i < str.length() ; ++i)
    {
        if(str[i]=='(' or str[i]=='{' or str[i]=='[')
        s.push(str[i]);

        else
        {
            if(s.empty()==false and matching(s.top(),str[i]) )
            {
                s.pop();
            }
            else
            {
                return s.empty();
            }


        }

    }
    return s.empty();
}

int main()
{
    string str;
    cin >> str;
    cout << boolalpha << balancedparen(str);
}