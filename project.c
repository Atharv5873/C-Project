#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int i,j;
int main_exit;
int months[12][2] = {{1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};
struct date{
    int day,month,year;
};

struct{
    int emp_no;
    char name[60];
    int basic;
    int da;
    int hra;
}add,upd,check;

struct month_trans
{
    int emp_no;
    int present;
    int itax;
    int soc;
    struct date dop;
}monthtrans,checktrans;
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
    scanf("%d",main_exit);
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
void edit()
{

}

void monthly_trans()
{
    int choice,flag=0,mon,totdays;
    int i=0,j=0;
    FILE *ptr,*ptr1;
    ptr1=fopen("record.dat","r");
    ptr=fopen("month.dat","a+");

    emp_no:
    system("cls");
    printf("\t\t\t CREATE MONTHLY TRANSACTION");
    printf("\nEnter Month of the Transaction: ");
    scanf("%d",&mon);
    for(i=0;i<12;i++)
    {
        for(j=0;j<2;j++)
        {
            totdays=months[i][j+1];
            break;
        }
    }
    printf("\nEnter the Employee Number");
    scanf("%d",&monthtrans.emp_no);
    while(fscanf(ptr1,"%d %s %d %d %d\n",&add.emp_no,add.name,&add.basic,&add.da,&add.hra)!=EOF)
    {
        if(monthtrans.emp_no==add.emp_no)
        {
            flag=1;
            monthtrans.emp_no=add.emp_no;
            break;
        }
    }
    if(flag==1)
    {
        enterdaysno:
        printf("\nEnter no. of days present: ");
        scanf("%d",&monthtrans.present);
        if(monthtrans.present>totdays)
        {
            printf("\nInvalid Days Present!");
            goto enterdaysno;
        }
        printf("\nEnter Date of Salary(dd/mm/yyyy): ");
        scanf("%d%d%d,&monthtrans.dop.day,&monthtrans.dop.month,&monthtrans.dop.year");
        printf("\nEnter Income Tax: ");
        scanf("%d",&monthtrans.itax);
        printf("\nEnter Society Loan Security: ");
        scanf("%d",&monthtrans.soc);
        fprintf(ptr,"%d %d %d %d %d %d %d\n",monthtrans.emp_no,monthtrans.present,monthtrans.dop.day,monthtrans.dop.month,monthtrans.dop.year,monthtrans.itax,monthtrans.soc);
        fclose(ptr);
        fclose(ptr1);
        printf("\nMonthly Transaction Created Successfully!");
    }
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit");
    scanf("%d",main_exit);
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

void process()
{
    FILE *ptr,*ptr1,*ptr2;
    int lines=0,lines1=0,ch=0;
    ptr1=fopen("month.dat","r");

    while((ch== fgetc(ptr1))!=EOF)
    {
        if(ch=='\n')
        lines++;
    }
    ptr=fopen("record.dat","r");
    while((ch== fgetc(ptr))!=EOF)
    {
        if(ch=='\n')
        lines1++;
    }
    printf("Lines %d %d",lines,lines1);
    int rec[lines1][5];
    char *names[lines1];
    int k,l;
    int mon,yr;
    int g=0;
    float b,c,d;
    int month,year,gross_ded,totdays;
    float gross_earn;
    char nm[60];
    ptr=fopen("record.dat","r");
    ptr1=fopen("month.dat","r");
    ptr2=fopen("process.dat","a+");
    fseek(ptr2,0,SEEK_END);
    printf("\nEnter the year: ");
    scanf("%d",&yr);
    printf("\nEnter the month: ");
    scanf("%d",&mon);
    for(i=0;i<12;i++)
    {
        for(j=0;j<2;i++)
        {
            if(months[i][j]==mon)
            {
                totdays=months[i][j+1];
                break;
            }
        }
    }
    while(fscanf(ptr,"%d %s %d %d %d\n",&add.emp_no,add.name,&add.basic,&add.da,&add.hra)!=EOF)
    {
        rec[g][0]=add.emp_no;
        rec[g][1]=add.basic;
        rec[g][2]=add.da;
        rec[g][3]=add.hra;
        names[g]=(char*)malloc(strlen(add.name)+1);
        strcpy(names[g],add.name);
        g++;
    }
    while(fscanf(ptr1,"%d %d %d %d %d %d %d\n",&monthtrans.emp_no,&monthtrans.present,&monthtrans.dop.day,&monthtrans.dop.month,&monthtrans.dop.year,&monthtrans.itax,&monthtrans.soc)!=EOF)
    {
        if(monthtrans.dop.year==yr && monthtrans.dop.month==mon)
        {
            for(k=0;k<lines1;k++)
            {
                if(rec[k][0]==monthtrans.emp_no)
                {
                    printf("Employee Number : %d",rec[k][0]);
                    b=rec[k][1];
                    c=rec[k][2];
                    d=rec[k][3];
                    gross_earn=monthtrans.present*b/totdays+monthtrans.present*c/totdays+monthtrans.present*d/totdays;
                    gross_ded=monthtrans.itax+monthtrans.soc;
                    fprintf(ptr2,"%d %s %d %d %d %f %d\n",monthtrans.emp_no,names[k],monthtrans.dop.day,monthtrans.dop.month,monthtrans.dop.year,gross_earn,gross_ded);
                    break;
                }
            }
        }
    }
    fclose(ptr);
    fclose(ptr1);
    fclose(ptr2);
    printf("Payroll Processed Sucessfully");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit");
    scanf("%d",main_exit);
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