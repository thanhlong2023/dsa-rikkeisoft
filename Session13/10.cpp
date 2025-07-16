#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Stack chứa ký tự toán tử
typedef struct
{
    char *arr;
    int top;
    int capacity;
} Stack;

Stack createStack(int capacity)
{
    Stack s;
    s.arr = (char *)malloc(sizeof(char) * capacity);
    s.top = -1;
    s.capacity = capacity;
    return s;
}

void push(Stack *s, char c)
{
    s->arr[++(s->top)] = c;
}

char pop(Stack *s)
{
    if (s->top == -1)
        return '\0';
    return s->arr[(s->top)--];
}

char peek(Stack *s)
{
    if (s->top == -1)
        return '\0';
    return s->arr[s->top];
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

char *infixToPostfix(const char *expr)
{
    int len = strlen(expr);
    Stack stack = createStack(len);
    char *result = (char *)malloc(len * 2); // dự phòng cho chuỗi kết quả
    int k = 0;

    for (int i = 0; i < len; ++i)
    {
        char c = expr[i];

        if (isspace(c))
            continue;

        if (isdigit(c))
        {
            result[k++] = c;
        }
        else if (c == '(')
        {
            push(&stack, c);
        }
        else if (c == ')')
        {
            while (peek(&stack) != '(')
            {
                result[k++] = pop(&stack);
            }
            pop(&stack); // bỏ dấu '('
        }
        else if (isOperator(c))
        {
            while (stack.top != -1 && precedence(peek(&stack)) >= precedence(c))
            {
                result[k++] = pop(&stack);
            }
            push(&stack, c);
        }
    }

    while (stack.top != -1)
    {
        result[k++] = pop(&stack);
    }

    result[k] = '\0';
    free(stack.arr);
    return result;
}
int main()
{
    char expr[100];

    printf("Nhập biểu thức infix: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0;

    char *postfix = infixToPostfix(expr);
    printf("%s\n", postfix);

    free(postfix);
    return 0;
}
