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
	struct node *top = NULL;
	struct node *head = NULL;
	struct node *new = NULL;
	struct node *temp = NULL;
	
	int choice,item,i,flag;
	do{
	printf("\nMenu\n______\nSelect Ur Desired Option From The Menu\n1.Push\n2.Pop\n3.Peer\n4.Display\nEnter Ur Option:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			
			printf("\nEnter the Element to be pushed:");
			new = (struct node *)malloc(sizeof(struct node));
			scanf("%d",&new->data);
			new->link = NULL;
			if(top==NULL)
			{
				top = head = new;
				break;
				
			}
			top->link = new;
			top = new;
			break;
			
		case 2:
			if(top==NULL)
			{
				printf("\nStack Underflow");
				break;
			}
			printf("\nPopped element is %d",top->data);
			temp = head;
			if(top==head)
			{
				free(top);		//free(head) is also same
				head=top=NULL;
				break;
			}
			while(temp->link != top)
				temp = temp->link;
			free(top);
			top = temp;
			top->link = NULL;
			break;
		
		case 3:
			if(top==NULL)
			{
				printf("\nStack Underflow");
				break;
			}
			printf("\nTop most element is %d",top->data);
			break;
			
		case 4:
			printf("\nElements of Stack:");
			temp = head;
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





