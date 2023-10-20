#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void menu()
{
    system("cls");
    int choice;
    printf("\n\n\t\tPAYROLL PROCESSING SYSTEM");
    printf("\n\n\t\tWELCOME TO THE MAIN MENU");
    printf("\n\n\t\t1.Create new Employee\n\t\t2.Edit Employee\n\t\t3.Enter Monthly Transaction\n\t\t4.Process Payroll\n\t\t5.Reports\n\t\t6.EXIT");
    printf("\n\n\n\n\n\t\t Enter yout Choice: ");

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