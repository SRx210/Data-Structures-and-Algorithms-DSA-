#include<stdio.h>
#define n 10
void enqueue();
void dequeue();
void display();
void peek();
int q[n];
int rear=- 1;
int front=- 1;
void main()
{
    int choice;
    do
    {
        printf("Enter 1 to insert element in queue \n");
        printf("Enter 2 delete element from queue \n");
        printf("Enter 3 display elements of queue \n");
        printf("Enter 4 peek elements in queue \n");
        printf("Enter 5 to exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                peek();
                break;

            case 5:
                exit(0);

            default:
            printf("Wrong choice \n");
        }
    }while(choice!=0);
     return 0;
}

void enqueue()
{
    int z;
    if (rear == n - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &z);
        rear = rear + 1;
        q[rear] = z;
    }
}

void dequeue()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", q[front]);
        front = front + 1;
    }
}

void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i=front;i<=rear;i++)
        printf("%d ", q[i]);
        printf("\n");
    }
}
void peek()
{
   if(front == -1)
   {
       printf("Queue is empty");
   }
   else
   {
       printf("The top most element is %d\n", q[rear]);
   }
}
