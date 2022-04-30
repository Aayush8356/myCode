#include <iostream>
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
Node *insertatend(Node *head, int value)
{
    Node *temp = new Node(value);
    if (head == nullptr)
    {
        head = temp;
        return head;
    }
    Node *newnode = head;
    while (head->next != nullptr)
    {
        head = head->next;
    }
    head->next = temp;
    return newnode;
}

Node *createll(Node *head, int n)
{
    int value;
    for (int i = 0; i < n; ++i)
    {
        cin >> value;
        head = insertatend(head, value);
    }
    return head;
}

void printll(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << '\n';
}
Node *delDuplicate(Node *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;
    Node *xNode = head->next;
    Node *newHead = head;
    while (xNode != nullptr)
    {
        if (newHead->data == newHead->next->data)
        {
            newHead->next = xNode->next;
        }
        else
            newHead = newHead->next;
        xNode = xNode->next;
    }
    return head;
}

pair<bool, Node *> detectLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr and fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return {true, fast};
    }
    return {false, fast};
}

Node *removeLoop(Node *head)
{
    pair<bool, Node *> pair2 = detectLoop(head);
    Node *slow = head;
    Node *fast = pair2.second;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    while (slow->next != fast)
    {
        slow = slow->next;
    }
    slow->next = nullptr;
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
Node *kGroupNode(Node *head, int k)
{
    int point = 1;
    Node *firstHalf = nullptr;
    Node *secondHalf = nullptr;
    if (head == nullptr)
    {
        return head;
    }
    Node *temp = nullptr;
    Node *curr = head;
    Node *afterNode = head;
    while (curr->next != nullptr and point != k)
    {
        curr = curr->next;
        afterNode = curr->next;
        ++point;
    }
    if (curr->next == nullptr)
    {
        head = revLL(head);
        return head;
    }
    curr->next = temp;
    firstHalf = revLL(head);
    secondHalf = revLL(afterNode);
    Node *copyNode = firstHalf;
    while (copyNode->next != nullptr)
    {
        copyNode = copyNode->next;
    }
    copyNode->next = secondHalf;
    return firstHalf;
}
Node *kthGroup(Node *head, int kth)
{
    bool isfirstpass = true;
    Node *curr = head, *xFirst = nullptr;
    while (curr != nullptr)
    {
        Node *prev = nullptr, *first = head;
        int count = 0;
        while (curr != nullptr and count < kth)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            ++count;
        }

        if (isfirstpass)
        {
            isfirstpass = false;
        }
        else
        {
            prev->next = xFirst;
        }
    }
}

void *deleteNode(Node *head)
{
    head->data = head->next->data;
    Node *temp = head->next;
    head->next = head->next->next;
    delete temp;
}

Node *oddEvenSep(Node *head)
{
    Node *eS = nullptr, *eE = nullptr, *oS = nullptr, *oE = nullptr;
    // Node *curr = head;
    for (Node *curr = head; curr != nullptr; curr = curr->next)
    {
        int value = curr->data;
        if (value % 2 == 0)
        {
            if (eS == nullptr)
            {
                eS = curr;
                eE = eS;
            }
            else
            {
                eE->next = curr;
                eE = eE->next;
            }
        }

        else
        {
            if (oS == nullptr)
            {
                oS = curr;
                oE = oS;
            }
            else
            {
                oE->next = curr;
                oE = oE->next;
            }
        }
    }
    if (eS == nullptr || oS == nullptr)
        return head;
    eE->next = oS;
    oE->next = nullptr;
    return eS;
}

Node *intersection(Node *head1, Node *head2)
{
    int count1 = 0;
    int count2 = 0;
    Node *h1 = head1;
    Node *h2 = head2;
    while (head1 != nullptr)
    {
        head1 = head1->next;
        ++count1;
    }
    while (head2 != nullptr)
    {
        head2 = head2->next;
        ++count2;
    }
    int equal = abs(count1 - count2);
    while (equal)
    {
        if (count1 > count2)
            h1 = h1->next;
        else
            h2 = h2->next;
        --equal;
    }
    while (h1->next != h2->next)
    {
        h1 = h1->next;
        h2 = h2->next;
    }
    Node *temp = h1->next;
    return temp;
}
int main()
{
    Node *head1 = new Node(11);
    Node *node1 = new Node(22);
    Node *node2 = new Node(33);
    Node *node3 = new Node(44);
    Node *head2 = new Node(25);
    head1->next = node1;
    node1->next = node2;
    node2->next = node3;
    head2->next = node2;
    // node3->next = node2;
    // int n;;

    // cin >> n;
    // head = createll(head, n);
    // printll(head);
    // head = delDuplicate(head);
    //printll(head);
    // removeLoop(head);
    // head = oddEvenSep(head);
    // printll(head);
    Node *temp = intersection(head1, head2);
    cout << temp->data;
}