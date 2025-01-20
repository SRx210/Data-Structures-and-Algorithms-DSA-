#include<stdio.h>
#define n 10
int top=-1, s[n];
void push();
void pop();
void peek();
void display();
void main()
{
    int choice;
    do{
    printf("Enter 1 for push operation\n");
    printf("Enter 2 for pop operation\n");
    printf("Enter 3 for peek operation\n");
    printf("Enter 4 for display operation\n");
    printf("Enter 5 to exit\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        push();
        break;

    case 2:
        pop();
        break;

    case 3:
        peek();
        break;

    case 4:
        display();
        break;

    case 5:
        exit(0);

    default:
            printf("Invalid Choice");
    }
    }
    while(choice!=0);
    return 0;
}

void push()
{
    int x;
    printf("Enter Value to be pushed in stacks: ");
    scanf("%d", &x);
    if(top==n-1)
    {
        printf("Stack is overflow");
    }
    else{
        top++;
        s[top]=x;}

}
void pop()
{
    if(top==-1)
    {
        printf("Stack is underflow");
    }
    else
    {
        top--;
    }
}
void peek()
{
   if(top==-1)
   {
       printf("Stack is empty");
   }
   else
   {
       printf("The Top most element is %d", s[top]);
   }
}
void display()
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%d\t",s[i]);
    }
    printf("\n");
}
