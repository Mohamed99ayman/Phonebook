#include "isvalid.h"
void modify(int*pindexofarr,person *z,int*q)
{
    char c;
    *q=0;
    printf("\nTo modify last name press 1\n");
    printf("To modify first name press 2\n");
    printf("To modify Address press 3\n");
    printf("To modify E-mail press 4\n");
    printf("To modify phone number press 5\n");
    printf("To modify Date press 6\n");
    printf("\nPress 0 If You Want To return\n");



    while(1)
    {


        printf("\n\nwhat do you want to modify? ");

        c=getch();

        switch (c)
        {
        case '1':
            printf("\nEnter New last name: ");
            scanf("%s",&z[*pindexofarr].Last_name);
            *q=1;
            break;

        case '2':
            printf("\nEnter New first name: ");
            scanf("%s",&z[*pindexofarr].First_name);
            *q=1;
            break;
        case '3':
            printf("\nEnter New Address: ");
            scanf("\n%[^\n]",&z[*pindexofarr].address);
            *q=1;
            break;
        case '4':
            printf("\nEnter New E-mail: ");
            char checkmail[100];
            *q=1;
            while(1)
            {
                scanf("%s",&checkmail);
                if ( isValid(checkmail)==1 )
                {

                    strcpy(z[*pindexofarr].mail,checkmail);
                    break;
                }
                else
                    printf("\nEmail isn't correct.\n");
                printf("\nEnter Correct E-mail\n");

            }
*q=1;
            break;
        case '5':

            printf("\nEnter New phone number: ");
            while (1)
            {
                scanf("\n%s",&z[*pindexofarr].Phone_number);
                int k=isint(z[*pindexofarr].Phone_number);
                if(k==0)
                {
                    printf("\nnot valid. Please enter a number\n");
                    printf("\nEnter Phone Number\n");
                }
                else
                    break;

            }
            *q=1;
            break;
        case '6':

            printf("\nEnter Date: ");
            char chard[2],charm[2],chary[4];
            while(1)
            {
                scanf("%[^/]/%[^/]/%[^\n]",&chard,&charm,&chary);
                z[*pindexofarr].d.day=atoi(chard);
                z[*pindexofarr].d.month=atoi(charm);
                z[*pindexofarr].d.year=atoi(chary);

                if(z[*pindexofarr].d.month<=12 && z[*pindexofarr].d.month > 0 && z[*pindexofarr].d.day <= 31 && z[*pindexofarr].d.day > 0 && z[*pindexofarr].d.year > 00 && z[*pindexofarr].d.year <= 2018 )
                {
                    break;
                }
                else
                {
                    printf("\ndate isn't correct.\n");
                    printf("\nEnter Correct date\n");
                }


            }
            *q=1;
            break;
        case '0':
            return;
        default:
            printf("Invalid Input,Please Try Again");



        }
    }

}
