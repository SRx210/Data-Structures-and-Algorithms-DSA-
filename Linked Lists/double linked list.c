#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;

void insert_at_beg()
{
    int x;
    printf("Enter element to be inserted at the beginning: ");
    scanf("%d", &x);
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if(start==NULL) //empty list
    {
        tmp->data=x;
        tmp->next=NULL;
        tmp->prev=NULL;
        start=tmp;
        printf("%d element has been inserted in the beginning\n", x);
    }
    else
    {
        tmp->data=x;
        tmp->prev=NULL;
        tmp->next=start;
        start->prev=tmp;
        start=tmp;
        printf("%d element has been inserted in the beginning\n", x);
    }
}

void delete_at_beg()
{
    struct node *p;
    if(start==NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        p=start;
        printf("%d has been deleted from the beginning\n", p->data);
        start=start->next;
        start->prev=NULL;
        free(p);
        return start;
    }
}

void insert_at_end()
{
    int x;
    printf("Enter element to be inserted at the end: ");
    scanf("%d", &x);
    struct node *tmp, *p;
    tmp = (struct node *)malloc(sizeof(struct node));
    if(start==NULL)
    {
        tmp->data;
        tmp->next=NULL;
        tmp->prev=NULL;
        start=tmp;
        return start;
    }
    else{
    p=start;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=tmp;
    tmp->data=x;
    tmp->prev=p;
    tmp->next=NULL;
    printf("%d element has been inserted at the end\n", x);
    return start;
    }

}

void delete_at_end()
{
    struct node *p, *tmp;
    if(start==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        p=start;
        while(p->next->next!=NULL)
        {
            p=p->next;
        }
        tmp=p->next;
        printf("%d has been deleted from the end\n", tmp->data);
        p->next=NULL;
        free(tmp);
    }

}

void display()
{
    struct node *p;
    if(start==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        p=start;
        while(p!=NULL)
        {
            printf("%d\t", p->data);
            p=p->next;
        }
        printf("\n");
    }
}

void insert_after_node()
{
    int x,item;
    printf("Enter element to be inserted: ");
    scanf("%d",&x);
    printf("Enter node: ");
    scanf("%d",&item);
    struct node *tmp, *p;
    tmp = (struct node *)malloc(sizeof(struct node));
    if(start==NULL)
    {
        printf("List is empty\n");
    }
    p=start;
    while(p->data!=item && p->next!=NULL)
    {
        p=p->next;
    }
    if(p->data==item)
    {
        tmp->data=x;
        tmp->prev=p;
        tmp->next=p->next;
        p->next=tmp;
        printf("%d element has been inserted after %d\n",x,item);
        return start;
    }
    printf("%d is not in list", item);
}

void delete_after_node()
{
    int item;
    printf("Enter node: ");
    scanf("%d", &item);
    struct node *p, *tmp;
    if(start==NULL)
    {
        printf("List is empty\n");
    }
    p=start;
    while(p->data!=item && p!=NULL)
    {
        p=p->next;
    }
    if(p->data==item)
    {
        tmp=p->next;
        p->next=tmp->next;
        tmp->next->prev=p;
        printf("%d element has been deleted\n",tmp->data);
        free(tmp);
        return start;
    }
    printf("%d not present in list\n",item);
}

void insert_before_node()
{
    int x,item;
    printf("Enter element to be inserted: ");
    scanf("%d",&x);
    printf("Enter node: ");
    scanf("%d",&item);
    struct node *tmp, *p, *previous;
    tmp = (struct node *)malloc(sizeof(struct node));
    if(start==NULL)
    {
        printf("List is empty, cannot insert before a node\n");
    }
    p=start;
    previous=NULL;
    while(p->data!=item && p!=NULL)
    {
        previous=p;
        p=p->next;
    }
    if(p->data==item)
    {
        tmp->data=x;
        tmp->next=p;
        tmp->prev=previous;
        previous->next=tmp;
        p->prev=tmp;
        printf("%d has been inserted before the node %d\n",x,item);
        return start;
    }
    printf("%d not present in the list\n");
}

void delete_before_node()
{
    int item;
    printf("Enter node: ");
    scanf("%d", &item);
    struct node *p, *tmp, *q;
    if(start==NULL)
    {
        printf("List is empty, cannot insert before a node\n");
    }
    if (start->next == NULL)
    {
        printf("Only one element in the list\n");
        return;
    }
    p=start;
    while(p->next->data!=item && p!=NULL)
    {
        q=p;
        p=p->next;
    }
    tmp=p;
    q->next=p->next;
    p->next=q;
    printf("Element %d has been deleted before the node %d\n", p->data, item);
    free(tmp);
    return start;

}

