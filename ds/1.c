#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct EMPLOYEE
{
    int empid;
    char name[20];
    char dept[20];
    int salary;
    int age;
}e;

 void read_record(FILE *fp)
 {
	 printf("\nEnter the Employee ID...\n");
	 scanf("%d",&e.empid);
	 printf("\nEnter the name...\n");
	 scanf("%s",e.name);
	 printf("\nEnter the department...\n");
	 scanf("%s",e.dept);
	 printf("\nEnter the salary...\n");
	 scanf("%d",&e.salary);
	 printf("\nEnter the age...\n");
	 scanf("%d",&e.age);
     fprintf(fp,"%d\t%s\t%s\t%d\t%d\n",e.empid,e.name,e.dept,e.salary,e.age);
     printf("\nRecord saved successfully");
}
 void print_record(FILE *fp)
 {
     printf("ID\t\tNAME\t\tDEPT\t\tSalary\t\tAGE\n");
     printf("----------------------------------------------------\n");

 while((fscanf(fp,"%d%s%s%d%d",&e.empid,e.name,e.dept,&e.salary,&e.age))!=EOF)
 printf("%d\t\t%s\t\t%s\t\t%d\t\t%d\n",e.empid,e.name,e.dept,e.salary,e.age);

}

 void search_record(FILE *fp)
 {
	int flag=0;
	char dept[20];

	printf("\nEnter the dept to search: ");
	scanf("%s",dept);

while((fscanf(fp,"%d%s%s%d%d",&e.empid,e.name,e.dept,&e.salary,&e.age))!=EOF)
{
	if(strcmp(e.dept,dept)==0)
	{
	   if(flag==0)
	    {
	       printf("\nSEARCH SUCCESSFUL !!!");
            printf("\nID\t\tNAME\t\tDEPT\t\tSalary\t\tAGE\n");
            printf("--------------------------------------------\n");
            flag=1;
	    }
 printf("%d\t\t%s\t\t%s\t\t%d\t\t%d\n",e.empid,e.name,e.dept,e.salary,e.age);
     }
 }
 if(flag==0)
      printf("\nFAILURE,NO SUCH RECORD FOUND !!!");
 }


int main()
{
    FILE *fp;
    int choice;

    while(1)
    {

      printf("\n\n1:Add_Record 2:Search_Record 3:Display\n4:Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&choice);


     switch(choice)
    {
          case 1:   fp=fopen("empfile","a");
	              if(fp==NULL)
	                   printf("\nError in opening file");
	              else
	              {
                              read_record(fp);
	                    fclose(fp);
	              }
                        break;

          case 2:   fp=fopen("empfile","r");
	              if(fp==NULL)
	                  printf("\nError in opening file");
	              else
	              {
                             search_record(fp);
	                   fclose(fp);
	              }
	              break;

          case 3:   fp=fopen("empfile","r");
	              if(fp==NULL)
	                   printf("\nNO RECORDS TO DISPLAY !!!");
	               else
	               {
	                  print_record(fp);
	                  fclose(fp);
	               }
                         break;

          case 4: exit(0);

          default: printf("\nInvalid choice !!!");
       }
    }
   return 0;
 }
