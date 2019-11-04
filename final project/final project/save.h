  void save(int indexofarr,person*z)
    {
     int i;
     FILE *fptr;
     fptr=fopen("phonebook.txt","w");
     for(i=0;i<=indexofarr;i++)
     {
       fprintf(fptr,"%s,%s,%d-%d-%d,%s,%s,%s\n",z[i].First_name,z[i].Last_name,z[i].d.day,z[i].d.month,z[i].d.year,z[i].address,z[i].mail,z[i].Phone_number);
     }
     fclose(fptr);
     checksave=true;
    }
