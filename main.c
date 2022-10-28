#include<stdio.h>
#include<conio.h>

void main()
{
    char ch,ch1,c1,c;
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
        ch=getche();
        switch(ch)
        {
            case '1': system("cls");
                      admin();
                      system("cls");
                      do
                     {
                         printf("\nWHAT DO YOU WANT TO DO?\n\n1.CREATE AN ACCOUNT\n2.DELETE AN ACCOUNT\n\nENTER YOUR CHOICE: ");
                         c=getche();
                         switch(c)
                        {
                            case '1': createacc();
                                      break;
                            case '2': deleteacc();
                                      break;
                        }
                        printf("\nDO YOU WISH TO VISIT LOGIN AS ADMIN PAGE(y/n)?? ");
                        c1=getche();
                     } while(c1=='y');
                      break;
            case '2': system("cls");
                      user();
                      break;
            case '3': exit(0);

        }
        printf("\n\n\nDO YOU WISH TO VISIT HOME PAGE(y/n)?? ");
        ch1=getche();
    }while(ch1=='y');
}