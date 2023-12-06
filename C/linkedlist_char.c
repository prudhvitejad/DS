#include <stdio.h>
#include <stdlib.h>

struct node 
{
    char data;
    struct node *next;

};

struct node *head=NULL;
typedef struct node NODE;
void insert();
void delete();
void display();


void insert()
{   
    int opt,prev;
    char ch;
    NODE *newnode,*ptr;
    newnode=(NODE *)malloc(sizeof(NODE)); 
    printf("Enter the character:\n");
    scanf("\n");
    scanf("%c",&ch);    // we should leave the space before the %c otherwise  it will gift you an error message;
    ptr=head;  
    newnode->data=ch;
    newnode->next=NULL;
    printf("Enter\n 1.AT END\n 2.AT STARTING\n3.MIDDLE\n");
    scanf("%d",&opt);
    if(head==NULL)
    {
        head=newnode;
        
    }
   else
    {   
       
          if(opt==1)
          {
        
                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                
                }
                
                ptr->next=newnode;
                
          }
          if(opt==2)
          {
                newnode->next=ptr;
                head=newnode;
          
          }
         
         
          if(opt==3)
          {     printf("\nLINKED LIST IS:\n");
                display();
                printf("Enter the value of element to insert after it:");
                scanf("%d",&prev);
                while(ptr->data!=prev)
                {
                    ptr=ptr->next;
                    
                }
                newnode->next=ptr->next;
                ptr->next=newnode;
          
          }
                 
    }

}


void display()
{
   
   
    NODE *ptr;
    ptr=head;
    printf("\n");
    if(ptr==NULL)
        printf("There are no elements in the linked list");
    
    else
    {
        while(ptr!=NULL)
        {
            printf("%c-->",ptr->data);
            ptr=ptr->next;
        
        }


    }
}


void delete()
{
    int ele;
   NODE *ptr;
   NODE *oldptr=NULL;
   ptr=head;
   printf("\nLINKED LIST\n");
   display();
   printf("Enter the element to delete:");
   scanf("%d",&ele);
   while(ptr->data!=ele)
   {
        oldptr=ptr;
        ptr=ptr->next;
   
   }
   
   if(oldptr==NULL)
   {
        head=ptr->next;
        
   }
   else if(ptr->next==NULL)
   {
        oldptr->next=NULL;
   
   }
   else
   {
        oldptr->next=ptr->next;
   
   }
   printf("Succesfully deteted the element %d",ptr->data);
   free(ptr);
  
}




void main()
{

    int opt;
    while(1)
    {
         printf("\n1.INSERT\n 2.DELETE\n 3.DISPLAY\n 4.EXIT\n");
         scanf("%d",&opt);
         switch(opt)
         {
            case 1:
               insert();
               break;
            case 2:
                delete();
                break;
                
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Enter the correct option:");         
         
         }  
                       
    }     
    
}
