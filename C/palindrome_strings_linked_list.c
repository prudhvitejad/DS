#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node 
{
    char str[40];
    struct node *next;
};

typedef struct node NODE;
NODE *head=NULL;


void insert();
void printf_palindrome_strings();
void display();


void insert()
{
    NODE *newnode=(NODE*)malloc(sizeof(NODE));
    NODE *ptr=head;
    printf("Enter the string in the newnode:");
    scanf("%s",newnode->str);
    newnode->next=NULL;
    char str1[30];
    if(head==NULL)
        head=newnode;
    else
    {
        int n;
        printf("\ninserting at\n1.Beginning\n2.midddle\n3.ending\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                newnode->next=head;
                head=newnode;
                break;
            case 2:
                display();
                printf("\nenter the string after whcih you want to insert:");
                scanf("%s",str1);
                while(strcmp(str1,ptr->str))
                {
                    ptr=ptr->next;
                }
                newnode->next=ptr->next;
                ptr->next=newnode;
                break;
           case 3:
                while(ptr->next!=NULL)
                    ptr=ptr->next;
                ptr->next=newnode;
               
                break;
                
        
        }
    }
    
}

void print_palindrome_strings()
{

    NODE *ptr=head;
    int i,j,l,temp=1;
    if(head==NULL)
        printf("\nLinked list is empty");
    else
    {
        while(ptr!=NULL)
        {
            i=0;
            temp=1;
            j=strlen(ptr->str)-1;
            while(i<j)
            {
                if(ptr->str[i]!=ptr->str[j])
                    temp=0;
                i++;
                j--;
            }
            if(temp==1)
                printf("\n%s ",ptr->str);
            ptr=ptr->next;
               
        }
    }    


}

void display()
{
    NODE *ptr=head;
    if(ptr==NULL)
        printf("\nLinked list is empty");
    else
    {
        while(ptr!=NULL)
        {
            printf("%s-->",ptr->str);
            ptr=ptr->next;
        }
    }
}

void main()
{
    int n;
    while (1)
    {
        printf("\nenter the option below:");
        printf("\n1.insert\n2.print_palindrome_strings\n3.display\n4.exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                insert();
                break;
            case 2:
                print_palindrome_strings();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nPlease enter the correct option");
                break;
        }  
           
    }
    
}

/* 

    SOME EXAMPLES OF PALINDROMES:
        1.MALAYALAM
        2.MADAM
        3.WOW
        4.MOM
        5.REPAPER
        6.AHA
        
*/



