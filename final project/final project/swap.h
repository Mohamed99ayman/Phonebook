 void swap (person*one,person*two)
    {

            char temp[max*2];
            strcpy(temp,one->First_name);
            strcpy(one->First_name,two->First_name);
            strcpy(two->First_name,temp);

            strcpy(temp,one->Last_name);
            strcpy(one->Last_name,two->Last_name);
            strcpy(two->Last_name,temp);

            strcpy(temp,one->address);
            strcpy(one->address,two->address);
            strcpy(two->address,temp);

            strcpy(temp,one->mail);
            strcpy(one->mail,two->mail);
            strcpy(two->mail,temp);

            strcpy(temp,one->Phone_number);
            strcpy(one->Phone_number,two->Phone_number);
            strcpy(two->Phone_number,temp);


            int tempx;
            tempx=one->d.day;
            one->d.day=two->d.day;
            two->d.day=tempx;

            tempx=one->d.month;
            one->d.month=two->d.month;
            two->d.month=tempx;

            tempx=one->d.year;
            one->d.year=two->d.year;
            two->d.year=tempx;

    }
