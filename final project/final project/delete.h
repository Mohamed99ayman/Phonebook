  void deletes(int delete_index,int*indexofarr,person*z,int*q)
    {
        char j;
        printf("\nAre You Sure You Want TO Delete This Contact\n");
        printf("Y/N\n");
       j=getch();
        switch(tolower(j))
        {
            case 'y':
                while(delete_index<*indexofarr)
                {
                    swap(&z[delete_index],&z[delete_index+1]);
                    delete_index++;
                }
                (*indexofarr)--;
                *q=true;


                break;
            case 'N' :
                 *q=false;


                screen();

                break;
            }


        }
