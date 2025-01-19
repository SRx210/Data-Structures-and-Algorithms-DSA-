#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue() {
    int x;
    printf("Enter element to be inserted: ");
    scanf("%d", &x);
    struct node* tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    if (tmp == NULL) {
        printf("Queue underflow\n");
    } else {
        tmp->data = x;
        tmp->link = NULL;
        if (front == NULL) {
            front = rear = tmp;
        } else {
            rear->link = tmp;
            rear = tmp;
        }
        printf("%d inserted at the rear\n", x);
    }
}

void dequeue() {
    struct node* p;
    if (front == NULL) {
        printf("Queue underflow\n");
    } else {
        p = front;
        printf("Element %d deleted from the front\n", p->data);
        front = front->link;
        free(p);
    }
}

void peek() {
    if (front == NULL) {
        printf("Queue underflow\n");
    } else {
        printf("Element at the front is %d\n", front->data);
    }
}

void display() {
    struct node* p;
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        p = front;
        while (p != NULL) {
            printf("%d\t", p->data);
            p = p->link;
        }
        printf("\n");
    }
}

void underflow()
{
  if(front==NULL && rear==NULL)
  {printf("Queue Underflow");}
  else
  {printf("Queue Not Underflow");}
  return;
}

int main() {
    int choice;
    char a;

    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Check Underflow\n");
    printf("4. Peek\n");
    printf("5. Display\n");
    do{
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                underflow();
                break;
            case 4:
                peek();
                break;

            case 5:
             display();
             break;

            default:
                printf("Invalid Choice\n");}
         printf("Do you want to continue? (y/n): ");
        scanf(" %c",&a);
        }while(a == 'y');
        return 0;


}
