#include <stdio.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include "headr.h"

struct user
{
    int accno;
    char name[30];
    char pswrd[30];
    float balance;
} u[10];

struct admin
{
    char username[30];
    char password[30];
} adm, adm1;

static time_t start; // time_t is a datatype for storing system time values.
time_t end;
int r = 10; // rate of interest
double t;
int acc = 101;
int acc1;
char pswrd1[10];
int flag = 0;
int c2;
char c3;
float amt;
int i, j;
static int n = 0;

void admin()
{
    FILE *f = fopen("admin.txt", "r+");
    printf("\n*************************************");
    printf("\n\t\t LOGIN AS ADMIN PAGE");
    printf("\n*************************************");
c:
    printf("\n ENTER USERNAME: ");
    scanf("%s", adm1.username) // s is for string
        fscanf(f, "%s%s", adm.username, adm.password);

    while (flag == 0)
    {
        if (strcmp(adm.username, adm1.username) == 0)
        {
        b:
            printf("ENTER PASSWORD: ");
            scanf("%s", adm1.password);
            if (strcmp(adm.password, adm1.password) == 0)
            {
                printf("\nYou have successfully logged in as Admin..!!");
                flag = 1;
            }
            else
            {
                printf("Wrong Password");
                goto b;
            }
        }
        else
        {
            printf("\n Invalid Username");
            goto c;
        }
    }
}

void user()
{
    printf("\n*************************************");
    printf("\n\t\t LOGIN AS USER ");
    printf("\n*************************************");
l:
    printf("ENTER ACCOUNT NUMBER ");
    scanf("%d", &acc1);
    printf("ENTER PASSWORD: ");
    scanf("%s", &pswrd1);

    for (i = 0; i <= (n - 1); i++)
    {
        if (acc1 == u[i].accno)
        {
            flag = 1;
            break;
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 1)
    {
    a:
        if (strcmp(pswrd1, u[i].pswrd) == 0)
        {
            printf("YOU HAVE SUCCESSFULLY LOGGED IN.....!!");
            system("cls");
            do
            {
                printf("\n*************************************");
                printf("\n\t\tLOGIN AS USER PAGE ");
                printf("\n*************************************");
                printf("\n\n\t1.CHECK DETAILS\n\t2.WITHDRAW MONEY\n\t3.DEPOSIT MONEY\n\t4.EXIT\n\n\tENTER YOUR CHOICE : ");

                scanf("%d", &c2);
                switch (c2)
                {
                case 1:
                    check();
                    break;

                case 2:
                    withdraw();
                    break;

                case 3:
                    deposit();
                    break;

                case 4:
                    exit(0);
                }
                printf("\n\nDO YOU WISH TO VISIT LOGIN AS USER PAGE(y/n)?? ");
                system("cls");

                c3 = getche();

            } while (c3 == 'y');
        }
        else
        {
            printf("ENTERED WRONG PASSWORD");
            printf("\nRE-ENTER THE PASSWORD: ");
            scanf("%s", pswrd1);
            goto a;
        }
    }
    else
    {
        printf("INVALID ACCOUNT NUMBER");
        printf("\nENTER A VALID ACCOUNT NUMBER: ");
        scanf("%d", &acc1);
        goto l;
    }
}

void createacc()
{
    system("cls");
    printf("\n*************************************");
    printf("\n\t\tACCOUNT CREATION ");
    printf("\n*************************************");
    start = time(NULL);
    printf("\nACCOUNT NUMBER IS %d", acc);
    u[n].accno = acc;
    printf("\n\nENTER NAME: ");
    scanf("%s", u[n].name);
    printf("ENTER PASSWORD: ");
    scanf("%s", u[n].pswrd);
    printf("ENTER BALANCE: ");
    scanf("%f", &u[n].balance);
    printf("\nACCOUNT IS CREATED SUCCESSFULLY.....");
    acc++;
    n++;
    system("cls");
}

void check()
{
    end = time(NULL);
    t = difftime(start, end);
    u[i].balance += ((u[i].balance * t * r) / (100 * 365 * 24 * 3600));
    printf("\nYOUR ACCOUNT BALANCE: %f", u[i].balance);
}
void withdraw()
{
    end = time(NULL);
    t = difftime(start, end);
    u[i].balance += (u[i].balance * t * r) / (100 * 365 * 24 * 3600);
    printf("\nYOUR CURRENT BALANCE: %f", u[i].balance);
na:
    printf("\nENTER AMOUNT YOU WANT TO WITHDRAW: ");
    scanf("%f", &amt);
    if (amt > u[i].balance)
    {
        printf("\nLIMIT EXCEED...\n");
        goto na;
    }
    u[i].balance -= amt;
    printf("\nYOUR NEW BALANCE: %f", u[i].balance);
}
void deposit()
{
    end = time(NULL);
    t = difftime(start, end);
    u[i].balance += (u[i].balance * t * r) / (100 * 365 * 24 * 3600);
    printf("\nYOUR CURRENT BALANCE: %f", u[i].balance);
    printf("\nENTER AMOUNT YOU WANT TO DEPOSIT: ");
    scanf("%f", &amt);
    u[i].balance += amt;
    printf("\nYOUR NEW BALANCE: %f", u[i].balance);
}
void deleteacc()
{
    printf("\nENTER ACCOUNT NUMBER: ");
    scanf("%d", &acc1);
    for (i = 0; i <= n - 1; i++)
    {
        if (acc1 == u[i].accno)
        {
            for (j = i; j <= n - 1; j++)
            {
                u[i].accno = u[i + 1].accno;
                u[i].balance = u[i + 1].balance;
                strcpy(u[i].name, u[i + 1].name);
                strcpy(u[i].pswrd, u[i + 1].pswrd);
            }
            printf("\nACCOUNT IS DELETED SUCCESSULLY..!!!");
            break;
        }
        else
            continue;
    }
}

void main()
{
    char ch, ch1, c1, c;
    printf("\t\t\t");
    printf("*****************");
    printf("\n\t\t\t BANK OF MINIONS\n");
    printf("\t\t\t");
    printf("*****************");
    printf("\n\t\t\t     WELCOME\t");
    printf("\n\n\n\n");
    do
    {
        printf("\n*************************************");
        printf("\n\t\tLOGIN PAGE ");
        printf("\n*************************************");
        printf("\n\n\t1. Login as Admin");
        printf("\n\n\t2. Login as User");
        printf("\n\n\t3. Exit the portal");
        printf("\n\n\tEnter your choice : ");
        ch = getche();
        switch (ch)
        {
        case '1':
            system("cls");
            admin();
            system("cls");
            do
            {
                printf("\nWHAT DO YOU WANT TO DO?\n\n1.CREATE AN ACCOUNT\n2.DELETE AN ACCOUNT\n\nENTER YOUR CHOICE: ");
                c = getche();
                switch (c)
                {
                case '1':
                    createacc();
                    break;
                case '2':
                    deleteacc();
                    break;
                }
                printf("\nDO YOU WISH TO VISIT LOGIN AS ADMIN PAGE(y/n)?? ");
                c1 = getche();
            } while (c1 == 'y');
            break;
        case '2':
            system("cls");
            user();
            break;
        case '3':
            exit(0);
        }
        printf("\n\n\nDO YOU WISH TO VISIT HOME PAGE(y/n)?? ");
        ch1 = getche();
    } while (ch1 == 'y');
}