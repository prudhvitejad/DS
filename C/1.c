#include <stdio.h>
#include <stdlib.h>

/*
	BFS
	
	=> node ni Queue loki add chesukoni and adjacency edge unte dhanini kuda Enqueue chesukuntam.
	=> Dequeue chesi, Dequeue chesina dhaniki adjacency lo undevatini enqueue chesukuntam.
*/

struct node
{
	char data;
	struct edgeNode *next;
	struct node *down;
};


struct edgeNode
{
	char data;
	struct edgeNode *next;
};


struct node* insertVertex(struct node *head,struct node *new)
{
	if(head == NULL)
	{
		head = new;
		return head;
	}
	if(head->down == NULL)
	{
		head->down = new;
		return head;
	}
	
	struct node *temp = head;
	while(temp->down != NULL)
		temp = temp->down;
	
	temp->down = new;
	return head;
}


void insertEdge(struct node *head,struct node *ref1,struct node *ref2,char ch1,char ch2) //
{ 
	struct node *temp = head;
	
	while(temp)
	{
		if( temp->data == ch1 )
		{
			struct edgeNode *temp2 = temp->next;
			struct edgeNode *new = (struct edgeNode*)malloc(sizeof(struct edgeNode));
			new->data = ch2;
			new->next = NULL;
			
			if(temp2 == NULL)
			{
				temp->next = new;
			}
			else if(temp2->next == NULL)
			{
				temp2->next = new;
			}
			else
			{
				struct edgeNode *temp3 = temp->next;
				while(temp3->next != NULL)
					temp3 = temp3->next;
					
				temp3->next = new;
			}
		}
		else if( temp->data == ch2 )
		{
			struct edgeNode *temp2 = temp->next;
			struct edgeNode *new = (struct edgeNode*)malloc(sizeof(struct edgeNode));
			new->data = ch1;
			new->next = NULL;
			
			if(temp2 == NULL)
			{
				temp->next = new;
			}
			else if(temp2->next == NULL)
			{
				temp2->next = new;
			}
			else
			{
				struct edgeNode *temp3 = temp->next;
				while(temp3->next != NULL)
					temp3 = temp3->next;
					
				temp3->next = new;
			}
		}
		
		temp = temp->down;
	}
}


struct node* search(struct node *head,char ch)
{
	struct node *temp = head;
	while(temp)
	{
		if(temp->data == ch)
			return temp;
		temp = temp->down;
	}
	return NULL;
}


struct node* deleteVertex(struct node *head,struct node *ref)
{
	if( head->down == NULL && head == ref )
	{
		free(head);
		return NULL;
	}
	struct node *temp = head;
	
	while(temp->down != ref)
		temp = temp->down;
	
	temp->down = ref->down;
	free(ref);
	return head;
}


void display(struct node *head)
{
	struct node *temp = head;
	
	while(temp)								// Vertical List(Nodes)
	{
		printf("|%c|->",temp->data);
		
		struct edgeNode *temp2 = temp->next;
		while(temp2)						// Inner Horizontal List(Edges of Nodes)
		{
			printf("%c->",temp2->data);
			temp2 = temp2->next;
		}
		printf("\n");
		
		temp = temp->down;
	}
}


int edgeSearch(struct node *head,char ch1,char ch2)
{
	int flag1=0;
	int flag2=0;
	struct node* temp = head;
	
	while(temp)
	{
		if(temp->data == ch1)
			flag1 = 1;
			
		else if(temp->data == ch2)
			flag2 = 1;
			
		temp = temp->down;
	}
	if(flag1 == 1 && flag2 == 1)
		return 1;
	else
		return 0;
}


int main()
{
	struct node *head = NULL;
	struct node *temp1 = NULL;
	struct node *temp2 = NULL;
	struct node *new = NULL;
	int choice1,flag;
	char ch1,ch2;	
	
	do
	{
		printf("\n1.Add Vertex(node)\n2.Add Edge\n3.Remove Vertex(node)\n4.Remove Edge\n5.Display Graph(Normal Display)\nEnter Ur Choice:");
		scanf("%d",&choice1);
		
		switch(choice1)
		{
			case 1:
				new = (struct node*)malloc(sizeof(struct node));
				printf("\nEnter the data:");
				scanf(" %c",&new->data);										// If U don't give space before %c then error occurs
				new->next = NULL;
				new->down = NULL;
				head = insertVertex(head,new);
				break;
			
			case 2:
				printf("\nEnter the 2 Vertices to add edge between them:");
				scanf(" %c %c",&ch1,&ch2);										// If U don't give space before %c then error occurs
				int val = edgeSearch(head,ch1,ch2);
				if(val == 1)
				{
					temp1 = search(head,ch1);
					temp2 = search(head,ch2);
					insertEdge(head,temp1,temp2,ch1,ch2);
					printf("\nVertices U have Entered is in the Graph and edge between %c and %c is added",ch1,ch2);
					break;
				}
				else if(val == 0)
				{
					printf("\nVertices U have Entered is not in the Graph");
					break;
				}
				break;
				
			case 3:
				printf("\nEnter the Vertex U Want to Delete:");
				scanf(" %c",&ch1);												// If U don't give space before %c then error occurs
				temp1 = search(head,ch1);
				if(temp1 == NULL)
				{
					printf("\nVertex U have Entered is not in the Graph");
					break;
				}
				else
				{
					head = deleteVertex(head,temp1);
					printf("\nVertex U have Entered is in the Graph and deleted successfully");
				}
				break;
				
			case 4:
				break;
			
			case 5:
				display(head);
				break;
		}
		
		printf("\nDo U Want To Continue(Press 1):");
		scanf("%d",&flag);
	}while(flag == 1);
}


































