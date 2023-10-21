#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main_exit;

struct{
    int emp_no;
    char name[60];
    int basic;
    int da;
    int hra;
}add,upd,check;

void close()
{
    printf("\n\n\n\nThis C Project is developed by Atharv Sharma!");
}

int check_dup(int empno)
{
    int test=0;
    FILE *ptr;
    ptr=fopen("record.dat","r");
    while(fscanf(ptr,"%d %s %d %d %d\n",&add.emp_no,add.name,&add.basic,&add.da,&add.hra)!=EOF)
    {
        if(empno==add.emp_no)
        {
            test=1;
            break;
        }
        fclose(ptr);
        return test;
    }
}
void new_emp()
{
    int choice,empno,i=0,t,ch=0,x;
    FILE *ptr,*ptr1;
    ptr1=fopen("newrec.dat","a+");
    emp_no:
    system("cls");
    printf("\t\t\t ADD RECORD");
    printf("\nEnter the Employee Number : ");
    scanf("%d",&check.emp_no);
    t=check_dup(check.emp_no);//function not written
    ptr=fopen("record.dat","a+");
    while (fscanf(ptr,"%d%d%d%d\n",&add.emp_no,add.name,&add.basic,&add.da,&add.hra)==1)
    {   
        if(t==1)
        printf("Employee already exists");
    }
    if(i!=1)
    {
        add.emp_no=check.emp_no;
        printf("Enter Name:");
        scanf("%s",add.name);
        printf("\nEnter the  Basic Salary: ");
        scanf("%d",&add.basic);
        printf("\nEnter the  Dearness Allowance: ");
        scanf("%d",&add.da);
        printf("\nEnter the Home Rent Allowance: ");
        scanf("%d",&add.hra);
        fssek(ptr,0,SEEK_END);
        fprintf(ptr,"%d%d%d%d\n",&add.emp_no,add.name,&add.basic,&add.da,&add.hra);
        fseek(ptr,0,SEEK_SET);
        fflush(ptr);
        printf("\nEmployee Creted Successfully!");
    }
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit");
    scanf("%d",main_exit);//not defined rn
    system("cls");
    if(main_exit==1)
    menu();
    else if(main_exit==0)
    close();
    else
    {
        printf("\nInvalid Entry! Try Again.");
        goto add_invalid;
    }
}
    
void menu()
{
    system("cls");
    int choice;
    printf("\n\n\t\tPAYROLL PROCESSING SYSTEM");
    printf("\n\n\t\tWELCOME TO THE MAIN MENU");
    printf("\n\n\t\t1.Create new Employee\n\t\t2.Edit Employee\n\t\t3.Enter Monthly Transaction\n\t\t4.Process Payroll\n\t\t5.Reports\n\t\t6.EXIT");
    printf("\n\n\n\n\n\t\t Enter yout Choice: ");
    scanf("%d",&choice);

    system("cls");
    switch (choice)
    {
    case 1:
        new_emp();
        break;
    case 2:
        edit();
        break;
    case 3:
        monthly_trans();
        break;
    case 4:
        process();
        break;
    case 5:
        view();
        break;
    case 6:
        close();
        break;
    }
    
}

int main()
{
    char pass[10],password[10]="atharv123";
    printf("\n\n\tEnter the Password to continue: ");
    scanf("%s",pass);
    if(strcmp(pass,password)==0)
    {
        printf("\n\nLOADING");
        for(int i=0;i<=7;i++)
        printf(".");
        menu();
    }
}