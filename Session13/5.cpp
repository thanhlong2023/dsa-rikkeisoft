#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int top;
    int capacity;
} Stack;

Stack createStack(int capacity)
{
    Stack stack;
    stack.arr = (int *)malloc(capacity * sizeof(int));
    stack.capacity = capacity;
    stack.top = -1;
    return stack;
}

int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *Stack, int value)
{
    if (!isFull(Stack))
    {
        Stack->arr[++Stack->top] = value;
    }
}

int pop(Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->arr[stack->top--];
    }
    return -1;
}

void reverseArray(int arr[], int size)
{
    Stack stack = createStack(size);
    for (int i = 0; i < size; i++)
    {
        push(&stack, arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = pop(&stack);
    }
    free(stack.arr);
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar();

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    reverseArray(arr, n);
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i != n - 1)
            printf(", ");
    }
    printf("]\n");
    free(arr);
    return 0;
}