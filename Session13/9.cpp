#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Cấu trúc stack chứa chuỗi
typedef struct
{
    char **arr;
    int top;
    int capacity;
} Stack;

Stack createStack(int capacity)
{
    Stack s;
    s.arr = (char **)malloc(sizeof(char *) * capacity);
    s.top = -1;
    s.capacity = capacity;
    return s;
}

void push(Stack *s, const char *str)
{
    s->arr[++(s->top)] = strdup(str); // copy chuỗi vào stack
}

char *pop(Stack *s)
{
    if (s->top == -1)
        return NULL;
    return s->arr[(s->top)--];
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

char *postfixToInfix(const char *expr)
{
    int len = strlen(expr);
    Stack stack = createStack(len);

    for (int i = 0; i < len; ++i)
    {
        char c = expr[i];

        if (isdigit(c))
        {
            // Chuyển số thành chuỗi rồi push
            char temp[2] = {c, '\0'};
            push(&stack, temp);
        }
        else if (isOperator(c))
        {
            char *right = pop(&stack);
            char *left = pop(&stack);

            // Cộng chuỗi theo dạng: (left op right)
            char *newExpr = (char *)malloc(strlen(left) + strlen(right) + 4);
            sprintf(newExpr, "(%s%c%s)", left, c, right);

            // Push lại
            push(&stack, newExpr);

            // Free tạm thời để tránh rò rỉ
            free(left);
            free(right);
        }
    }

    char *result = pop(&stack);
    free(stack.arr);
    return result;
}
int main()
{
    char expr[100];

    printf("Nhập biểu thức hậu tố (postfix): ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0; // Xóa \n

    char *infix = postfixToInfix(expr);
    printf("%s\n", infix);

    free(infix);
    return 0;
}
