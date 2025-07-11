#include <bits/stdc++.h>

struct node
{
    char data[100];
    int tanSuat;
    struct node *next;
};
typedef struct node Node;

node *makeNode(char c[])
{
    node *newNode = (node *)malloc(sizeof(node));
}