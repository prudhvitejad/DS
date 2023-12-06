#include <stdio.h>
#include <stdlib.h>
#define	MAX 10
int arr[MAX];

int main()
{
	int ch1,val,ch2;
	int top=-1;
	
	do
	{
		printf("\n*****MENU*****\n1.Push\n2.Pop\n3.Peek\n4.Display\nEnter Your Choice:");
		scanf("%d",&ch1);
		
		switch(ch1)
		{
			case 1:
				if(top == MAX-1)
				{
					printf("\nStack Overflow");
					break;
				}
				printf("\nEnter the data:");
				scanf("%d",&val);
				top++;
				arr[top] = val;
				break;
			
			case 2:
				if(top == -1)
				{
					printf("\nStack Underflow");
					break;
				}
				printf("\nPopped out from the stack:%d",arr[top]);
				top--;
				break;
			
			case 3:
				if(top == -1)
				{
					printf("\nStack Underflow");
					break;
				}
				printf("\nTopmost element in the stack:%d",arr[top]);
				break;
			
			case 4:
				if(top == -1)
					break;
				for(int i=0;i<=top;i++)
					printf("%d\t",arr[i]);
		}
		printf("\nDo You want to continue(press 1):");
		scanf("%d",&ch2);
	}while(ch2 == 1);
}





