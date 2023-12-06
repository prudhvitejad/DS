#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *pre;
};

struct node *INSERT_B4_HEAD(struct node *, struct node *);
struct node *INSERT_AT_END_OF_THE_LIST(struct node *, struct node *);
void INSERT_AFTER_GIVEN_NODE(struct node *, struct node *);
struct node *INSERT_B4_GIVEN_NODE(struct node *, struct node *, struct node *);
struct node *DELETE(struct node *, struct node *);
struct node *SEARCH(struct node *, int);
void DISPLAY(struct node *);

void main()
{
	int ch1, ch2, flag, key;
	struct node *head=NULL;
	struct node *new=NULL;
	struct node *temp=NULL;
	struct node *ref=NULL;
	do
	{
		printf("\nMENU\n--------\n");
		printf("\n1. Insertion\n2. Display\n3. Search\n4. Deletion\nEnter UR choice:");
		scanf("%d", &ch1);
		switch(ch1)
		{
			case 1:
				new=(struct node *)malloc(sizeof(struct node));
				printf("\nEnter the data to the new node:");
				scanf("%d", &new->data);
				new->next=NULL;
				new->pre=NULL;
				printf("\n1. Before Head\n2.End of The List\n");
				printf("3. After the given Node\n4. B4 the given Node\n");
				printf("Enter UR choice:");
				scanf("%d", &ch2);
				switch(ch2)
				{
					case 1:	
						head=INSERT_B4_HEAD(head, new);
						break;
					case 2:  	
						head=INSERT_AT_END_OF_THE_LIST(head, new);
						break;
					case 3:	
						printf("\nEnter the reference key:");
						scanf("%d", &key);	
						temp=SEARCH(head, key);
						if(temp==NULL)
						{
							printf("\n U entered invalid Key.");
							break;
						}
						INSERT_AFTER_GIVEN_NODE(temp, new);
						break;
					case 4:	
						printf("\nEnter the reference key:");
						scanf("%d", &key);	
						ref=SEARCH(head, key);
						if(ref==NULL)
						{
							printf("\n U entered invalid Key.");
							break;
						}
						head=INSERT_B4_GIVEN_NODE(head,ref,new);
						break;
			}
				break;
			case 2:
				DISPLAY(head);
				break;
			case 3:	
				printf("\nEnter the key to be searched:");
				scanf("%d", &key);	
				temp=SEARCH(head, key);
				if(temp!=NULL)
					printf("\nKey is found.");
				else 	
					printf("\nKey is not found.");
				break;
			case 4:
				printf("\nEnter the key to be deleted:");
				scanf("%d", &key);	
				temp=SEARCH(head, key);
				if(temp==NULL)
				{
				 	printf("\n Key is not found.");
					break;
				}
				head=DELETE(head, temp);
				break;	
		}
		printf("\nDo U want to Continue (press 1):");
		scanf("%d", &flag);
	}while(flag==1);
}

struct node *INSERT_B4_HEAD(struct node *head, struct node *new)
{
	if(head==NULL)
	{
		new->next=new;
		new->pre=new;
		head=new;
		return head;
	}
	struct node *temp=head->pre;
	new->next=head;
	head->pre=new;
	head=new;
	temp->next=head;
	head->pre=temp;
	return head;
}

struct node *INSERT_AT_END_OF_THE_LIST(struct node *head, struct node *new)
{
	if(head==NULL)
	{
		new->next=new;
		new->pre=new;
		head=new;
		return head;
	}
	struct node *temp=head->pre;
	temp->next=new;
	new->next=head;
	head->pre=new;
	new->pre=temp;
	return head;
}

void INSERT_AFTER_GIVEN_NODE(struct node *ref,struct node *new)
{
	new->next=ref->next;
	ref->next->pre=new;
	ref->next=new;
	new->pre=ref;
}

struct node *INSERT_B4_GIVEN_NODE(struct node *head, struct node *ref, struct node *new)
{
	if(ref==head && head->next==head && head->pre==head)
	{
		new->next=head;
		head->pre=new;
		ref->next=new;
		new->pre=head;
		return head;
	}
	struct node *temp=ref->pre;
	temp->next=new;
	new->next=ref;
	ref->pre=new;
	new->pre=temp;
	if(head==ref)
		head=new;
	return head;
}

struct node *DELETE(struct node *head, struct node *del)
{
	if(del==head && head->next==head && head->pre==head)
	{
			free(del);
			return NULL;
	}
	del->pre->next=del->next;
	del->next->pre=del->pre;
	if(del==head)
		head=del->pre->next;
	free(del);
	return head;
}

struct node *SEARCH(struct node *head, int key)
{
	struct node *temp=head->next;
	if(head==NULL)
		return NULL;
	if(head->data==key)
		return head;
	while(temp!=head)
	{
		if(temp->data==key)
			return temp;
		temp=temp->next;
	}
	return NULL;
}

void DISPLAY(struct node *head)
{
	struct node *temp=head;
	if(head!=NULL)
	{
		printf("%d\t", temp->data);
		temp=head->next;
		while(temp!=head)
		{
			printf("%d\t", temp->data);
			temp=temp->next;
		}
	}
}





