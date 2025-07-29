// tìm tầng của node trong cây nhị phân
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

// queue - bằng link list
typedef struct QueueNode
{
    Node *data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue
{
    QueueNode *head;
    QueueNode *tail;
} Queue;

void initQueue(Queue *q)
{
    q->head = q->tail = NULL;
}

int isEmpty(Queue *q)
{
    return q->head == NULL;
}
void enqueue(Queue *q, Node *node)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->data = node;
    newNode->next = NULL;
    if (q->tail == NULL)
    {
        q->head = q->tail = newNode;
    }
    else
    {
        q->tail->next = newNode;
        q->tail = newNode;
    }
}
Node *dequeue(Queue *q)
{
    if (isEmpty(q))
        return NULL;

    QueueNode *temp = q->head;
    Node *node = temp->data;
    q->head = q->head->next;
    if (q->head == NULL)
    {
        q->tail = NULL;
    }
    free(temp);
    return node;
}
int findLevel(Node *root, int x)
{
    if (root == NULL)
        return -1;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);
    int level = 0;

    while (!isEmpty(&q))
    {
        int size = 0;
        QueueNode *temp = q.head;
        while (temp != NULL)
        {
            size++;
            temp = temp->next;
        }

        for (int i = 0; i < size; i++)
        {
            Node *current = dequeue(&q);
            if (current->data == x)
                return level;

            if (current->left != NULL)
                enqueue(&q, current->left);
            if (current->right != NULL)
                enqueue(&q, current->right);
        }
        level++;
    }
    return -1; // Nếu không tìm thấy
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

    int x = 7;
    int level = findLevel(root, x);
    if (level != -1)
        printf("Tầng của node %d là: %d\n", x, level);
    else
        printf("Node %d không tồn tại trong cây.\n", x);

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