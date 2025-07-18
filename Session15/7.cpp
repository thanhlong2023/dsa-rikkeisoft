#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define NAME_LENGTH 31

typedef struct
{
    char name[NAME_LENGTH];
} Customer;

typedef struct
{
    Customer customers[MAX_CUSTOMERS];
    int front;
    int rear;
    int size;
} Queue;

// Khởi tạo hàng đợi
void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Kiểm tra rỗng
int isEmpty(Queue *q)
{
    return q->size == 0;
}

// Kiểm tra đầy
int isFull(Queue *q)
{
    return q->size == MAX_CUSTOMERS;
}

// Thêm khách vào hàng đợi
void enqueue(Queue *q, char *name)
{
    if (isFull(q))
    {
        printf("Hàng đợi đã đầy. Không thể thêm khách mới.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_CUSTOMERS;
    strncpy(q->customers[q->rear].name, name, NAME_LENGTH - 1);
    q->customers[q->rear].name[NAME_LENGTH - 1] = '\0'; // Đảm bảo kết thúc chuỗi
    q->size++;
    printf("Đã thêm khách \"%s\" vào hàng đợi.\n", name);
}

// Phục vụ khách
void dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Hàng đợi rỗng. Không có khách để phục vụ.\n");
        return;
    }
    printf("Phục vụ khách: %s\n", q->customers[q->front].name);
    q->front = (q->front + 1) % MAX_CUSTOMERS;
    q->size--;
}

// Hiển thị danh sách khách đang chờ
void displayQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Hàng đợi rỗng.\n");
        return;
    }
    printf("Danh sách khách đang chờ:\n");
    for (int i = 0; i < q->size; i++)
    {
        int index = (q->front + i) % MAX_CUSTOMERS;
        printf("%d. %s\n", i + 1, q->customers[index].name);
    }
}

// Menu thao tác
void menu()
{
    printf("\n--- MENU ---\n");
    printf("1. Thêm khách hàng mới vào hàng đợi\n");
    printf("2. Phục vụ khách hàng\n");
    printf("3. Hiển thị danh sách khách đang chờ\n");
    printf("4. Thoát chương trình\n");
    printf("Chọn thao tác (1-4): ");
}

int main()
{
    Queue q;
    initQueue(&q);

    int choice;
    char name[NAME_LENGTH];

    do
    {
        menu();
        scanf("%d", &choice);
        getchar(); // Xóa ký tự '\n' sau scanf

        switch (choice)
        {
        case 1:
            printf("Nhập tên khách hàng: ");
            fgets(name, NAME_LENGTH, stdin);
            name[strcspn(name, "\n")] = 0; // Xóa ký tự '\n' nếu có
            enqueue(&q, name);
            break;

        case 2:
            dequeue(&q);
            break;

        case 3:
            displayQueue(&q);
            break;

        case 4:
            printf("Thoát chương trình.\n");
            break;

        default:
            printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
        }
    } while (choice != 4);

    return 0;
}
