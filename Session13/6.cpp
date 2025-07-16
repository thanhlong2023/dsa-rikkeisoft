#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

bool isPalindrome(char *str)
{
    int len = strlen(str);
    Stack stack = createStack(len);

    for (int i = 0; i < len; i++)
    {
        push(&stack, str[i]);
    }

    for (int i = 0; i < len; i++)
    {
        char fromStack = pop(&stack);
        if (str[i] != fromStack)
        {
            free(stack.arr);
            return false;
        }
    }

    free(stack.arr);
    return true;
}

int main()
{
    char str[1000];

    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    return 0;
}