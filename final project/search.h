#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  void search (int indexofarr,person*z,char*lastn,int*start,int*end)
    {

        int i=0;
        while(strcasecmp(lastn,z[i].Last_name)&&i<=indexofarr)
        {
            i++;
        }
        if(i>indexofarr)
        {
            printf("NOT FOUND\n");
            *start=i;
        }
        else if(i==indexofarr)
        {
            *start=i;
            *end=i;
        }
        else
        {
            *start=i;
            while(strcasecmp(lastn,z[i].Last_name)==0)
            {
                i++;
            }
            i--;
            *end=i;
        }
    }
    void string(int*i,int*l,char*wanted,char*in)
{
    wanted+=(*l);
    if(in==0)
    {
        *wanted='0';
    }
    else
    {
        while((*in)!='\0')
        {
            (*wanted)=(*in);
            wanted++;in++;(*l)++;
        }

    *wanted=',';
    wanted++;
    (*l)++;
    }

}
int compare(char*cont,char*wanted)
{
    while(*wanted!='\0')
    {
        while(*wanted!=',')
        {
            if(tolower(*wanted)==tolower(*cont))
            {
                wanted++;cont++;
            }
            else
                return false;
        }
        if(*wanted==','&&*cont==',')
        {
            wanted++;cont++;
        }
        while(*wanted==',')
        {
            if(*cont!=',')
            {
            cont++;
            }
            else
            {
                wanted++;
                cont++;
            }
        }
    }
    return true;
}

    void advanced_search(person*z,char*wanted,int indexofarr)
    {
    char cont[max];
    char str[max];
    int k=1;
      for(int j=0;j<=indexofarr;j++)
      {
       int i=0,l=0;
       string(&i,&l,cont,z[j].Last_name);
       string(&i,&l,cont,z[j].First_name);
       string(&i,&l,cont,z[j].address);
       string(&i,&l,cont,z[j].mail);
       string(&i,&l,cont,z[j].Phone_number);
       sprintf(str, "%d", z[j].d.day);
       string(&i,&l,cont,str);
       sprintf(str, "%d", z[j].d.month);
       string(&i,&l,cont,str);
       sprintf(str, "%d", z[j].d.year);
       string(&i,&l,cont,str);
      int r=compare(cont,wanted);
      if(r)
      {
          print(j,j,z,k);
          k++;
      }


      }
      if(k==1)
      {
          printf("Contact Not Found\n");
      }


    }
