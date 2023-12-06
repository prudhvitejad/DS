// Program For Array Representation Of Stack
#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *link;	
};
void main()
{
	struct node *front = NULL;
	struct node *rear = NULL;
	struct node *new = NULL;
	struct node *temp = NULL;
	
	int choice,item,i,flag;
	do{
	printf("\nMenu\n______\nSelect Ur Desired Option From The Menu\n1.Enqueue\n2.Dequeue\n3.Display\nEnter Ur Option:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			
			printf("\nEnter the Element to be Enqueued/Inserted:");
			new = (struct node *)malloc(sizeof(struct node));
			scanf("%d",&new->data);
			new->link = NULL;
			if( front == NULL && rear == NULL )
			{
				front = rear = new;
				break;
			}
			rear->link = new;
			rear = new;
			break;
			
		case 2:
		
			if( front == NULL && rear == NULL)
			{
				printf("\nQueue Underflow");
				break;
			}
			printf("\nDeleted element is %d",front->data);
			if( front == rear )
			{
				free(front);
				front=rear=NULL;
				break;
			}
			temp=front;
			front=front->link;
			free(temp);
			break;
			
		case 3:
			printf("\nElements of Queue:");
			temp = front;
			while(temp!=NULL)
			{
				printf("%d\t",temp->data);
				temp = temp->link;
			}
			break;

	}
	printf("\nIf U Want To Continue (Enter ----> 1)");
	scanf("%d",&flag);
	}while(flag==1);
		
}