void insert_at_pos()
{
    int x,pos,i;
    printf("Enter element to be inserted: ");
    scanf("%d", &x);
    printf("Enter position: ");
    scanf("%d", &pos);
    struct node *p,*tmp,*q;
    tmp = (struct node *)malloc(sizeof(struct node));
    if(start==NULL)
    {
        printf("List is empty\n");
    }
    if(pos==1)
    {
        tmp->data=x;
        tmp->prev=NULL;
        tmp->next=start;
        start=tmp;
        printf("%d has been inserted at position 1\n", x);
        return start;
    }
    p=start;
    q=NULL;
    for(i=1;i<pos && p!=NULL;i++)
      {
        q=p;
        p=p->next;
      }
    if (p == NULL && i < pos) {
        printf("Invalid position, cannot insert at position %d\n", pos);}
    if(p->next==NULL)
    {
       tmp->data=x;
       p->next=tmp;
       tmp->prev=p;
       tmp->next=NULL;
       printf("%d has been inserted at position %d",x, pos);
       return;
    }
    else
    {
      tmp->data=x;
      tmp->prev=q;
      tmp->next=p;
      q->next=tmp;
      p->prev=tmp;
      printf("%d has been inserted at position %d\n",x,pos);
      return start;
    }
}

void delete_at_pos()
{
    int pos,i;
    printf("Enter position: ");
    scanf("%d",&pos);
    struct node *p,*tmp,*q;
    if(start==NULL)
    {
        printf("List is empty, cannot delete\n");
    }
    if(pos==1)
    {
        tmp=start;
        start->next->prev=NULL;
        start=start->next;
        printf("%d has been deleted from position 1\n", tmp->data);
        free(tmp);
        return;
    }
    p=start;
    q=NULL;
        for(i=1;i<pos && p!=NULL;i++)
    {
        q=p;
        p=p->next;
    }
    if (p == NULL && i < pos)
    {
        printf("Invalid position\n");
    }
    if(p->next==NULL)
    {
        tmp=p;
        q->next=NULL;
        printf("%d has been deleted from the position %d\n",tmp->data,pos);
        free(tmp);
        return;
    }
    else
        tmp=p;
        q->next=p->next;
        p->next->prev=q;
        printf("%d has been deleted from the position %d\n", tmp->data, pos);
        free(tmp);
        return;
}

void search()
{
    int key,pos=1,found=0;
    struct node *p;
    printf("Enter element to be searched: ");
    scanf("%d", &key);
    if(start==NULL)
    {
        printf("List is empty\n");
    }
    p=start;
    while (p != NULL)
      {
        if (p->data == key)
        {
            printf("Element %d found at position %d\n", key, pos);
            found = 1;
            break;
        }
        p = p->next;;
        pos++;
      }
    if (!found) {
        printf("Element %d not found in the list\n", key);
    }
}

void count()
{
    int count=0;
    struct node *p;
    if(start==NULL)
    {
        printf("List is empty\n");
    }
    p=start;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    printf("%d elements present in the list\n",count);
    return;
}

void reverse()
{
    struct node *p, *q, *next;
    if(start==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        p=start;
        q = NULL;
        while(p!=NULL)
        {
            next = p->next;
            p->next = q;
            q = p;
            p = next;
        }
        start=q;
        printf("List is reversed\n");
    }
}

int main()
{
    int choice;
    char a;
    printf("1. Insert at the beginning\n");
    printf("2. Delete at the beginning\n");
    printf("3. Insert at the end\n");
    printf("4. Delete at the end\n");
    printf("5. Display\n");
    printf("6. Insert after a node\n");
    printf("7. Delete after a node\n");
    printf("8. Insert before a node\n");
    printf("9. Delete before a node\n");
    printf("10. Insert at position\n");
    printf("11. Delete at position\n");
    printf("12. Search\n");
    printf("13. Count\n");
    printf("14. Reverse\n");
    do{
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        insert_at_beg();
        break;

    case 2:
        delete_at_beg();
        break;

    case 3:
        insert_at_end();
        break;

    case 4:
        delete_at_end();
        break;

    case 5:
        display();
        break;

    case 6:
        insert_after_node();
        break;

    case 7:
        delete_after_node();
        break;

    case 8:
        insert_before_node();
        break;

    case 9:
        delete_before_node();
        break;

    case 10:
        insert_at_pos();
        break;

    case 11:
        delete_at_pos();
        break;

    case 12:
        search();
        break;

    case 13:
        count();
        break;

    case 14:
        reverse();
        break;

    default:
        printf("Invalid Choice\n");
        break;
    }
    printf("Do you want to continue (y/n): ");
    scanf(" %c", &a);
   }while(a=='y' || a=='Y');
   return 0;

}
