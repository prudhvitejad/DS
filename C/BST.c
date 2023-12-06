/*properties to satisfy binary search tree
1.All node values of left sub tree are lessthan root node value
2.All node values of right sub tree are greaterthan root node value
3.Sub trees of each node should be Binary search tree it means having above properties
*/
#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node* left;
	struct node* right;
};//here node is created

struct node* newnode(int k)
{
	struct node* new=(struct node*)malloc(sizeof(struct node*)); //memory alloation for node
	new->data=k;
	new->left=NULL;
	new->right=NULL;
	return new;
}

struct node* insertion(struct node* root,int k)
{
	if(root==NULL)
		return newnode(k);
	if(k<root->data)
		root->left=insertion(root->left,k);
	else if(k>root->data)
		root->right=insertion(root->right,k);
	return root;
}

void display(struct node* temp)
{
	if(temp==NULL)
		return;	
	display(temp->left);
	printf("%d->",temp->data);
	display(temp->right);
}

struct node* search(struct node* t,int k)
{
	if(t==NULL)
		return NULL;
	if(t->data==k)
		return t;
	if(k<t->data)
		return search(t->left,k);
	if(k>t->data)
		return search(t->right,k);
}

struct node* findMin(struct node *root)
{
	if(root == NULL)
		return NULL;
	else if(root->left == NULL)
		return root;
	else
		return findMin(root->left);
}

struct node* findMax(struct node *root)
{
	if(root == NULL)
		return NULL;
	else if(root->right == NULL)
		return root;
	else
		return findMax(root->right);
}

struct node* delete(struct node *root,int data)
{
	struct node *temp;
	
	if(root == NULL)
		return root;
	if(data < root->data)							//If data < root->data. data must be present in the left subtree
		root->left = delete(root->left,data);
	else if(data > root->data)						//If data > root->data. data must be present in the right subtree
		root->right = delete(root->right,data);
	else										//This part will be executed only if the root->data == data.The actual removal starts from here
	{
		//Both left and right reference is NULL.replace the node with NULL by returning NULL to the calling pointer.free the node
		
		if( root->left == NULL && root->right == NULL )
		{
			free(root);
			return NULL;
		}
		else if( root->left == NULL )
		{
			temp = root->right;
			free(root);
			return temp;
		}
		else if( root->right == NULL )
		{
			temp = root->left;
			free(root);
			return temp;
		}
		
		temp = findMin(root->right);
		root->data = temp->data;
		root->right = delete(root->right,temp->data);
	}
	return root;
}

int main()
{
	int k,c,f,key,max,min;
	struct node* root=NULL;
	struct node* temp=NULL;
	do
	{
		printf("------Menu-------\n1.insertion\n2.display\n3.Search\n4.Delete\n5.Finding Maximum\n6.Finding Minimum\nEnter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("Enter the number :");
				scanf("%d",&k);
				root=insertion(root,k);
				break;
			case 2:
				display(root);//following inorder gives sorted elements
				printf("\n");
				break;
			case 3:
				printf("Enter the number to search:");
				scanf("%d",&k);
				temp=search(root,k);
				if(temp!=NULL)
					printf("Number is found\n");
				else
					printf("Number is not found\n");
				break;
			
			case 4:
				printf("Enter the Number to be deleted:");
				scanf("%d",&key);
				root = delete(root,key);
				break;
				
			case 5:
				temp = findMax(root);
				printf("\nMaximum = %d\n",temp->data);
				break;
			
			case 6:
				temp = findMin(root);
				printf("\nMinimum = %d\n",temp->data);
				break;
		}
		printf("Press 1 to continue");
		scanf("%d",&f);
	}while(f==1);
}





