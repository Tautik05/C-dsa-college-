#include<stdio.h>
#include<stdlib.h>

void push(int);

void pop();

void display();
typedef struct node
{
    int info;
    struct node *next;
}ND;
ND *start=NULL;

void main()
{
    int opt,val;

    while(1)
    {
        printf("\n1.insert at begin\n2.delete at end\n3.display\n4.exit\nenter your option:");
        scanf("%d",&opt);
        switch(opt)
        {

        case 1: printf("enter the value to be inserted at end:\n");
            scanf("%d",&val);
            push(val);
            break;
        case 2: pop();
            break;

        case 3:display();
            break;

        case 4:exit(1);
            break;

        default: printf("wrong input\n");

        }
    }
}

void push(int data)
{
    ND *newnode,*temp=start;
    newnode=(ND*)malloc(sizeof(ND));
    newnode->info=data;
    if(start==NULL)
    {
        start=newnode;
        newnode->next=NULL;
    }
    else
    {
        newnode->next=start;
        start=newnode;
    }
}

void pop()
{
    ND *temp=start,*temp1;
    if(start==NULL) 
    {
        printf("list is already empty\n");
    }
	if(start->next==NULL)
	{
        free(start);
        start=NULL;
        return;
	}
	else
	{
        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=NULL;
        free(temp);
	}
}

void display()
{
    ND *temp=start;
    if(start==NULL)
        printf("list is empty\n");

    else
    {
        while(temp->next!=NULL)
        {
            printf("%d->",temp->info);
            temp=temp->next;
        }
        printf("%d->null",temp->info);
    }

}