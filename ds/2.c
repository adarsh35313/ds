#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 3

typedef struct
{
    char items[MAXSIZE][25];
    int top;
}STACK;

int isfull(STACK s)
{
    if(s.top==MAXSIZE-1)
        return 1;
    return 0;
}

int isempty(STACK s)
{
    if(s.top==-1)
        return 1;
    return 0;

}

void PUSH(STACK *s,char name[])
{
    strcpy(s->items[++s->top],name);
    printf("\n%s is pushed on to the stack",name);
}


char* POP(STACK *s)
{
    return(s->items[s->top--]);
}

void DISPLAY(STACK s)
{
    int i;
    printf("\nSTACK CONTENTS:\nBOS->");
    for(i=0;i<=s.top;i++)
        printf("%s->",s.items[i]);
     printf("TOS");
}

int main()
{
    STACK s;
    int choice;
    char name[20];
    s.top=-1;
    while(1)
    {
        printf("\n\n1:PUSH\n2:POP\n3:Display\n4:Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: if(isfull(s))
                              printf("\nSTACK OVERFLOW");
                        else
                       {
                              printf("\nEnter the name to be pushed: ");
                              scanf("%s",name);
                              PUSH(&s,name);
                        }
                        break;
            case 2: if(isempty(s))
                             printf("\nSTACK UNDERFLOW");
                        else
                             printf("\n%s is popped from Stack",POP(&s));
                        break;
            case 3: if(isempty(s))
                             printf("\nSTACK EMPTY");
                        else
                             DISPLAY(s);
                        break;
            case 4:exit(0);
            default: printf("\nInvalid choice");
        }
    }
    return 0;
}



