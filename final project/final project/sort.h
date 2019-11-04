#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sortall (int indexofarr,person*z)
    {
       int i, j;
       for (i = 0; i < indexofarr-1; i++)
       {
           for (j = 0; j < indexofarr-i-1; j++)
           {
               if(strcasecmp(z[j].Last_name,z[j+1].Last_name)>0)
               {
                swap(&z[j],&z[j+1]);
               }
               else if(strcasecmp(z[j].Last_name,z[j+1].Last_name)==0)
               {
                   if(strcasecmp(z[j].First_name,z[j+1].First_name)>0)
                   {
                    swap(&z[j],&z[j+1]);
                   }
                else if(strcasecmp(z[j].First_name,z[j+1].First_name)==0&&strcasecmp(z[j].Phone_number,z[j+1].Phone_number)>0)
                {
                    swap(&z[j],&z[j+1]);
                }
               }
           }
       }
    }
void Date_sort(int indexofarr,person*z)
{
     int i, j;
       for (i = 0; i < indexofarr-1; i++)
       {
           for (j = 0; j < indexofarr-i-1; j++)
           {
               if(z[j].d.year<z[j+1].d.year)
               {
                swap(&z[j],&z[j+1]);
                continue;
               }
               else if(z[j].d.year==z[j+1].d.year)
               {
                   if(z[j].d.month<z[j+1].d.month)
                   {
                    swap(&z[j],&z[j+1]);
                    continue;
                   }
                else if(z[j].d.month<z[j+1].d.month&&z[j].d.day<z[j+1].d.day)
                {
                    swap(&z[j],&z[j+1]);
                }
               }
           }
       }

}
