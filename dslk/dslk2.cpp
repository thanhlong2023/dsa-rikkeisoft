#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

node* makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void traverse(node *head){
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
}
int size(node *head){
    int cnt = 0;
    while(head != NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}
//thêm đầu
void pushFront(node **head, int x){
    node *newNode = makeNode(x);
    newNode->next = *head;
    if(*head != NULL){
        (*head)->prev = newNode;
    }
    *head = newNode;
}
//thêm cuối
void pushBack(node **head, int x){
    node *newNode = makeNode(x);
    if(*head == NULL){
        *head = newNode;return;
    }
    node *tmp = *head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
}
//thêm vào pos
void inser(node **head, int x, int pos){
    int n = size(*head);
    if(pos < 1 || pos > n+1){
        printf("Vi tri khong hop le\n");
        return;
    }
    if(pos == 1){
        pushFront(head,x);
    }else if(pos == n+1){
        pushBack(head,x);
    }else{
        node *tmp = *head;
        for(int i = 1; i < pos-1; i++){
            tmp = tmp->next;
        }
        node *newNode = makeNode(x);
        newNode->next = tmp->next;
        newNode->prev = tmp;
        tmp->next->prev = newNode;
        tmp->next = newNode;
    }
}
void duyetNguoc(node *head){
    if(head == NULL){
        printf("Danh sach rong\n");
        return;
    }
    while(head->next != NULL){
        head = head->next;
    }
    while(head != NULL){
        printf("%d ",head->data);
        head = head->prev;
    }
    printf("\n");
}

void sort(node **head){
    for(node *i = *head; i != NULL; i = i->next){
        for(node *j = i->next; j != NULL; j = j->next){
            if(i->data > j->data){
                int tmp = i->data;
            }
        }
    }
}
