#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node* start=NULL;

void insert_beg()
{
    int x;
    printf("Enter Value to be inserted at the beginning: ");
    scanf("%d", &x);
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if(start==NULL) // if list is empty
    {
        tmp->data=x;
        tmp->link=NULL;
        start=tmp;
        printf("%d value inserted at beginning",x);
        return start;
    }
    else
        tmp->data=x;
        tmp->link=start;
        start=tmp;
        printf("%d value inserted at beginning",x);
        return start;
}
void insert_end()
{
    int x;
    printf("Enter value to be inserted at end: ");
    scanf("%d", &x);
    struct node *tmp, *p;
    tmp = (struct node *)malloc(sizeof(struct node));
    p=start;
    if(start==NULL)
    {
        tmp->data=x;
        tmp->link=NULL;
        start=tmp;
        printf("%d value inserted at end",x);
        return start;
    }
        while(p->link!=NULL)
    {
        p=p->link;
    }
    p->link=tmp;
    tmp->data=x;
    tmp->link=NULL;
    printf("%d value inserted at end",x);
    return start;
}
void *delete_beg()
{
    struct node *p, *tmp;
    if(start==NULL)
    {
        printf("List is empty");
        return start;
    }
    tmp = start;
    start = start->link;
    free(tmp);
    printf("Element in the beginning deleted from the list\n");
}
void *delete_end()
    {
    struct node *p;
    if(start==NULL)
        {
        printf("LIST IS EMPTY\n");
        return start;
        }
    else if(start->link==NULL)
        {
        p=start;
        printf("%d has been deleted from end\n",p->data);
        free(p);
        start=NULL;
        return start;
        }
    else
        {
        p=start;
        while(p->link->link!=NULL)
            {p=p->link;}
        printf("Element %d has been deleted from the End\n",p->link->data);
        free(p->link);
        p->link=NULL;
        }
}

void *insert_after()
{
    int x,item;
    printf("Enter element to be inserted: ");
    scanf("%d", &x);
    printf("Enter element after which you want to insert: ");
    scanf("%d", &item);
    struct node *tmp, *p;
    p=start;
    while(p->data!=item && p!=NULL)
    {
        p=p->link;
    }
    if(p->data==item)
    {
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->data=x;
        tmp->link=p->link;
        p->link=tmp;
    }
    return start;
}
void *insert_before()
{
   int x, item;
    struct node *tmp, *p, *prev;
    tmp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the element you want to insert: ");
    scanf("%d", &x);
    printf("Enter the element before which you want to insert: ");
    scanf("%d", &item);
    tmp->data = x;
    if (start == NULL) {
        tmp->link = NULL;
        start = tmp;
        printf("Element %d inserted before %d\n", x, item);
        return;
    }
    if (start->data == item)
    {
        tmp->link = start;
        start = tmp;
        printf("Element %d inserted before %d.\n", x, item);
        return;
    }
    p = start;
    prev = NULL;
    while (p != NULL && p->data != item) {
        prev = p;
        p = p->link;
    }
    if (p == NULL) {
        printf("Element %d not found in the list\n", item);
    } else {
        prev->link = tmp;
        tmp->link = p;
        printf("Element %d inserted before %d\n", x, item);
    }
}
void delete_before()
{
    int item;
    struct node *tmp, *p, *prev;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    if (start->link == NULL) {
        printf("Only one element in the list\n");
        return;
    }
    printf("Enter the element before which you want to delete: ");
    scanf("%d", &item);
    p = start;
    prev = NULL;
    while (p != NULL && p->data != item) {
        prev = p;
        p = p->link;
    }
    if (p == NULL) {
        printf("Element %d not found in the list\n", item);}
    else if (prev == NULL) {
        printf("Cannot delete before the first element in the list\n");}
     else {
        tmp = prev->link;
        prev->link = tmp->link;
        free(tmp);
        printf("Element before %d deleted from the list.\n", item);}
}

