// Program For Array Representation Of Queue
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void main()
{
	int queue[MAX];
	int front=-1,rear=-1;
	int choice,item,i,flag;
	do{
	printf("\nMenu\n______\nSelect Ur Desired Option From The Menu\n1.Insert\n2.Delete\n3.Display\nEnter Ur Option:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			if(rear==MAX-1)
			{
				printf("\nQueue Overflow\n");
				break;
			}
			printf("\nEnter the key to be inserted:");
			scanf("%d",&item);
			if(front == -1 && rear == -1)
				front=0;
			rear++;
			queue[rear]=item;
			break;
		case 2:
			if(front==-1 && rear==-1)
			{
				printf("\nQueue Underflow\n");
				break;
			}
			printf("Deleted element is %d\n",queue[front]);
			if(front==rear)
			{
				front=rear=-1;
				break;
			}
			front++;
			break;
		
		case 3:
			printf("Elements of Queue are:");
			for(i=front;i<=rear;i++)
				printf("%d\t",queue[i]);
			break;

	}
	printf("\nIf U Want To Continue (Enter ----> 1)");
	scanf("%d",&flag);
	}while(flag==1);		
}





