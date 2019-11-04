 int loaddata(person*z)
    {
        FILE *fptr;
        int i=0;
        fptr=fopen("phonebook.txt","r");
        if(fptr!=NULL)
        {
        while(!feof(fptr))
        {
        fscanf(fptr,"%[^,],%[^,],%d-%d-%d,%[^,],%[^,],%s\n",&z[i].First_name,&z[i].Last_name,&z[i].d.day,&z[i].d.month,&z[i].d.year,&z[i].address,&z[i].mail,&z[i].Phone_number);
        i++;
        }
        }
        else
            printf("File doesn't exist");

        fclose(fptr);
        return i;
    }
