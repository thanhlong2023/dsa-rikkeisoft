// TÌM GIÁ TRỊ lớn nhất trong cây nhị phân
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int findMax(Node *root)
{
    if (root == NULL)
        return -1; // Hoặc giá trị nhỏ nhất có thể trong cây

    int max = root->data;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    if (leftMax > max)
        max = leftMax;
    if (rightMax > max)
        max = rightMax;

    return max;
}

int main()
{
    Node *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(18);

    int maxValue = findMax(root);
    printf("Giá trị lớn nhất trong cây: %d\n", maxValue);

    // Giải phóng bộ nhớ (không hiển thị ở đây để ngắn gọn)
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}