#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue() {
    int x;
    printf("Enter value to be inserted: ");
    scanf("%d", &x);
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL) {
        printf("Queue overflow\n");
    } else if (front == NULL && rear == NULL) {
        tmp->data = x;
        tmp->link = tmp; // Point to itself in a circular queue
        rear = tmp;
        front = tmp;
        printf("%d has been inserted\n", x);
    } else {
        tmp->data = x;
        tmp->link = front;
        rear->link = tmp;
        rear = tmp;
        printf("%d has been inserted\n", x);
    }
}

void dequeue() {
    struct node *tmp;
    if (front == NULL) {
        printf("Queue underflow\n");
    } else {
        tmp = front;
        front = front->link;
        rear->link = front;
        printf("%d has been deleted\n", tmp->data);
        free(tmp);
    }
}

void peek() {
    if (front == NULL) {
        printf("Queue underflow\n");
    } else {
        printf("%d is the front element\n", front->data);
    }
}

void underflow() {
    if (front == NULL) {
        printf("Queue underflow\n");
    } else {
        printf("Queue NOT underflow\n");
    }
}

void display() {
    struct node *p;
    if (front == NULL) {
        printf("Queue underflow\n");
    } else {
        p = front;
        do {
            printf("%d\t", p->data);
            p = p->link;
        } while (p != front);
    }
    printf("\n");
}

int main() {
    int choice;
    char a;
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. Check underflow\n");
    printf("5. Display\n");
    do {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                underflow();
                break;

            case 5:
                display();
                break;

            default:
                printf("Invalid Choice\n");
                break;
        }
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &a);
    } while (a == 'Y' || a == 'y');

    return 0;
}
