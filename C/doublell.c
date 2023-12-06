#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
}; 

struct node* INSERT_B4_HEAD(struct node*,struct node*);
void INSERT_AFTER_GIVEN_NODE(struct node *,struct node *);
struct node* INSERT_B4_GIVEN_NODE(struct node*,struct node*,struct node*);
struct node* INSERT_AT_END_OF_THE_LIST(struct node*,struct node*);
struct node* SEARCH(struct node*,int);
void DISPLAY(struct node*);
struct node* DELETE(struct node*,struct node*);

int main()
{
	int ch1,ch2,flag,key;
	struct node *head = NULL;
	struct node *new = NULL;
	struct node *temp = NULL;
	
	do
	{
		printf("\nMENU\n***********\n");
		printf("1.Insertion\n2.Display\n3.Search\n4.Deletion\nEnter your choice:");
		scanf("%d",&ch1);
		
		switch(ch1)
		{
			case 1:
			
				new = (struct node *)malloc(sizeof(struct node));
				printf("Enter the data to the new node:");
				scanf("%d",&new->data);
				new->next = NULL;
				new->prev = NULL;
				printf("\n1.Before Head\n2.End of the List\n3.After the given Node\n4.Before the given Node\nEnter Your choice:");
				scanf("%d",&ch2);
				
				switch(ch2)
				{
					case 1:
					
						head = INSERT_B4_HEAD(head,new);
						break;
					
					case 2:
						
						head = INSERT_AT_END_OF_THE_LIST(head,new);
						break;
						
					case 3:
						
						printf("Enter the reference key:");
						scanf("%d",&key);
						temp = SEARCH(head,key);
						if(temp == NULL)
						{
							printf("\nU Entered invalid key:");
							break;
						}
						
						INSERT_AFTER_GIVEN_NODE(temp,new);
						break;	
						
					case 4:
						printf("Enter the reference key:");
						scanf("%d",&key);
						temp = SEARCH(head,key);
						if(temp == NULL)
						{
							printf("\nU Entered invalid key:");
							break;
						}
						head = INSERT_B4_GIVEN_NODE(head,temp,new);
						break;
												
				}
				break;
				
			case 2:
				
				DISPLAY(head);
				break;
				
			case 3:
			
				printf("Enter the key to be search:");
				scanf("%d",&key);
				temp = SEARCH(head,key);
				if(temp != NULL)
					printf("\nKey is found");
				else
					printf("Key is not found");
				break;
				
			case 4:
			
				printf("Enter the key to be deleted:");
				scanf("%d",&key);
				temp = SEARCH(head,key);
				if(temp == NULL)
				{
					printf("\nKey is not found");
					break;
				}
				head = DELETE(head,temp);
				break;
			
		}
		printf("\nDo you want to continue (press 1)");
		scanf("%d",&flag);
	}while(flag == 1);
}

struct node *INSERT_B4_HEAD(struct node *head,struct node *new)
{
	new->next  = head;
	if(head != NULL)				//VVIM
		head->prev = new;
	
	head = new;
	return head;			// return new (is also same)
}

struct node *INSERT_AT_END_OF_THE_LIST(struct node *head,struct node *new)
{
	if(head == NULL)
	{
		head = new;
		return head;		// return new (is also same)
	}
	
	struct node *temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	
	temp->next = new;
	new->prev = temp;
	return head;
}

void INSERT_AFTER_GIVEN_NODE(struct node *ref,struct node *new)
{
	new->next = ref->next;
	new->prev = ref;
	ref->next = new;
	if( new->next != NULL)				// VVIM
		new->next->prev = new;
}

struct node* INSERT_B4_GIVEN_NODE(struct node *head,struct node *ref,struct node *new)
{
	new->next = ref;
	new->prev = ref->prev;
	ref->prev = new;
	if( new->prev == NULL )
	{
		head = new;
		return head;
	}
	new->prev->next = new;
	return head;
}

struct node *SEARCH(struct node *head,int key)
{
	struct node *temp = head;
	while(temp != NULL)
	{
		if(temp->data == key)
			return temp;
		temp = temp->next;
	}
	return NULL;
}

void DISPLAY(struct node *head)
{
	struct node *temp = head;
	while(temp != NULL)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
}

struct node* DELETE(struct node *head,struct node *del)
{
	if( del == head )
	{
		head = head->next;
		if( head == NULL )
		{
			free(del);
			return NULL;	//return head is also same 
		}
		head->prev = NULL;
		free(del);
		return head;
	}
	del->prev->next = del->next;
	if( del->next != NULL )
	{
		del->next->prev = del->prev;
		free(del);
		return head;
	}
	free(del);
	return head;
}





