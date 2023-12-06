#include<stdio.h>
#define max 5
void main()
{
	int arr[max];
	int rear=-1,front=-1,ch,ch1,i,val;
	do{
		printf("\n1-insertion\n2-deletion\n3.display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				if(front==(rear+1)%max)
					printf("\n-----Circular Queue overflow------\n");
				else
				{
					printf("Enter element to insert");
					scanf("%d",&val);
					if(rear==-1 && front==-1)
					{
						front=rear=0;	
						arr[front]=val;
						break;
					}
					rear=(rear+1)%max;
					
					arr[rear]=val;
				}
				break;
				
			case 2:
				if(front==-1&&rear==-1)
				{
					printf("\n-----Queue Underflow------\n");
				}
				else if(front==rear)
				{
					printf("Deleted element is %d",arr[front]);
					front=rear=-1;
				}
				else
				{
					printf("Deleted element is %d",arr[front]);
					front=(front+1)%max;
				}
				break;
				
			case 3:
				if(front==-1)
				{
					rear=-1;
					printf("\n------No elements-----\n");
				}
				else	
				{
					for(i=front;i<rear;i=(i+1)%max)
					{
						printf("%d\t",arr[i]);
					}
					printf("%d",arr[i]);
				}
				break;
		}
	printf("\nPress 1 to continue");
	scanf("%d",&ch1);
	}while(ch1==1);
}
			
			
			

		
