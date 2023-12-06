#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node* insert_before_head(struct node *head,struct node *new)
{
	if(head == NULL)
	{
		head = new;
		head->next = head;
		return head;
	}
	
	if(head->next == head)
	{
		new->next = head;
		head->next = new;
		head = new;
		return head;
	}
	
	struct node *temp = head;
	while(temp->next != head)
		temp = temp->next;
	
	temp->next = new;
	new->next = head;
	head = new;
	return head;
}

struct node* insert_at_the_end(struct node *head,struct node *new)
{
	if(head == NULL)
	{
		head = new;
		head->next = head;
		return head;
	}
	
	if(head->next == head)
	{
		new->next = head;
		head->next = new;
		return head;
	}
	
	struct node *temp = head;
	
	while(temp->next != head)
		temp = temp->next;
	
	new->next = head;
	temp->next = new;
	return head;
}

struct node* insert_before_given_node(struct node *head,struct node *new,struct node *ref)
{
	if(head->next == head)
	{
		if(head == ref)
		{
			new->next = head;
			head->next = new;
			head = new;
			return head;
		}
	}
	
	struct node *temp = head;
	while(temp->next != ref)
		temp = temp->next;
	
	new->next = ref;
	temp->next = new;
	if(head == ref)
		head = new;
	return head;
}

struct node* delete(struct node *head,struct node *ref)
{
	if(head->next == head && head == ref)
	{
		free(ref);
		return NULL;
	}
	struct node *temp = head;
	
	while(temp->next != ref)
		temp = temp->next;
	
	temp->next = ref->next;
	head = ref->next;
	free(ref);
	return head;
}

struct node* search(struct node *head,int key)
{
	if(head == NULL)
		return NULL;
	if(head->next == head)
	{
		if(head->data == key)
			return head;
		else
			return NULL;
	}
	
	struct node *temp = head;
	
	while(temp->next != head)
	{
		if(temp->data == key)
			return temp;
		temp = temp->next;
	}
	if(temp->data == key)
		return temp;
	return NULL;
}

void display(struct node *head)
{
	if(head == NULL)
		return;
	if(head->next == head)
	{
		printf("%d\t",head->data);
		return;
	}
	
	struct node *temp = head;
	while(temp->next != head)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("%d\t",temp->data);
	
}

int main()
{
	struct node *head = NULL;
	struct node *temp = NULL;
	struct node *new = NULL;
	int key;
	
	for(int i=0;i<5;i++)
	{
		new = (struct node*)malloc(sizeof(struct node));
		printf("Enter the data:");
		scanf("%d",&new->data);
		new->next = NULL;
		//head = insert_before_head(head,new);
		
		head = insert_at_the_end(head,new);
	}
	display(head);
	
	printf("\nEnter key for which new node should be inserted before it:");
	scanf("%d",&key);
	temp = search(head,key);
	if(temp == NULL)
		printf("\nKey not found");
	else
	{
		printf("\nKey is there");
		
		new = (struct node*)malloc(sizeof(struct node));
		printf("\nEnter the data:");
		scanf("%d",&new->data);
		new->next = NULL;
		
		head = insert_before_given_node(head,new,temp);
	}
		
	display(head);
	
	printf("\nEnter key for delete:");
	scanf("%d",&key);
	temp = search(head,key);
	if(temp == NULL)
		printf("\nKey not found");
	else
	{
		printf("\nKey is there");
		
		head = delete(head,temp);
	}
		
	display(head);
}





