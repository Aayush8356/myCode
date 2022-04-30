#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

void inorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
void preorderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}
int heightOfBinaryTree(Node *root)
{
    if (root == nullptr)
        return 0;
    return max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right)) + 1;
}

void KthNode(Node *root, int k)
{
    if (root == nullptr)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    KthNode(root->left, k - 1);
    KthNode(root->right, k - 1);
}

int main()
{
    Node *root = new Node(10);
    Node *node1 = new Node(23);
    Node *node2 = new Node(37);
    Node *node3 = new Node(41);
    Node *node4 = new Node(58);
    Node *node5 = new Node(69);
    Node *node6 = new Node(75);
    Node *node7 = new Node(82);

    root->left = node1;
    root->right = node2;
    node1->right = node5;
    node1->left = node7;
    node2->left = node4;
    node4->left = node6;
    node4->right = node3;
    int k = 0;
    // cout << heightOfBinaryTree(root);
    KthNode(root,k);
}