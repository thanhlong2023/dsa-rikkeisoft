#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Cấu trúc stack cho số nguyên
typedef struct
{
    int *arr;
    int top;
    int capacity;
} Stack;

Stack createStack(int capacity)
{
    Stack s;
    s.arr = (int *)malloc(sizeof(int) * capacity);
    s.top = -1;
    s.capacity = capacity;
    return s;
}

void push(Stack *s, int value)
{
    if (s->top < s->capacity - 1)
        s->arr[++(s->top)] = value;
}

int pop(Stack *s)
{
    if (s->top == -1)
        return 0; // Underflow, mặc định là 0
    return s->arr[(s->top)--];
}

int evaluatePostfix(const char *expr)
{
    int len = strlen(expr);
    Stack stack = createStack(len);

    for (int i = 0; i < len; ++i)
    {
        char c = expr[i];

        if (isdigit(c))
        {
            // Chuyển ký tự thành số và push
            push(&stack, c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            int b = pop(&stack);
            int a = pop(&stack);
            int result;

            switch (c)
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                if (b == 0)
                {
                    printf("Divide by zero error\n");
                    free(stack.arr);
                    return 0;
                }
                result = a / b;
                break;
            }

            push(&stack, result);
        }
    }

    int finalResult = pop(&stack);
    free(stack.arr);
    return finalResult;
}
int main()
{
    char expr[100];

    printf("Nhập biểu thức hậu tố (postfix): ");
    fgets(expr, sizeof(expr), stdin);

    // Xóa ký tự newline '\n' nếu có
    expr[strcspn(expr, "\n")] = 0;

    int result = evaluatePostfix(expr);
    printf("%d\n", result);

    return 0;
}
