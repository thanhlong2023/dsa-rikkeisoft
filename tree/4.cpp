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

int cnt = 0;
void inOrder(Node *root)
{
    if (root == NULL)
        return;
    if (!root->left && !root->right)
    {
        cnt++;
    }
    inOrder(root->left);
    // cout << root->data << " ";
    inOrder(root->right);
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
    inOrder(root);
    cout << cnt << endl;
    return 0;
}