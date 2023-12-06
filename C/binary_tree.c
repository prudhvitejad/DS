#include <stdio.h>
#include <stdlib.h>
#define max 10

struct node 
{
	int data;
	struct node *left;
	struct node *right;
};

struct node* Queue[max];
int rear=-1,front=-1;

void Enqueue(struct node *root)
{
	if(front==(rear+1)%max)
		printf("\n-----Circular Queue overflow------\n");
	else
	{
		if(rear==-1 && front==-1)
		{
			front=rear=0;	
			Queue[front]=root;
			return;
		}
		rear=(rear+1)%max;
					
		Queue[rear]=root;
	}
}

struct node* Dequeue()
{
	int temp;
	if(front==-1&&rear==-1)
	{
		printf("\n-----Queue Underflow------\n");
	}
	else if(front==rear)
	{
		//printf("Deleted element is %d",Queue[front]);
		temp = front;
		front=rear=-1;
		return Queue[temp];
	}
	else
	{
		//printf("Deleted element is %d",Queue[front]);
		temp = front;
		front=(front+1)%max;
		return Queue[temp];
	}
}

int isEmptyQueue()
{
	if(front == -1 && rear == -1)
		return 1;
	else
		return 0;
}

struct node* insert(struct node *root,int data)
{
	struct node *temp;
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = data;
	new->left = new->right = NULL;
	
	if(!root)
	{
		root = new;
		return root;
	}
	
	Enqueue(root);
	
	while(!isEmptyQueue())
	{
		temp = Dequeue();
		if(temp->left)
			Enqueue(temp->left);
		else
		{
			temp->left = new;
			while(!isEmptyQueue())
				Dequeue();
				
			return root;
		}
		
		if(temp->right)
			Enqueue(temp->right);
		else
		{
			temp->right = new;
			while(!isEmptyQueue())
				Dequeue();

			return root;
		}
	}
	
}

void preorder(struct node *root)
{
	if(root)
	{
		printf("%d->",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct node *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d->",root->data);
		inorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d->",root->data);
	}
}

void levelorder(struct node *root)
{
	struct node *temp;
	if(!root)
		return;
	Enqueue(root);
	while(!isEmptyQueue())
	{
		temp = Dequeue();
		printf("%d->",temp->data);
		if(temp->left)
			Enqueue(temp->left);
		if(temp->right)
			Enqueue(temp->right);
	}
}

struct node* search(struct node *root,int data)
{
	struct node *temp;
	if(root == NULL)
		return NULL;
	else
	{
		if(root->data == data)
			return root;
		else
		{
			temp = search(root->left,data);
			if(temp != NULL)
				return temp;
			else return search(root->right,data);
		}
	}
	return NULL;
}

struct node* delete_full_tree(struct node *root)
{
	if( root == NULL )
		return NULL;
		
	delete_full_tree(root->left);
	delete_full_tree(root->right);
	
	free(root);
}

struct node* swap(struct node *root)
{
	struct node *temp;
	if(root)
	{
		swap(root->left);
		swap(root->right);
		
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
	return root;
}


int main()
{
	int ch1,ch2,flag,key,val;
	struct node *root = NULL;
	struct node *new = NULL;
	struct node *temp = NULL;
	
	do
	{
		printf("\nMENU\n***********\n");
		printf("1.Insertion\n2.Display\n3.Search\n4.Deletion(Entire tree deletion)\n5.Exit\n6.QueueEmpty\n7.Swap Left and Right Childs\nEnter your choice:");
		scanf("%d",&ch1);
		
		switch(ch1)
		{
			case 1:
				printf("Enter The value:");
				scanf("%d",&val);
				root = insert(root,val);
				break;
				
			case 2:
				printf("\n1.PreOrder\n2.InOrder\n3.PostOrder\n4.LevelOrder\nEnter Your Choice:");
				scanf("%d",&ch2);
				
				switch(ch2)
				{
					case 1:
						preorder(root);
						break;
					
					case 2:
						inorder(root);
						break;
					
					case 3:
						postorder(root);
						break;
					
					case 4:
						levelorder(root);
						break;
				}
				break;
				
			case 3:
				printf("Enter the key to be searched:");
				scanf("%d",&key);
				temp = search(root,key);
				if( temp == NULL )
					printf("\nThe key is not found\n");
				else
					printf("\nThe key is found\n");
				break;
				
			case 4:
				root = delete_full_tree(root);
				break;
				
			case 5:
				exit(0);
				break;
			
			case 6:
				key = isEmptyQueue();
				if(key==1)
					printf("\nQueue is Empty\n");
				else
					printf("\nQueue is not Empty\n");
				break;
			
			case 7:
				root = swap(root);
				break;
		}
		
		printf("\nDo you want to continue (press 1)");
		scanf("%d",&flag);
	}while(flag == 1);
}





