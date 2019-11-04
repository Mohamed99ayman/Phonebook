#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 200
#define true 1
#define false 0
#include "structs.h"
#include "add.h"
#include "load.h"
#include "save.h"
#include "swap.h"
#include "sort.h"
#include "search.h"
#include "delete.h"
#include "modify.h"
int checksave;
void screen()
{
    system("cls");
    printf("\t\t WELCOME TO PHONEBOOK\n\n\n");
    printf("To add a contact type A\n\n");
    printf("To save contacts type S\n\n");
    printf("To Search for a contact type F \n\n");
    printf("To print all your contacts type P\n\n");
    printf("To delete a contact type D\n\n");
    printf("To Modify a contact type M\n\n");
    printf("For Advanced Search type k\n\n");
    printf("For Date sort type h\n\n");
    printf("To Quit type Q\n\n");
}


void print(int start,int end,person*z,int l)
{
    int temp=start;
    if(l)
    {
        printf("%d- Last name: %s\nFirst name : %s\nAddress: %s\nE-mail: %s\nphone number: %s\nDate of birth: %d/%d/%d\n\n",l,z[temp].Last_name,z[temp].First_name,z[temp].address,z[temp].mail,z[temp].Phone_number,z[temp].d.day,z[temp].d.month,z[temp].d.year);

    }
    else
    {

        int k=1;
        while(temp!=end+1)
        {
            printf("%d- Last name: %s\nFirst name : %s\nAddress: %s\nE-mail: %s\nphone number: %s\nDate of birth: %d/%d/%d\n\n",k,z[temp].Last_name,z[temp].First_name,z[temp].address,z[temp].mail,z[temp].Phone_number,z[temp].d.day,z[temp].d.month,z[temp].d.year);
            temp++;
            k++;
        }
    }
}
void rev_print(person*z,int indexofarr)
{
    int x=1;
    while(indexofarr>=0)
    {
        printf("%d- Last name: %s\nFirst name : %s\nAddress: %s\nE-mail: %s\nphone number: %s\nDate of birth: %d/%d/%d\n\n",x,z[indexofarr].Last_name,z[indexofarr].First_name,z[indexofarr].address,z[indexofarr].mail,z[indexofarr].Phone_number,z[indexofarr].d.day,z[indexofarr].d.month,z[indexofarr].d.year);
        indexofarr--;
        x++;
    }

}


