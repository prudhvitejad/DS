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
struct node *INSERT_BEFORE_GIVEN_NODE(struct node *,struct node *,struct node *);
struct node *SEARCH(struct node *,int );
struct node *DELETE(struct node *,struct node *);
struct node* mergetwolists(struct node*,struct node*);


int main()
{	
	int ch,ch1,ch2,flag,key;	
	struct node *head1=NULL,*head2=NULL,*new=NULL,*temp=NULL,*ref=NULL;
	do
	{	printf("\n1.List 1\n2.List 2\n3.Concatanation\n4.Merge\nENter Your Choice:-");
		scanf("%d",&ch);
		switch(ch)
		{	
			case 1:
			
				printf("\nMENU\n*******\n");
				printf("1.Insert\n2.Display\n3.Search\n4.Deletion\nEnter Your Choice:-");
				scanf("%d",&ch1);
				
				switch(ch1)
				{	
					case 1:
					
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
							
								head1=INSERT_B4_HEAD(head1,new);
								break;
							
							case 2:
							
								head1=INSERT_AT_END_OF_THE_LIST(head1,new);
								break;
							
							case 3:
								
								printf("\nEnter the reference Key:-");
								scanf("%d",&key);
								temp=SEARCH(head1,key);
								if(temp==NULL)
								{	printf("\nU Entered Invalid Key");
									break;
								}
								INSERT_AFTER_GIVEN_NODE(temp,new);
								break;
								
							case 4:
							
								printf("\nEnter the reference Key:-");
								scanf("%d",&key);
								ref=SEARCH(head1,key);
								if(ref==NULL)
								{	printf("\nU Entered Invalid Key");
									break;
								}
								head1=INSERT_BEFORE_GIVEN_NODE(head1,ref,new);
						}
						break;
						
					case 2:
						
						DISPLAY(head1);
						break;
						
					case 3:
					
						printf("\nEnter the Key to be Searched:-");
						scanf("%d",&key);
						temp=SEARCH(head1,key);
						if(temp!=NULL)
						{	printf("\nKey Found");
						}
						else
							printf("\nKey NOT Found");
						break;
					
					case 4:
						
						printf("\nEnter the Number to be Deleted:-");
						scanf("%d",&key);
						temp=SEARCH(head1,key);
						if(temp==NULL)
						{	printf("\nU Entered Invalid Key");
							break;
						}
						head1=DELETE(head1,temp);
						
						break;
					
				}
				break;
				
			case 2:
			
				printf("\nMENU\n*******\n");
				printf("1.Insert\n2.Display\n3.Search\n4.Deletion\nEnter Your Choice:-");
				scanf("%d",&ch1);
				switch(ch1)
				{	
					case 1:
					
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
							
								head2=INSERT_B4_HEAD(head2,new);
								break;
							
							case 2:
								
								head2=INSERT_AT_END_OF_THE_LIST(head2,new);
								break;
							
							case 3:
							
								printf("\nEnter the reference Key:-");
								scanf("%d",&key);
								temp=SEARCH(head2,key);
								if(temp==NULL)
								{	printf("\nU Entered Invalid Key");
									break;
								}
								INSERT_AFTER_GIVEN_NODE(temp,new);
								break;
							
							case 4:
							
								printf("\nEnter the reference Key:-");
								scanf("%d",&key);
								ref=SEARCH(head2,key);
								if(ref==NULL)
								{	printf("\nU Entered Invalid Key");
									break;
								}
								head2=INSERT_BEFORE_GIVEN_NODE(head2,ref,new);
						}
						break;
						
				case 2:	
				
					DISPLAY(head2);
					break;
					
				case 3:
				
					printf("\nEnter the Key to be Searched:-");
					scanf("%d",&key);
					temp=SEARCH(head2,key);
					if(temp!=NULL)
					{	printf("\nKey Found");
					}
					else
						printf("\nKey NOT Found");
					break;
					
				case 4:
				
					printf("\nEnter the Number to be Deleted:-");
					scanf("%d",&key);
					temp=SEARCH(head2,key);
					if(temp==NULL)
					{	printf("\nU Entered Invalid Key");
						break;
					}
					head2=DELETE(head2,temp);
					
					break;
					
				}
				break;
				
			case 3:	
			
				if(head1==NULL)
				{	head1=head2;
					head2=NULL;
					break;
				}	
				temp=head1;
				while(temp->link!=NULL)
				{	temp=temp->link;
				}
				temp->link=head2;
				head2=NULL;
				break;
				
			case 4:
			{
				struct node *head3;
				head3 = mergetwolists(head1,head2);
				printf("hi\n");
				DISPLAY(head3);
				break;
			}
		}
		
		printf("Do U want to Continue(press 1):-");
		scanf("%d",&flag);
	}while(flag==1);
}

struct node * INSERT_B4_HEAD(struct node *head,struct node *new)
{	new->link=head;
	head=new;
	return head; 
}

struct node *INSERT_AT_END_OF_THE_LIST(struct node *head,struct node *new)
{	
	struct node *temp=head;
	if(head==NULL)
	{	head=new;
		return head;
	}
	while(temp->link!=NULL)
	{	temp=temp->link;
	}
	temp->link=new;
	return head; 
}

void INSERT_AFTER_GIVEN_NODE(struct node *ref,struct node *new)
{	new->link=ref->link;
	ref->link=new;
}

struct node *INSERT_BEFORE_GIVEN_NODE(struct node *head,struct node *ref,struct node *new)
{	if(ref==head)
	{	new->link=head;
		head=new;
		return head;
	}
	struct node *temp=head;
	while(temp->link!=ref)
	{	temp=temp->link;
	}
	new->link=ref;
	temp->link=new;
	return head;
}

struct node *DELETE(struct node *head,struct node *del)
{	
	
	if(head==del)
	{	head=head->link;
		free(del);
		return head;
	}
	struct node *temp=head;
	while(temp->link!=del)
	{	temp=temp->link;
	}
	temp->link=del->link;
	free(del);
	return head;
}

struct node *SEARCH(struct node *head,int key)
{	
	struct node *temp=head;
	while(temp!=NULL)
	{	
		if(temp->data==key)
		{	
			return temp;
		}
		temp=temp->link;
	}
	return NULL;
}

void DISPLAY(struct node *head)
{	
	struct node *temp=head;
	while(temp!=NULL)
	{	
		printf("%d\t",temp->data);
		temp=temp->link;
	}
}

struct node* mergetwolists(struct node *head1,struct node *list2)
{
	struct node *temp1 = head1;
	struct node *temp2 = list2;
	struct node *head3 = NULL;
	struct node *temp3 = head3;
	
	while( (temp1 != NULL) && ( temp2 != NULL ) )
	{
		temp3 = temp1;
		temp1 = temp1->link;
		temp3 = temp3->link;
		temp3  = temp2;
		temp2 = temp2->link;
		temp3 = temp3->link;
	}
	
	if( (temp1 == NULL) && (temp2 != NULL ) )
	{
		while(temp2 != NULL)
		{
			temp3 = temp2;
			temp2 = temp2->link;
			temp3 = temp3->link;
		}
	}
	
	else if( ( temp1!= NULL ) && ( temp2 == NULL ) )
	{
		while( temp1 != NULL )
		{
			temp3 = temp1;
			temp1 = temp1->link;
			temp3 = temp3->link;
		}
	}
	
	return head3;
}



























