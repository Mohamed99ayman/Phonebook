  #include "checksave.h"
  #include <ctype.h>
#include "isvalid.h"
void add(int*pindexofarr,person*z)
{

    printf("Last Name\n");
    scanf("%s",&z[*pindexofarr].Last_name);
    printf("Enter First Name\n");
    scanf("%s",&z[*pindexofarr].First_name);
    printf("Enter Address\n");
    scanf("\n%[^\n]",&z[*pindexofarr].address);
    printf("Enter E-mail\n");
    char checkmail[50];
    while(1)
    {
        scanf("\n%[^\n]",&checkmail);
        if ( isValid(checkmail)==1 )
        {

            strcpy(z[*pindexofarr].mail,checkmail);
            break;
        }
        else
            printf("\nEmail isn't correct.\n");
        printf("\nEnter Correct E-mail\n");

    }
    printf("Enter Phone Number\n");
    while (1)
    {
        scanf("\n%s",&z[*pindexofarr].Phone_number);
        int k=isint(z[*pindexofarr].Phone_number);
        if(k==0)
        {
            printf("not valid. Please enter a number\n");
            printf("Enter Phone Number\n");
        }
        else
            break;

    }
    printf("Enter Date\nIn this format DD/MM/YY\n");
    char chard[2],charm[2],chary[4];
    while(1)
    {
        scanf("%[^/]/%[^/]/%s",&chard,&charm,&chary);
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

}
