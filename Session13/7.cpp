#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Cấu trúc ngăn xếp
typedef struct
{
    char *arr;
    int top;
    int capacity;
} Stack;

Stack createStack(int maxSize)
{
    Stack s;
    s.arr = (char *)malloc(sizeof(char) * maxSize);
    s.top = -1;
    s.capacity = maxSize;
    return s;
}

void push(Stack *s, char value)
{
    if (s->top < s->capacity - 1)
    {
        s->arr[++(s->top)] = value;
    }
}

char pop(Stack *s)
{
    if (s->top == -1)
        return '\0'; // Stack rỗng
    return s->arr[(s->top)--];
}

char peek(Stack *s)
{
    if (s->top == -1)
        return '\0';
    return s->arr[s->top];
}

bool isMatching(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isValidBrackets(const char *expr)
{
    int len = strlen(expr);
    Stack stack = createStack(len);

    for (int i = 0; i < len; ++i)
    {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{')
        {
            push(&stack, c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            char top = pop(&stack);
            if (!isMatching(top, c))
            {
                free(stack.arr);
                return false;
            }
        }
    }

    bool valid = (stack.top == -1);
    free(stack.arr);
    return valid;
}
int main()
{
    char expr[100];

    printf("Nhập biểu thức: ");
    fgets(expr, sizeof(expr), stdin);

    // Xóa ký tự newline '\n' nếu có
    expr[strcspn(expr, "\n")] = 0;

    if (isValidBrackets(expr))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    return 0;
}
