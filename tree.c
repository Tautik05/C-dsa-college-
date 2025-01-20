#include<stdio.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *tree=NULL;

struct node *insert_element(struct node*,int);
void preorder_traversal(struct node*);
void inorder_traversal(struct node*);
void postorder_traversal(struct node*);
int total_node(struct node*);
struct node *smallest(struct node*);
struct node *highest(struct node*);

int main()
{
	int option,val,node;
	struct node *ptr;
	
	do
	{
		printf("\n1.Insert element");
		printf("\n2.Preorder traversal");
		printf("\n3.Inorder traversal ");
		printf("\n4.Postorder traversal");
		printf("\n5.total node in the tree");
		printf("\n6. The smallest emement in the tree is:");
		printf("\n7. The highest emement in the tree is:");
		printf("\n8.Exit");
		printf("\nEnter the the choice: ");
        scanf("%d",&option);

    switch(option)
    {
	case 1:
		printf("\nenter the value of the new node");
		scanf("%d",&val);
		tree=insert_element(tree,val);
		break;
	case 2:
		printf("\nThe datas after preorder traversal of the tree :\n");
	    preorder_traversal(tree);
		break;	
	case 3: 
		
	    printf("\nThe datas after inorder traversal of the tree :\n");
	    inorder_traversal(tree);
		break;	
	case 4:
		
	    printf("\nThe datas after postorder traversal of the tree :\n");
	    postorder_traversal(tree);
		break;	
	case 5:
		
	    printf("\nThe total nodes in the tree : :");
	    node=total_node(tree);
	    printf("%d",node);
		break;	
	case 6:
		printf("Finding the smallest element in the tree:");
		ptr=smallest(tree);
		printf("%d",ptr->data);
		break;
	
	case 7:
		printf("Finding the highest element in the tree:");
		ptr=highest(tree);
		printf("%d",ptr->data);
		break;
	

	}
	
}while(option!=9);

return 0;
}

struct node *insert_element(struct node *tree,int val)
{
	struct node *ptr,*nodeptr,*parentptr;
	
	ptr=(struct node *)malloc(sizeof(struct node*));
	printf("%d\t%d",sizeof(struct node),sizeof(struct node*));	
	ptr->data=val;
	ptr->left=NULL;
	ptr->right=NULL;
	
	if(tree==NULL)
	{
		tree=ptr;
		tree->left=NULL;
	    tree->right=NULL;
	}
	else
	{
		parentptr=NULL;
		nodeptr=tree;
		
		while(nodeptr!=NULL )
		{
			parentptr=nodeptr;
			if(val < nodeptr->data)
				nodeptr=nodeptr->left;
			else
				nodeptr=nodeptr->right;
	    }
		if(val<parentptr->data)
			parentptr->left=ptr;
		else
			parentptr->right=ptr;
	}
	return tree;
}

void preorder_traversal(struct node *tree)
{
	if(tree!=NULL)
	{
		printf("%d\t",tree->data);
		preorder_traversal(tree->left);
		preorder_traversal(tree->right);
	}
}

void inorder_traversal(struct node *tree)
{
	if(tree!=NULL)
	{
		inorder_traversal(tree->left);
		printf("%d\t",tree->data);
		inorder_traversal(tree->right);
	}
}

void postorder_traversal(struct node *tree)
{
	if(tree!=NULL)
	{
		postorder_traversal(tree->left);
		postorder_traversal(tree->right);
		printf("%d\t",tree->data);
	
	}
}

int total_node(struct node *tree)
{
	if(tree==NULL)
	return 0;
	else
	return(total_node(tree->left)+total_node(tree->right)+1);
}

struct node *smallest(struct node *tree)
{
	if((tree==NULL)||(tree->left==NULL))
	return tree;
	else
	return smallest(tree->left);
}

struct node *highest(struct node *tree)
{
	if((tree==NULL)||(tree->right==NULL))
	return tree;
	else
	return highest(tree->right);
}
