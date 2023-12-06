#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

struct node* insert_before_head(struct node*,struct node*);
struct node* insert_at_the_end(struct node*,struct node*);
struct node* insert_before_given_node(struct node*,struct node*,struct node*);
void insert_after_given_node(struct node*,struct node*,struct node*);
struct node* delete(struct node*,struct node*);
struct node* search(struct node*,int);
void display(struct node*);

int main()
{
	struct node *head = NULL;
	struct node *temp = NULL;
	struct node *new = NULL;
	int choice1,key,choice2,choice3;
	
	do
	{
		printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Search\n5.Exit\nEnter Your Choice:");
		scanf("%d",&choice1);
		
		switch(choice1)
		{
			case 1:
				printf("\n1.Before Head\n2.At the End\n3.Before A given Node\n4.After A given Node\nEnter Your Choice:");
				scanf("%d",&choice2);
				new = (struct node*)malloc(sizeof(struct node));
				printf("Enter the data of New Node:");
				scanf("%d",&new->data);
				new->next = NULL;
				
				switch(choice2)
				{
					case 1:
						head = insert_before_head(head,new);
						break;
					
					case 2:
						head = insert_at_the_end(head,new);
						break;
						
					case 3:
						printf("\nEnter the key to insert new node before this key:");
						scanf("%d",&key);
						temp = search(head,key);
						if(temp == NULL)
						{
							printf("\nThe Key You have entered is not available");
							break;
						}
						else
							printf("\nThe Key You have entered is available");
							
						head = insert_before_given_node(head,temp,new);
						break;
						
					case 4:
						printf("\nEnter the key to insert new node after this key:");
						scanf("%d",&key);
						temp = search(head,key);
						if(temp == NULL)
						{
							printf("\nThe Key You have entered is not available");
							break;
						}
						else
							printf("\nThe Key You have entered is available");
							
						insert_after_given_node(head,temp,new);
						break;
				}
				break;
				
			case 2:
				printf("\nEnter the key to deleted:");
				scanf("%d",&key);
				temp = search(head,key);
				if(temp == NULL)
				{
					printf("\nThe Key You have entered is not available");
					break;
				}
				else
					printf("\nThe Key You have entered is available");
				
				head = delete(head,temp);
				break;
			
			case 3:
				display(head);	
				break;
			
			case 4:
				printf("\nEnter the key to search:");
				scanf("%d",&key);
				temp = search(head,key);
				if(temp == NULL)
				{
					printf("\nThe Key You have entered is not available");
					break;
				}
				else
				{
					printf("\nThe Key You have entered is available");
				}
				break;
			
			case 5:
				exit(1);
		}
		
		printf("\nDo You Want to Continue(Press 1):");
		scanf("%d",&choice3);
	}while(choice3 == 1);
}

struct node* insert_before_head(struct node *head,struct node *new)
{
	new->next = head;
	head = new;
	return head;
}

struct node* insert_at_the_end(struct node *head,struct node *new)
{
	if(head == NULL)
	{
		head = new;
		return head;
	}
	struct node *temp = head;
	while(temp->next != NULL)
		temp = temp->next;
		
	temp->next = new;
	return head;
}

struct node* insert_before_given_node(struct node *head,struct node *ref,struct node *new)
{
	if(head == ref)
	{
		new->next = head;
		head = new;
		return head;
	}
	struct node *temp = head;
	while(temp->next != ref)
		temp = temp->next;
		
	new->next = ref;
	temp->next = new;
	return head;
}

void insert_after_given_node(struct node *head,struct node *ref,struct node *new)
{
	new->next = ref->next;
	ref->next = new;
}

struct node* delete(struct node *head,struct node *ref)
{
	struct node *temp = head;
	if(head == ref)
	{
		head = temp->next;
		free(ref);
		return head;
	}
	while(temp->next != ref)
		temp = temp->next;
	
	temp->next = ref->next;
	free(ref);
	return head;
}

void display(struct node *head)
{
	struct node *temp = head;
	while(temp)
	{
		printf("%d->",temp->data);
		temp = temp->next;
	}
}

struct node* search(struct node *head,int key)
{
	struct node *temp = head;
	while(temp != NULL)
	{
		if(temp->data == key)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}


















