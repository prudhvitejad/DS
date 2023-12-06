#include <stdio.h>
#include <string.h>
char stack[100];
int top=-1;

void push(char);
char pop();

int main()
{
	char postfix[100];
	int i = 0;
	int item1,item2;
	printf("\nEnter the valid postfix expression:");
	scanf("%s",postfix);
	printf("\nInput\tStack");
	while( postfix[i] )
	{
		if( postfix[i]>='0' && postfix[i]<='9' )
		{
			push(postfix[i]-'0');
			i++;
		}
		else
		{
			switch( postfix[i] )
			{
				case '+':
					
					item1 = pop();
					item2 = pop();
					push(item2+item1);
					break;
				
				case '-':
					
					item1 = pop();
					item2 = pop();
					push(item2-item1);
					break;
				
				case '*':
					
					item1 = pop();
					item2 = pop();
					push(item2*item1);
					break;
				
				case '/':
					
					item1 = pop();
					item2 = pop();
					push(item2/item1);
					break;
				
				case '%':
					
					item1 = pop();
					item2 = pop();
					push(item2%item1);
					break;
			}
			i++;	
			
		}
		printf("\n");
			printf("%c\t",postfix[i-1]);
			for(int j=0;j<=top;j++)
			{
				printf("%d ",stack[j]);
			}
	}
	printf("\nResult of given Postfix expression:%d\n",stack[top]);
	
}

void push(char item)
{
	top++;
	stack[top] = item;
}

char pop()
{
	char item = stack[top];
	top--;
	return item;
	
}






