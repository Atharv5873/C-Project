#include<stdio.h>
#include<string.h>

int main()
{
    char pass[10],password[10]="atharv123";
    int i=0;
    printf("\n\n\tEnter the Password to continue: ");
    scanf("%s",pass);
    if(strcmp(pass,password)==0)
    {
        printf("\n\nLOADING");
    }
}