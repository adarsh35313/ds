#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int  info;
    struct node *next;
}NODE;

NODE *insert(NODE *first,int data)
{
    NODE *newnode,*temp,*prev;

    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->info=data;

    if(first==NULL || data<first->info)
    {
        newnode->next=first;
        first=newnode;
    }
    else
    {
        temp=first;
        while(temp!=NULL && data>temp->info)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL || data!=temp->info)
        {
            prev->next=newnode;
            newnode->next=temp;
        }
    }
    return first;
}





void display(NODE *first)
{
    if(first==NULL)
    {
        printf("Empty");
        return;
    }
    printf("Contents:\nBegin->");
    while(first!=NULL)
    {
        printf("%d->",first->info);
        first=first->next;
    }
    printf("End");
}

NODE *merge(NODE *L1,NODE *L2,NODE *L3)
{
    L3=NULL;
    if(L1==NULL && L2==NULL)
    {
        printf("\nEMPTY LISTS");
        return NULL;
    }
    while(L1!=NULL && L2!=NULL)
    {
        if(L1->info<L2->info)
        {
            L3=insert(L3,L1->info);
            L1=L1->next;
        }
         else if(L2->info<L1->info)
        {
            L3=insert(L3,L2->info);
            L2=L2->next;
        }
         else
        {
            L3=insert(L3,L1->info);
            L1=L1->next;
            L2=L2->next;
        }
    }
    while(L1!=NULL)
    {
        L3=insert(L3,L1->info);
        L1=L1->next;
    }

    while(L2!=NULL)
    {
        L3=insert(L3,L2->info);
        L2=L2->next;
    }
    printf("\nLists are merged successfully");
    printf("\nList3 ");
    display(L3);
    return L3;
}


int main()
{
    NODE *L1=NULL,*L2=NULL,*L3=NULL;
    int data,choice;
    while(1)
    {
        printf("\n1:INS_LIST1\n2:INS_LIST2\n3:MERGE\nDISPLAY");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter the data: ");
                    scanf("%d",&data);
                    L1=insert(L1,data);
                    break;

            case 2: printf("\nEnter the data: ");
                    scanf("%d",&data);
                    L2=insert(L2,data);
                    break;

            case 3: L3=merge(L1,L2,L3);
                    break;

            case 4: printf("\nList1 ");
                    display(L1);

                    printf("\nList2 ");
                    display(L2);
                    break;

           case 5: exit(0);
           default: printf("\nInvalid choice");
        }
    }

    return 0;
}
