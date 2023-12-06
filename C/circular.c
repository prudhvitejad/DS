#include<stdio.h>
#include<stdlib.h>

struct node
{	int data;
	struct node *link;
};

struct node * INSERT_B4_HEAD(struct node *,struct node *);
void DISPLAY(struct node *);
struct node *INSERT_AT_END_OF_THE_LIST(struct node *,struct node *);
void INSERT_AFTER_GIVEN_NODE(struct node *,struct node *);
struct node *INSERT_B4_GIVEN_NODE(struct node *,struct node *,struct node *);
struct node *SEARCH(struct node *,int );
struct node *DELETE(struct node*,struct node*);

int main()
{	
	int ch1,ch2,flag,key;	
	struct node *head=NULL,*new=NULL,*temp=NULL,*ref=NULL;
	do
	{
		printf("\nMENU\n*******\n");
		printf("1.Insert\n2.Display\n3.Search\n4.Deletion\nEnter Your Choice:-");
		scanf("%d",&ch1);
		switch(ch1)
		{	case 1:
				new=(struct node *)malloc(sizeof(struct node));
				printf("\n Enter the data to the New node:-");
				scanf("%d",&new->data);
				new->link=NULL;
				printf("\n1.Before Head\n2.End of the list\n3.After given Node\n4.Before given Node\n");
				printf("Enter your choice:-");
				scanf("%d",&ch2);
				switch(ch2)
				{	
					case 1:
						head=INSERT_B4_HEAD(head,new);
						break;
					case 2:
						head=INSERT_AT_END_OF_THE_LIST(head,new);
						break;
					case 3:
						printf("\nEnter the reference Key:-");
						scanf("%d",&key);
						temp=SEARCH(head,key);
						if(temp==NULL)
						{	printf("\nU Entered Invalid Key");
							break;
						}
						INSERT_AFTER_GIVEN_NODE(temp,new);
						break; 
					case 4:
						printf("Enter the reference key:");
						scanf("%d",&key);
						temp = SEARCH(head,key);
						if(temp == NULL)
						{
							printf("\nU Entered invalid key:");
							break;
						}
						head = INSERT_B4_GIVEN_NODE(head,temp,new);
						break;
				}
				break;
			case 2:	
				DISPLAY(head);
				break;
			case 3:
				printf("\nEnter the Key to be Searched:-");
				scanf("%d",&key);
				temp=SEARCH(head,key);
				if(temp!=NULL)
				{	printf("\nKey Found");
				}
				else
					printf("\nKey NOT Found");
				break;
			case 4:
				printf("\nEnter the Number to be Deleted:-");
				scanf("%d",&key);
				temp=SEARCH(head,key);
				if(temp==NULL)
				{	printf("\nU Entered Invalid Key");
					break;
				}
				head=DELETE(head,temp);
				
				break;
				
		}
		printf("\nDo U want to Continue(press 1):-");
		scanf("%d",&flag);
	}while(flag==1);
}

struct node * INSERT_B4_HEAD(struct node *head,struct node *new)
{	
	if(head==NULL)
	{	new->link=new;
		head=new;
		return head;
	}
	new->link=head;
	head=new;
	struct node *temp=head->link;
	while(temp->link!=head->link)
		temp=temp->link;
	
	temp->link=head;
	return head;
}

struct node *INSERT_AT_END_OF_THE_LIST(struct node *head,struct node *new)
{	
	if(head==NULL)
	{	new->link=new;
		head=new;
		return head;
	}
	struct node *temp=head;
	while(temp->link!=head)
	{	temp=temp->link;
	}
	new->link=head;
	temp->link=new;
	return head;
}

struct node *INSERT_B4_GIVEN_NODE(struct node *head,struct node *ref,struct node *new)
{	
	if( (head == ref) && (head->link == head) )
	{
		new->link = head;
		head->link = new;
		head = new;
		return head;
	}
	struct node *temp = head;
	while( temp->link != ref )
		temp = temp->link;
	new->link = ref;
	temp->link = new;
	if( ref == head )
		head = new;
	return head;
}

void INSERT_AFTER_GIVEN_NODE(struct node *ref,struct node *new)
{	
	new->link=ref->link;
	ref->link=new;
}

void DISPLAY(struct node *head)
{	
	struct node *temp=head;
	if(head!=NULL)
	{	printf("%d\t",head->data);
		temp=head->link;
		while(temp!=head)
		{	printf("%d\t",temp->data);
			temp=temp->link;
		}
	}
}

struct node *SEARCH(struct node *head,int key)
{	
	
	if(head==NULL)
	{	return NULL;
	}
	if(head->data==key)
	{	return head;
	}
	struct node *temp=head->link;
	while(temp!=head)
	{	
		if(temp->data==key)
		{	
			return temp;
		}
		temp=temp->link;
	}
	return NULL;
}

struct node *DELETE(struct node *head,struct node *del)
{	struct node *temp=head;
	if (temp->link == head && temp==del) 
	{ 
	        head = NULL; 
	        free(temp); 
	        return NULL;
	} 
	if(head==del)
	{	
		while(temp->link!=head)
		{	temp=temp->link;
		}
		head=head->link;
		temp->link=head;
		free(del);
		return head;
	}	
	while(temp->link!=del)
	{	temp=temp->link;
	}
	temp->link=del->link;
	free(del);
	return head;	
	
}







