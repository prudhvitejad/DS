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
	char temp[100];
	int flag;
	int l;
	do
	{
		printf("\nEnter Any Infix Expression:");
		scanf("%s",temp);
		int i=0,j=0;
		int len = strlen(temp);
		for(l=len-1;l>=0;l--)
		{
			if(temp[l]=='(')
			{
				infix[i]=')';
				i++;
				continue;
			}
			else if(temp[l]==')')
			{
				infix[i]='(';
				i++;
				continue;
			}
			
			infix[i] = temp[l];
			i++;
		}
		infix[i]=')';
		i++;
		infix[i]='\0';
		push('(');
		i=0;
		
		while(infix[i])
		{
			if(infix[i]=='(')
			{
				push('(');  // same as push(infix[i])
				i++;
			}
			else if(infix[i]==')')
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
			else if(('a'<=infix[i] && infix[i]<='z') || ('A'<=infix[i] && infix[i]<='Z') || (0<=infix[i] && infix[i]<=9))
			{
				postfix[j] = infix[i];
				j++;
				i++;
			}
			else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='%')
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
			else
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
		len = strlen(postfix);
		printf("\nResultant Postfix Expression:");
		for(l=len-1;l>=0;l--)
		{
			printf("%c",postfix[l]);
		}
		
		
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