void delete_after() {
    int item;
    struct node *tmp, *p;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter the element after which you want to delete: ");
    scanf("%d", &item);
    p = start;
    while (p != NULL && p->data != item) {
        p = p->link;
    }
    if (p == NULL) {
        printf("Element %d not found in the list\n", item);
    } else if (p->link == NULL) {
        printf("No element to delete after %d\n", item);
    } else {
        tmp = p->link;
        p->link = tmp->link;
        free(tmp);
        printf("Element after %d deleted from the list\n", item);
    }
}
void insert_pos() {
    int x, pos, i;
    struct node *tmp, *p, *prev;
    tmp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the element you want to insert: ");
    scanf("%d", &x);
    printf("Enter the position at which you want to insert: ");
    scanf("%d", &pos);
    tmp->data = x;
    if (pos == 1) {
        tmp->link = start;
        start = tmp;
        printf("Element %d inserted at position %d\n", x, pos);
        return;
    }
    p = start;
    prev = NULL;
    for (i = 1; i < pos && p != NULL; i++) {
        prev = p;
        p = p->link;
    }
    if (p == NULL && i < pos) {
        printf("Invalid position. Cannot insert at position %d\n", pos);
    } else {
        prev->link = tmp;
        tmp->link = p;
        printf("Element %d inserted at position %d\n", x, pos);
    }
}

void delete_pos() {
    int pos, i;
    struct node *tmp, *p, *prev;
    printf("Enter the position from which you want to delete: ");
    scanf("%d", &pos);
    if (pos == 1) {
        tmp = start;
        start = start->link;
        free(tmp);
        printf("Element deleted from position %d\n", pos);
        return;
    }
    p = start;
    prev = NULL;
    for (i = 1; i < pos && p != NULL; i++) {
        prev = p;
        p = p->link;
    }
    if (p == NULL && i < pos)
    {
        printf("Invalid position");
    }
    else
    {
        tmp = p;
        prev->link = tmp->link;
        free(tmp);
        printf("Element deleted from position %d\n", pos);
    }
}

void display()
{
    struct node *p;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    p = start;
    printf("Linked List: ");
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("NULL\n");
}

void search()
{
    struct node* p = start;
    int key, pos = 1, found = 0;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Enter the element you want to search for: ");
    scanf("%d", &key);
    while (p != NULL) {
        if (p->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            found = 1;
            break;
        }
        p = p->link;
        pos++;
    }
    if (!found) {
        printf("Element %d not found in the list\n", key);
    }
}
void reverse()
{
    struct node *prev, *current, *next;
    prev = NULL;
    current = start;
    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    start = prev;
    printf("List has been reversed\n");
}
void count()
{
    struct node *p;
    int cnt=0;
    p=start;

    while(p!=NULL)
        {
        p=p->link;
        cnt++;
        }
    printf("Number of elements are %d\n",cnt);
}



int main()
{
    int choice;
    char a;
    printf("Enter 1 to insert element in the beginning\n");
    printf("Enter 2 to insert element in the end\n");
    printf("Enter 3 to insert element after a node\n");
    printf("Enter 4 to insert element before a node\n");
    printf("Enter 5 to insert element at a given position\n");
    printf("Enter 6 to delete element in the beginning\n");
    printf("Enter 7 to delete element in the end\n");
    printf("Enter 8 to delete element in after a node\n");
    printf("Enter 9 to delete element in before a node\n");
    printf("Enter 10 to delete element at the given position\n");
    printf("Enter 11 to search elements in list\n");
    printf("Enter 12 to reverse elements in list\n");
    printf("Enter 13 to display linked list\n");
    printf("Enter 14 to count elements in list\n");
    do{
            printf("Enter choice: ");
            scanf("%d", &choice);
            switch(choice)
            {

            case 1:
                insert_beg();
                break;

            case 2:
                insert_end();
                break;

            case 3:
                insert_after();
                break;

            case 4:
                insert_before();
                break;

            case 5:
                insert_pos();
                break;

            case 6:
                delete_beg();
                break;

           case 7:
                delete_end();
                break;

            case 8:
                delete_after();
                break;

            case 9:
                delete_before();
                break;

            case 10:
                delete_pos();
                break;

            case 11:
                search();
                break;

            case 12:
                reverse();
                break;

            case 13:
                display();
                break;

            case 14:
                count();
                break;


            default:
                printf("Invalid Choice");

            }
            printf("\nEnter 'y' to continue or 'n' to exit: ");
            scanf(" %c", &a);
            }while(a == 'y');
             return 0;
}
