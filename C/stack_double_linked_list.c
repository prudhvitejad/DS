//Program To Represent Stack In The Form Of Double Linked List 
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *pre;
	struct node *link;
};
void main()
{	
	int choice,flag;
	struct node *head=NULL;
	struct node *new=NULL;
	struct node *top=NULL;
	struct node *temp=NULL;
	do
	{
		printf("\nMENU\n_________\n");
		printf("\n1.Push");		
		printf("\n2.P0P");
		printf("\n3.Display");
		printf("\n4.PEER");
		printf("\n<<<------Enter Ur Desired Option From The Menu------>>>\n");	
		scanf("%d",&choice);		
		switch(choice)
		{
			case 1:
				new=(struct node*)malloc(sizeof(struct node));
				printf("\nPlease Enter The Key Of New Node");
				scanf("%d",&new->data);
				new->next=NULL;
				new->pre=NULL;
				if(top==NULL)
				{
					top=new;
					head=new;
					break;
				}
				top->next=new;
				top=new;
				top->pre=NULL;
				break;
			case 2:
				if(top==NULL)
				{
					printf("\nStack Is UnderFlow");
					break;
				}				
				temp=head;
				if(head==top)//If Only 0ne Element Is Present
				{
					printf("Poped Element Is :%d",top->data);
					free(top);
					top=head=NULL;
					break;				
				}
				while(temp->link!=top)
				{
					temp=temp->link;					
				}
				printf("\nPoped Element Is :%d",top->data);
				top=temp;
				free(temp->link);//(top->link)
				temp->link=NULL;
				break;
			case 3:
				temp=head;
				while(temp!=NULL)
				{
					printf("%d\t",temp->data);
					temp=temp->next;			
				}
				break;
			case 4:
				if(top!=NULL)
				{
					printf("\nTop:%d",top->data);
					break;			
				}
				printf("Stack Is Underflow");
				break;	
	}
	printf("\nIf U Want To Continue Enter (--->1)");
	scanf("%d",&flag);
	}while(flag==1);
}







