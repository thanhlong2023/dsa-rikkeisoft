// chèn cây nhị phân không có thứ tự
#include <iostream>
#include <cstdlib>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
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
    {
        return NULL;
    }

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

// chèn cây nhị phân
void insert(Node **root, int x)
{
    Node *newNode = createNode(x);
    if (*root == NULL)
    {
        *root = newNode;
        return;
    }

    Queue q;
    initQueue(&q);
    enqueue(&q, *root);

    while (!isEmpty(&q))
    {
        Node *current = dequeue(&q);
        if (current->left == NULL)
        {
            current->left = newNode;
            return;
        }
        else
        {
            enqueue(&q, current->left);
        }

        if (current->right == NULL)
        {
            current->right = newNode;
            return;
        }
        else
        {
            enqueue(&q, current->right);
        }
    }
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
    Node *root = NULL;
    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 12);
    insert(&root, 18);

    printf("Inorder traversal: ");
    inorder(root); // result: 3 5 7 10 12 15 18
    printf("\n");

    return 0;
}