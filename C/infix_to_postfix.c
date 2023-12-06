#include <stdio.h>
#include <string.h>
char stack[100];
int top=-1;

void push(char);
char pop();
int Priority(char);

int main()
{
	char infix[100];
	char postfix[100];
	int flag;
	do
	{
		printf("\nEnter Any Infix Expression:");
		scanf("%s",infix);
		int len = strlen(infix);
		infix[len]=')';
		len++;
		infix[len]='\0';
		push('(');
	
		int i=0,j=0;	// 'i' for infix and 'j' for postfix
		
		while(infix[i])
		{
			if(infix[i]=='(')										// 1.Logic for Left-parenthesis
			{
				push('(');  // same as push(infix[i])
				i++;
			}
			else if(infix[i]==')')								// 2.Logic for Right-parenthesis
			{
				if(infix[i-1]=='(')
				{
					printf("\nInvalid Expression\n");
					return;
				}
				while( (top != -1) && (stack[top] != '(') )
				{
					postfix[j]=pop();
					j++;
				}
				if(top==-1)
				{
					printf("\nInvalid Expression\n");
					return;
				}
				pop();
				i++;
			}
			else if(('a'<=infix[i] && infix[i]<='z') || ('A'<=infix[i] && infix[i]<='Z') || (0<=infix[i] && infix[i]<=9))	// 3.Logic for operands
			{
				postfix[j] = infix[i];
				j++;
				i++;
			}
			else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='%') // 4.Logic for operators
			{
				if(top != -1 && stack[top]=='(')
				{
					push(infix[i]);
					i++;
				}
				else if(top==-1)
				{
					printf("\nInvalid Expression\n");
					return;
				}
				else if(stack[top]!='(')
				{
					while( ( stack[top] != '(' ) && ( Priority(stack[top])>=Priority(infix[i]) ) )
					{
						postfix[j] = pop();
						j++;
					}
					push(infix[i]);
					i++;
				}
			}
			else											// 5
			{
				printf("\nInvalid Expression\n");
				return;
			}

		}
		if(top!=-1)
		{
			printf("\nInvalid Expression\n");
			return;
		}
		postfix[j]='\0';
		printf("\nResultant Postfix Expression = %s\n",postfix);
		
	printf("\nDo U Want to Continue(press 1):");
	scanf("%d",&flag);
		
	}while(flag==1);
	
	
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

int Priority(char op)
{
	if(op=='*' || op=='/' || op=='%')
		return 1;
	else if(op=='+' || op=='-')
		return 0;
}





