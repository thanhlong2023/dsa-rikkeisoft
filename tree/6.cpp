#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void makeNode(Node *root, int u, int v, char c)
{
    if (c == 'L')
    {
        root->left = new Node(v);
    }
    else
    {
        root->right = new Node(v);
    }
}

void insert(Node *root, int u, int v, char c)
{
    if (root == NULL)
        return;
    if (root->data == u)
    {
        makeNode(root, u, v, c);
    }
    else
    {
        insert(root->left, u, v, c);
        insert(root->right, u, v, c);
    }
}

int check(Node *root)
{
    if (root == NULL)
        return 1;
    if (!root->left && !root->right)
    {
        return 1; // Leaf node
    }
    if (!root->left || !root->right)
    {
        return 0; // Node with only one child
    }
    return check(root->left) && check(root->right); // Both children exist
}

int main()
{
    Node *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (root == NULL)
        {
            root = new Node(x);
            makeNode(root, x, y, c);
            continue;
        }
        insert(root, x, y, c);
    }
    if (check(root))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}