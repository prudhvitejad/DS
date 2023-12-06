#include <stdio.h>
#include <string.h>
#include <math.h>
char stack[100];
double int_stack[100];
int top=-1;
int int_top=-1;

void push(char);
void int_push(double);
char pop();
double int_pop();
int Priority(char);
char associativity(char);

int main()
{
	char infix[100];
	char postfix[100];
	int flag;
	char temp;
	printf("\nEnter Any Infix Expression:");
	scanf("%s",infix);
	int len = strlen(infix);
	infix[len]=')';
	len++;
	infix[len]='\0';
	push('(');
	int i=0,j=0;
	
	while( infix[i] )
	{
		
		if(infix[i]=='(')
		{
			//postfix[j]='@';
			//j++;
			push('(');  // same as push(infix[i])
			i++;
		}
		else if(infix[i]==')')
		{
			//postfix[j]='@';
			//j++;
			if(infix[i-1]=='(')
			{
				printf("\nInvalid Expression\n");
				return 0;
			}
			while( (top != -1) && (stack[top] != '(') )
			{
				postfix[j]=pop();
				j++;
			}
			if(top==-1)
			{
				printf("\nInvalid Expression\n");
				return 0;
			}
			pop();
			i++;
		}	
		else if( (infix[i]>='0' && infix[i]<='9') )
		{
			postfix[j] = infix[i];
			j++;
			i++;
		}
		else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='%' || infix[i]=='^' || infix[i]=='!' || 		    infix[i]=='s' || infix[i]=='c' || infix[i]=='t' || infix[i]=='l')
		{
			if( infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='%' || infix[i]=='^' || infix[i]=='!' )
			{
				postfix[j] = '@';
				j++;
			}
			if(top != -1 && stack[top]=='(')
			{
				push(infix[i]);
				i++;
			}
			else if(top==-1)
			{
				printf("\nInvalid Expression\n");
				return 0;
			}
			else if( ( stack[top] != '(' ) && ( Priority(infix[i]) > Priority(stack[top]) ) )
			{
				push(infix[i]);
				i++;
			}
		    else if(stack[top]!='(')
			{
				while( ( stack[top] != '(' ) && ( Priority(infix[i]) <= Priority(stack[top]) ) )
				{
					if ( Priority(infix[i]) == Priority(stack[top]) )
					{
						if( associativity(infix[i]) == 'L' )
						{
							postfix[j] = pop();
							j++;
						}
						else if( associativity(infix[i]) == 'R' )
						{
							push(infix[i]);
							i++;
						}
					}
					else if( Priority(infix[i]) < Priority(stack[top]) )
					{
						postfix[j] = pop();
						j++;
					}	
				}
			}	
		}
		else
		{
			printf("\nInvalid Expression\n");
			return 0;
		}
	}
	if(top!=-1)
	{
		printf("\nInvalid Expression\n");
		return 0;
	}
	postfix[j]='\0';
	printf("\nResultant Postfix Expression = %s\n",postfix);
	
	
	double item1,item2;
	i=0;
	
	while( postfix[i] )			// postfix evaluation
	{
		if( postfix[i]>='0' && postfix[i]<='9' )
		{
			int value=0;
			while( postfix[i]>='0' && postfix[i]<='9' )
			{
				value=(value*10)+(postfix[i]-48);		// to get ascii value
				i++;
			}
			int_push(value);
			//printf("%d\n",value);
		}
		else
		{
			switch(postfix[i])
			{
				case '+':
					item1 = int_pop();
					item2 = int_pop();
					int_push(item2+item1);
					break;
					
				case '-':
					
					item1 = int_pop();
					item2 = int_pop();
					int_push(item2-item1);
					break;
					
				case '*':
					
					item1 = int_pop();
					item2 = int_pop();
					int_push(item2*item1);
					break;
					
				case '/':
					
					item1 = int_pop();
					item2 = int_pop();
					int_push(item2/item1);
					break;
					
				case '!':
				{	
					item1 = int_pop();
					int n = item1;
					int temp=1;
					if(n<0)
					{
						printf("\nInvalid\n");
						return 0;
					}	
					while(n>0)
					{
						temp=temp*n;
						n--;
					}
					int_push(temp);
					break;							
				}
					
				case '^':
				{
					double item3 = int_pop();
					double item4 = int_pop();
					//printf("%f\n%f\n",item3,item4);
					int_push(pow(item4,item3));
					break;
				}
				
				case 'l':
				{
					double item3 = int_pop();
					if(item3 == 0)
					{
						printf("\nInvalid\n");
						return 0;
					}
					int_push(log10(item3));
					break;
				}
				
				case 's':
				{
					double item3 = int_pop();
					item3 = item3*(3.142/180);
					int_push(sin(item3));
					break;
				}
				
				case 'c':
				{
					double item3 = int_pop();
					item3 = item3*(3.142/180);
					int_push(cos(item3));
					break;
				}
				
				case 't':
				{
					double item3 = int_pop();
					int n = item3;
					if( ( (n%90) == 0 ) && ( n!= 0 ) )
					{
						printf("\nInvalid\n");
						return 0;
					}
					item3 = item3*(3.142/180);
					int_push(tan(item3));
					break;	
				}
				
				case '@':
					break;
			}
			i++;
		}
		
	}
	printf("%f\n",int_stack[int_top]);	
}

void push(char item)
{
	top++;
	stack[top] = item;
}

void int_push(double item)
{
	int_top++;
	int_stack[int_top] = item;
}

char pop()
{
	char item = stack[top];
	top--;
	return item;
	
}

double int_pop()
{
	double item = int_stack[int_top];
	int_top--;
	return item;
	
}


int Priority(char op)
{
	if(op=='!')
		return 10;
	else if(op=='l')
		return 9;
	else if(op=='^')
		return 8;
	else if(op=='*' || op=='/' || op=='%')
		return 7;
	else if(op=='+' || op=='-')
		return 6;
	else if(op=='s' || op=='c' || op=='t')
		return 5;
}

char associativity(char op)
{
	if(op=='!')
		return 'R';
	else if(op=='l')
		return 'R';
	else if(op=='^')
		return 'R';
	else if(op=='*' || op=='/' || op=='%')
		return 'L';
	else if(op=='+' || op=='-')
		return 'L';
	else if(op=='s' || op=='c' || op=='t')
		return 'R';
}






