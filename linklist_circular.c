#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;

};
struct node *start=NULL;

struct node *create(struct node*);
struct node *traverse(struct node*);
struct node *insert_at_beg(struct node*);
struct node *insert_at_end(struct node*);
struct node *delete_beg(struct node*);
struct node *delete_end(struct node*);

int main()
{
int choice;


do
{

printf("\n1. Enter 1 to create a link list.\n");
printf("2. Enter 2 to traverse a link list.\n");
printf("3. Enter 3 to insert at beg.\n");
printf("4. Enter 4 to insert at end.\n");
printf("5. Enter 5 to delete at beg.\n");
printf("6. Enter 6 to delete at end.\n");
printf("7. Enter 0 to EXIT\n");
printf("Enter the the choice: ");
scanf("%d",&choice);

switch(choice)
{
	case 1:
		start=create(start);
		printf("\nlink list created.\n");
		break;
	case 2:
		printf("\nThe elements of the link list are:\n");
		start=traverse(start);
		break;
	case 3:

		start=insert_at_beg(start);
		break;
	case 4:

		start=insert_at_end(start);
		break;

	case 5:

		start=delete_beg(start);
		break;
	case 6:

		start=delete_end(start);
		break;
	case 0:

		exit(0);
}
}while(choice!=0);
}


struct node *create(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
	printf("\nEnter -1 to exit :");
	printf("\nEnter the data:");
	scanf("%d",&num);
	while(num !=-1)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->data=num;


		if(start==NULL)
		{

			new_node->next=new_node;
            start=new_node;
		}
		else
		{   ptr=start;
			while(ptr->next!=start)
			{
				ptr=ptr->next;
			}
		    ptr->next=new_node;

			new_node->next=start ;



		}

		printf("\nEnter the data:");
		scanf("%d",&num);

	}

	return start;
}

struct node *traverse(struct node *start)
{
struct node *ptr;
ptr=start;

while(ptr->next!=start)
{
	printf("\t %d",ptr->data);
	ptr =ptr->next;
}
printf("\t %d",ptr->data);
return start;
}

struct node *insert_at_beg(struct node *start)
{
struct node *new_node,*ptr;
int num;

new_node=(struct node *)malloc(sizeof(struct node));
printf("\nEnter the data to be inserted:");
scanf("%d",&num);
new_node->data=num;
ptr=start;
while(ptr->next!=start)
		ptr= ptr->next;
ptr->next=new_node;
new_node->next=start;
start=new_node;
return start;

}

struct node *insert_at_end(struct node *start)
{
struct node *ptr,*new_node;
int num;
ptr=start;
new_node=(struct node *)malloc(sizeof(struct node));
printf("\nEnter the data to be inserted:");
scanf("%d",&num);
new_node->data=num;
while(ptr->next!=start)
	ptr=ptr->next;

ptr->next=new_node;
new_node->next=start;

return start;

}

struct node *delete_beg(struct node *start)
{
struct node *ptr;
ptr=start;
while(ptr->next!=start)
	ptr=ptr->next;
ptr->next=start->next;
start=ptr->next;
return start;
}

struct node *delete_end(struct node *start)
{
struct node *ptr,*preptr;
ptr=start;
while(ptr->next!=start)
{   preptr=ptr;
	ptr=ptr->next;
}
preptr->next=ptr->next;
return start;
}