int main()
{
    system("color 0B");

    char inp;
    checksave=true;
    int start,end;
    person z[max];
    screen();
    int indexofarr=loaddata(z)-1;
    char lastn[max];
    char j;
    char phone[max];
    int i;
    int q=false;
    /*Choosing the function */
    sortall(indexofarr+1,z);
    while(1)
    {
        inp=getch();
        switch(tolower(inp))
        {
        case 'a':
            indexofarr++;
            system("cls");
            add(&indexofarr,z);
            sortall(indexofarr+1,z);
            screen();
            printf("contact added");
            checksave=false;
            inp=NULL;
            break;
        case 's':
            save(indexofarr,z);
            checksave=true;
            screen();
            printf("Saved\n");
            break;
        case 'p':
            sortall(indexofarr+1,z);
            system("cls");
            print(0,indexofarr,z,0);
            printf("press any key to return.");
            getch();
            screen();
            break;


        case 'k':
            system("cls");
            char*wanted=malloc(sizeof(person)/sizeof(char));
            char *k=",";
            char in[max];
            wanted[0]=NULL;
            printf("Last Name : ");
            gets(in);
            strcat(wanted,in);
            strcat(wanted,k);
            printf("First Name : ");
            gets(in);
            strcat(wanted,in);
            strcat(wanted,k);
            printf("Address : ");
            gets(in);
            strcat(wanted,in);
            strcat(wanted,k);
            printf("E-Mail : ");
            gets(in);
            strcat(wanted,in);
            strcat(wanted,k);
            printf("Phone Number : ");
            gets(in);
            strcat(wanted,in);
            strcat(wanted,k);
            printf("Date in this format DD/MM/YY : ");
            gets(in);
            int i=0;
            while(in[i]!=NULL)
            {
             if(in[i]=='/')

                in[i]=',';
             i++;
            }
            strcat(wanted,in);
            strcat(wanted,k);
            if(strcmp(wanted,",,,,,,")==0)
            {
             printf("NO DATA WAS ENTERD\n");
            }
            else
            {
            advanced_search(z,wanted,indexofarr);
            free(wanted);
            }
            printf("press any key to return.");
            getch();
            screen();

            break;
        case 'd':
            printf("Enter Last Name : ");
            scanf("%s",&lastn);
            search(indexofarr,z,lastn,&start,&end);
            if(start<=indexofarr)
            {
                system("cls");
                print(start,end,z,false);
                printf("\n\n");
                if(start==end)
                {
                    deletes(start,&indexofarr,z,&q);
                    screen();
                    if(q==true)
                    {
                        printf("deleted");
                    }
                    else
                    {
                        printf("is not deleted");
                    }
                    checksave=false;
                    break;

                }
                else
                {
                    printf("Write the number of the contact you want to modify\n\n");
                    printf("number : ");
                    while(1)
                    {
                        scanf(" %c",&phone[0]);
                        if(phone[0]-'0'+start-1>=start&&phone[0]-'0'+start-1<=end)
                        {
                            break;
                        }
                        else
                        {
                            printf("INVALID INPUT\n");
                        }
                    }
                    int i=start+phone[0]-'0'-1;
                    deletes(i,&indexofarr,z,&q);
                    screen();
                    if(q==true)
                    {
                        printf("deleted");
                    }
                    else
                    {
                        printf("is not deleted");
                    }
                    checksave=false;





                }


            }
            else
                printf("Contact Not Found");
            break;


        case 'm':
            printf("Enter The last Name\n");
            scanf("%s",lastn);
            search(indexofarr,z,lastn,&start,&end);
            if(start<=indexofarr)
            {
                system("cls");
                print(start,end,z,0);
                printf("\n\n");
                if(start==end)
                {
                    modify(&start,z,&q);
                    screen();
                    if(q)
                    {
                    printf("contact modified");
                    checksave=false;
                    }
                    break;
                }
                else
                {
                    printf("Write the number of the contact you want to modify\n\n");
                    printf("number : ");
                    while(1)
                    {

                        scanf(" %c",&phone[0]);
                        if(phone[0]-'0'+start-1>=start&&phone[0]-'0'+start-1<=end)
                        {
                            break;
                        }
                        else
                        {
                            printf("INVALID INPUT\n");
                        }

                    }
                    int i=start+phone[0]-'0'-1;
                    modify(&i,z,&q);
                    screen();
                    if(q)
                    {
                    printf("contact modified");
                    checksave=false;
                    }
                    break;


                }
            }
            else
                printf("Contact Not Found");

            break;
        case 'f':
            printf("Enter The last Name\n");
            gets(lastn);
            search(indexofarr,z,lastn,&start,&end);
            if(start<=indexofarr)
            {
                system("cls");
                print(start,end,z,0);
            }
            printf("press any key to return.");
            getch();
            screen();
            break;
        case 'h':
            printf("1-To Sort in ascending order\n2-To Sort in descending order\n");
            j=NULL;
            lastn[0]=getch();
            if((lastn[0]-'0')==1)
            {
                system("cls");
                Date_sort(indexofarr,z);
                rev_print(z,indexofarr);
                printf("press any key to return.");
                getch();
                screen();
                sortall(indexofarr,z);
            }
            else if((lastn[0]-'0')==2)
            {
                system("cls");
                Date_sort(indexofarr,z);
                print(0,indexofarr,z,false);
                printf("press any key to return.");
                getch();
                screen();
                sortall(indexofarr,z);

            }
            else
                printf("Invalid Input");
            continue;
            break;
        case 'q':
            if(checksave)
            {
                exit(0);
            }
            else
            {
                printf("Unsaved Data will be lost\nAre you Sure You Want To Quit\nY/N\n");
                j=getch();
                switch(tolower(j))
                {
                case 'y':
                    exit(0);
                    break;
                case 'n':
                    break;
                default:
                    printf("Invalid input");
                }
                screen();
            }
        default:
            printf("Invalid Input\n");

        }
    }
    return 0;
}
