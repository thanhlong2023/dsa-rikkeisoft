// xóa phần tử trong cây nhị phân
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

Node *deleteNode(Node *root, int x)
{
    if (root == NULL)
        return NULL;
    if (x < root->data)
    {
        root->left = deleteNode(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = deleteNode(root->right, x);
    }
    else
    {
        // Node found
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // Trường hợp node có 2 con: tìm node kế tiếp theo thứ tự (node nhỏ nhất bên cây con phải)
        Node *temp = root->right;
        while (temp && temp->left != NULL)
            temp = temp->left;

        // Sao chép giá trị của node kế tiếp vào node hiện tại
        root->data = temp->data;

        // Xóa node kế tiếp ở cây con phải
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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

    printf("Cây trước khi xóa:\n");
    inorder(root);
    printf("\n");

    int x = 5;
    root = deleteNode(root, x);

    printf("Cây sau khi xóa %d:\n", x);
    inorder(root);
    printf("\n");

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